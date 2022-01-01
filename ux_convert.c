/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ux_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 07:51:13 by euyi              #+#    #+#             */
/*   Updated: 2021/12/15 09:39:13 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	lintlen(size_t n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		if (n >= 10)
			n /= 10;
		else
			break ;
	}
	return (len);
}

static char	*litoanm(size_t n)
{
	int		j;
	char	arr[11];
	char	*ptr;

	j = lintlen(n);
	if (n == 0)
		return ("0");
	ptr = arr;
	ptr[j] = '\0';
	while (n > 0)
	{
		ptr[(j - 1)] = '0' + (n % 10);
		if (n >= 10)
			n /= 10;
		else
			break ;
		j--;
	}
	return (ptr);
}

static void	litoa(size_t n)
{
	char	*ptr;

	ptr = litoanm(n);
	while (*ptr != '\0')
	{
		write(1, &(*ptr), 1);
		ptr++;
	}
}

void	ux_convert(char **ptr2d, long int n)
{
	if (*(*ptr2d + 1) == 'u' && n >= 0)
		litoa((size_t)n);
	else if (*(*ptr2d + 1) == 'u' && n < 0)
		litoa((size_t)n + 4294967296);
	else if (*(*ptr2d + 1) == 'x')
		ux_x_convert(n);
	else if (*(*ptr2d + 1) == 'X')
		ux_xb_convert(n);
	*ptr2d += 2;
}
