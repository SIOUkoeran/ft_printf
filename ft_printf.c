/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:59:08 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/14 14:49:33 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *args, ...)
{
	va_list ap;
	int n;
	
	n = 1;
	va_start(ap, args);
	while (1)
	{
		if (*args == 0)
			return (0);
		else if (*args == '%')
		{
			args++;
			n = ft_check_type(*args, ap);
		}
		if (*args != '%')
			write(1, args, 1);
		args++;
	}
}

int ft_check_type(char c, va_list ap)
{
	switch (c)
	{
		case 'd':
			int n = va_arg(ap, int);
			ft_putnbr(n);
		case 'f':
			float n = (float) va_arg(ap, double);
			ft_putnbr(n);
		case 'x':
			unsigned int n = va_arg(ap, unsigned int);
			ft_putnbr(n);
		case 's':
			char *s = va_arg(ap, char *);
			ft_putstr(s);
		case 'c':
			char c = va_arg(ap, char);
			ft_putchar(c);
		case 'p':
			unsigned int n = va_arg(ap, unsigned int);
			ft_putnbr(n);
		case 'X':
			ft_putnbr();
		case 'i':
			int n = va_arg(ap, int);
			ft_putnbr(n);
		case 'u':
			int n = va_arg(ap, int);
			if (n < 0)
				n *= -1;
			ft_putnbr(n);
		case '%':
			ft_putchar('%');
		default:
			return (0);	
	}
	return (1);
}