/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:52:21 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/19 16:26:25 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr_fd(int n, int cnt)
{
	if (n < 0)
	{
		write(1, "-", 1);
		if (n == -2147483648)
			write(1, "2147483648", 10);
		else
		{
			n *= -1;
			ft_putnbr_fd(n, cnt + 1);
		}
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, cnt + 1);
		}
		n = 48 + n % 10;
		write(fd, &n, 1);
		cnt++;
	}
	return (cnt);
}

int	ft_puthex(unsigned int n, char c)
{
	
}

int	ft_putptr(size_t n)
{
	
}

int	ft_putstr(char *s)
{
	int length;
	
	length = ft_strlen(s);
	write(1, s, length);
	return (length);
}