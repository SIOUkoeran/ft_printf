/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:04:33 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/21 16:12:46 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char *s)
{
	int length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int	ft_puthex_lower(unsigned int n)
{
	size_t	length;
	char *s;

	length = ft_intlen(n);
	s = (char *)malloc(sizeof(char) * length);
	if (s == NULL)
		return (0);
	while (n > 0)
	{
		s[length - 1] = "0123456789abcdef"[n % 16];
		length--;
		n /= 16;
	}
	write(1, s, length);
	free(s);
	return (length);
}

int	ft_puthex_upper(unsigned int n)
{
	size_t	length;
	char 	*s;

	length = ft_intlen(n);
	s = (char *)malloc(sizeof(char) * length);
	if (s == NULL)
		return (0);
	while (n > 0)
	{
		s[length - 1] = "0123456789ABCDEF"[n % 16];
		length--;
		n /= 16;
	}
	write(1, s, length);
	free(s);
	return (length);
}

int ft_puthex_u(unsigned int n)
{
	size_t	length;
	char *s;

	length = ft_intlen(n);
	s = (char *)malloc(sizeof(char) * length);
	if (s == NULL)
		return (0);
	while (n > 0)
	{
		s[length - 1] = n % 10 + '0';
		n /= 10;
		length--;
	}
	write(1, s, length);
	free(s);
	return (length);
}

size_t	ft_intlen(unsigned int n)
{
	size_t	length;

	length = 0;
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}
