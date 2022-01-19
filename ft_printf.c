/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:59:08 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/19 16:26:58 by mkim3            ###   ########.fr       */
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
			ft_check_type(*args, ap);
		}
		if (*args != '%')
			write(1, args, 1);
		args++;
	}
}

void ft_check_type(char c, va_list ap)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int), 0));
	else if (c == 'u' || c == 'x' || c == 'X')
		return (ft_puthex((unsigned int)va_arg(ap, int), c));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, char)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr((size_t)av_arg(ap, void *)));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (0);
}