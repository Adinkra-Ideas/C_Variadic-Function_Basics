/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux_x_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 05:12:19 by euyi              #+#    #+#             */
/*   Updated: 2021/12/15 09:35:30 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	hexx_con(int n)
{
	char	c;

	if (n < 10)
		c = n + '0';
	else if (n == 10)
		c = 'a';
	else if (n == 11)
		c = 'b';
	else if (n == 12)
		c = 'c';
	else if (n == 13)
		c = 'd';
	else if (n == 14)
		c = 'e';
	else if (n == 15)
		c = 'f';
	return (c);
}

static char	*itorhx(size_t addr)
{
	char	arr[25];
	char	*ptr;
	int		i;

	ptr = arr;
	i = 0;
	while (addr != 0)
	{
		arr[i] = hexx_con(addr % 16);
		if (addr >= 16)
			addr /= 16;
		else
			break ;
		i++;
	}
	arr[i + 1] = 0;
	return (ptr);
}

void	ux_x_convert(size_t n)
{
	char	*ptr;
	char	arr[25];
	int		i;
	int		j;

	ptr = itorhx(n);
	i = ft_strlen(ptr);
	j = i;
	arr[i] = '\0';
	while (i > 0)
	{
		arr[i - 1] = *ptr;
		ptr++;
		i--;
	}
	ptr = arr;
	write(1, ptr, j);
}
