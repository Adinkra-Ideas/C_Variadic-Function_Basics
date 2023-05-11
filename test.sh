#!/bin/sh
cc -Wall -Werror -Wextra -pedantic -g3 -fsanitize=address -D PRINTER=printg printg.c -o printer
echo "======================================================================="
echo "Using printg();"
./printer
./printer > printg
echo "-----------------------------------------------------------------------"

cc -Wall -Werror -Wextra -pedantic -g3 -fsanitize=address -D PRINTER=printf printg.c -o printer
echo "Using printf();"
./printer
./printer > printf
echo "======================================================================="

if [ ! $(diff -U 3 printg printf) ]
then
  echo "Test Successful :)"
fi

rm printer printg printf
