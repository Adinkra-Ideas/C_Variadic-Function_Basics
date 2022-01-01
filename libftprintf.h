/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 05:17:01 by euyi              #+#    #+#             */
/*   Updated: 2021/12/15 09:40:31 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *ptr, ...);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	idc_convert(char **ptr2d, int n);
void	p_convert(char **ptr2d, void *vptr);
void	s_convert(char **ptr2d, char *ptr);
void	ux_convert(char **ptr2d, long int n);
void	ux_x_convert(size_t n);
void	ux_xb_convert(size_t n);

#endif
