/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:29:08 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/27 18:58:19 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define	FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_puthex(unsigned int n, char c);
int		ft_putptr(ssize_t n);
int		ft_putstr(char *s);
int		ft_strlen(char *s);
int		ft_puthex_lower(unsigned long n);
int		ft_puthex_upper(unsigned long n);
int		ft_puthex_u(unsigned long n);
size_t	ft_unsignedlen(unsigned long n, int base);
size_t	ft_intlen(ssize_t n, int base);
int		ft_printf(char const *args, ...);
int		ft_check_type(char c, va_list ap);
#endif