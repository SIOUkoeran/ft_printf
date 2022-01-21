/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:29:08 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/21 16:28:53 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_puthex(unsigned int n, char c);
int		ft_putptr(size_t n);
int		ft_putstr(char *s);
int 	ft_strlen(char *s);
int		ft_puthex_lower(unsigned int n);
int		ft_puthex_upper(unsigned int n);
int 	ft_puthex_u(unsigned int n);
size_t	ft_intlen(unsigned int n);
int 	ft_printf(char const *args, ...);
int		ft_check_type(char c, va_list ap);
#endif