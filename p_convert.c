/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 08:42:54 by euyi              #+#    #+#             */
/*   Updated: 2021/12/15 09:32:04 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	hex_con(int n)
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

static char	*reverse_addr(void *vptr)
{
	char	arr[25];
	char	*ptr;
	size_t	addr;
	int		i;

	ptr = arr;
	addr = (size_t) vptr;
	i = 0;
	while (addr != 0)
	{
		arr[i] = hex_con(addr % 16);
		if (addr >= 16)
			addr /= 16;
		else
			break ;
		i++;
	}
	arr[i + 1] = 0;
	return (ptr);
}

void	p_convert(char **ptr2d, void *vptr)
{
	char	*ptr;
	char	arr[25];
	int		i;
	int		j;

	ptr = reverse_addr(vptr);
	arr[0] = '0';
	arr[1] = 'x';
	i = ft_strlen(ptr) + 1;
	j = i + 1;
	arr[j] = '\0';
	while (i > 1)
	{
		arr[i] = *ptr;
		ptr++;
		i--;
	}
	ptr = arr;
	write(1, ptr, j);
	*ptr2d += 2;
}
