/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 05:15:30 by euyi              #+#    #+#             */
/*   Updated: 2022/01/01 23:46:47 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

	#include <stdio.h>
	int main(void)
	{
		int n = -500;
		
		ft_printf("Ft_printf Test Result = |%X| - ok\n", n);
		printf("Printf Test Result = |%X| - ok\n", n);
	}


static int	check_uxx(int n)
{
	if ((n == 'u') || (n == 'x') || (n == 'X'))
		return (0);
	return (1);
}

static int	check_idc(int n)
{
	if ((n == 'i') || (n == 'd') || (n == 'c'))
		return (0);
	return (1);
}

int	ft_printf(const char *ptr, ...)
{
	va_list	args;

	va_start(args, ptr);
	while (*ptr)
	{
		if (*ptr == '%' && *(ptr + 1) == '%' && write(1, &(*(ptr + 1)), 1))
			ptr += 2;
		else if (*ptr == '%' && check_uxx(*(ptr + 1)) == 0)
			ux_convert((char **)&ptr, va_arg(args, long int));
		else if (*ptr == '%' && check_idc(*(ptr + 1)) == 0)
			idc_convert((char **)&ptr, va_arg(args, int));
		else if (*ptr == '%' && *(ptr + 1) == 'p')
			p_convert((char **)&ptr, va_arg(args, void *));
		else if (*ptr == '%' && *(ptr + 1) == 's')
			s_convert((char **)&ptr, va_arg(args, char *));
		else if (*ptr == '%' && *(ptr + 1) == 0)
			return (0);
		else if (*ptr == '%')
			ptr += 2;
		else if (*ptr != 0 && write(1, &(*ptr), 1))
			ptr++;
	}
	va_end(args);
	return (0);
}
