/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:07:52 by euyi              #+#    #+#             */
/*   Updated: 2021/12/15 09:27:39 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n /= -1;
		len++;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_itoanm(int n)
{
	int		j;
	char	arr[12];
	char	*ptr;

	j = ft_intlen(n);
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	ptr = arr;
	if (n < 0)
	{
		ptr[0] = '-';
		n /= -1;
	}
	ptr[j] = '\0';
	while (n > 0)
	{
		ptr[(j - 1)] = '0' + (n % 10);
		n /= 10;
		j--;
	}
	return (ptr);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	*ptr;

	ptr = ft_itoanm(n);
	while (*ptr != '\0')
	{
		write(fd, &(*ptr), 1);
		ptr++;
	}
}
