/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:52:21 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/27 18:57:12 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
			write(1, "2147483648", 10);
		else
		{
			n *= -1;
			ft_putnbr(n);
		}
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		n = 48 + n % 10;
		write(1, &n, 1);
	}
}

int	ft_puthex(unsigned int n, char c)
{
	if (c == 'u')
		return (ft_puthex_u(n));
	else if (c == 'x')
		return (ft_puthex_lower(n));
	else if (c == 'X')
		return (ft_puthex_upper(n));
	else
		return (0);
}

int	ft_putptr(ssize_t n)
{
	int	cnt;
	int	length;

	cnt = 0;
	length = ft_intlen(n, 16);
	write(1, "0x", 2);
	cnt += 2;
	if (n == 0)
	{
		write(1, "0", 1);
		return (++cnt);
	}
	cnt += ft_puthex_lower(n);
	return (cnt);
}

int	ft_putstr(char *s)
{
	int	length;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	length = ft_strlen(s);
	write(1, s, length);
	return (length);
}
