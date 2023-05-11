# ifndef _PRINTER
# define _PRINTER printg
#endif

#include <unistd.h>
#include <stdarg.h>
# include <stdio.h>

int g_count = 0;

// function for managing s conversions.
void s_convert(char *tmp)
{
	int i = 0;

	if ( ! tmp && write(1, "(null)", 6) ) {
		g_count += 6;
		return ;
	}

	while ( tmp && tmp[i] ) {
		write (1, &tmp[i], 1);
		g_count++;
		i++;
	}
}

// function for managing x, d conversions.
void xd_convert(long number, int base)
{
	char *list = "0123456789abcdef\0";

	if ( base == 10 && number < 0 && write(1, "-", 1) && ++g_count )
		number = -number;
	else if ( base == 16 && number < 0 )
		number += 4294967296;

	if ( number >= base )
		xd_convert(number / base, base);

	write(1, &list[number % base], 1);

	g_count++;
}

// **********************************************
// Primary function. Supports the following 	*
// Conversion specifiers: s, d, x				*
// **********************************************
int printg( const char *ptr, ... ) {
	va_list args;

	va_start(args, ptr);

	while ( *ptr ) {
		if ( *ptr && *ptr == '%' && ptr++ ) {
			if ( *ptr && *ptr == 's' && ptr++ )
				s_convert(va_arg(args, char *));
			else if ( *ptr && *ptr == 'd' && ptr++ )
				xd_convert(va_arg(args, int), 10);
			else if ( *ptr && *ptr == 'x' && ptr++ )
				xd_convert(va_arg(args, int), 16);
			else if ( *ptr && *ptr == '%' && ptr++ )
				g_count += write (1, "%", 1);
		}
		else if ( *ptr && *ptr != '%' && write(1, &(*ptr), 1) && ptr++ )
			g_count++;
	}

	va_end(args);

	return (g_count);
}

int main() {
	_PRINTER("%s %d is %x\n", "Hexadecimal for", -23, -23);
	return (0);
}
