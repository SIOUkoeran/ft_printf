/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:59:08 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/21 16:31:29 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(char const *args, ...)
{
	va_list ap;
	int total;
	
	total = 0;
	va_start(ap, args);
	while (1)
	{
		if (*args == '\0')
			break;
		if (*args == '%')
		{
			args++;
			total += ft_check_type(*args, ap);
		}
		else if (*args != '%')
			write(1, args, 1);
		args++;
		total++;
	}
	return (total - 1);
}

int ft_check_type(char c, va_list ap)
{
	int	num;

	num = 0;
	if (c == 'd' || c == 'i')
	{	
		num = va_arg(ap, int);
		ft_putnbr(num);
		return ((int) ft_intlen((unsigned int) num));
	}
	else if (c == 'u' || c == 'x' || c == 'X')
		return (ft_puthex((unsigned int)va_arg(ap, int), c));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr((size_t)va_arg(ap, void *)));
	else if (c == '%')
		return (write(1, &c, 1));
	else
		return (0);
}