/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:29:08 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/19 16:23:35 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(int n, int cnt);
int	ft_puthex(unsigned int n, char c);
int	ft_putptr(size_t n);
int	ft_putstr(char *s);
int ft_strlen(char *s);

#endif