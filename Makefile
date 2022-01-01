# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 22:09:40 by euyi              #+#    #+#              #
#    Updated: 2021/12/17 06:02:50 by euyi             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c	ft_putnbr_fd.c	ft_strlen.c	idc_convert.c \
		p_convert.c	s_convert.c	ux_convert.c	ux_x_convert.c \
		ux_xb_convert.c
				

OBJ = $(subst .c,.o,$(SRC))

BSRC=

BOBJ = $(subst .c,.o,$(BSRC))

CC ?= cc

CFLAGS = -Wall	-Werror	-Wextra

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

bonus: $(BOBJ)
	ar rc $(NAME) $(BOBJ)

clean:
	/bin/rm -f $(OBJ) $(BOBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all	clean	fclean	re bonus
