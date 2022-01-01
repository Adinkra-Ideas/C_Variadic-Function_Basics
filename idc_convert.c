/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idc_convert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:57:21 by euyi              #+#    #+#             */
/*   Updated: 2021/12/15 09:29:50 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	idc_convert(char **ptr2d, int n)
{
	if (*(*ptr2d + 1) == 'c')
		write(1, &n, 1);
	else if (*(*ptr2d + 1) == 'i')
		ft_putnbr_fd(n, 1);
	else if (*(*ptr2d + 1) == 'd')
		ft_putnbr_fd(n, 1);
	*ptr2d += 2;
}
