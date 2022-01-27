/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_sub_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:04:33 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/27 18:45:26 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_strlen(char *s)
{
	int	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}

int	ft_puthex_lower(unsigned long n)
{
	size_t	length;
	char	*s;
	size_t	s_len;

	length = ft_unsignedlen(n, 16);
	s_len = length;
	s = (char *)malloc(sizeof(char) * (length + 1));
	if (s == NULL)
		return (0);
	s[length] = '\0';
	while (n >= 16)
	{
		s[length - 1] = "0123456789abcdef"[n % 16];
		length--;
		n /= 16;
	}
	s[length - 1] = "0123456789abcdef"[n % 16];
	write(1, s, s_len);
	free(s);
	return (s_len);
}

int	ft_puthex_upper(unsigned long n)
{
	size_t	length;
	char	*s;
	size_t	s_len;

	length = ft_unsignedlen(n, 16);
	s_len = length;
	s = (char *)malloc(sizeof(char) * (length + 1));
	if (s == NULL)
		return (0);
	s[length] = '\0';
	while (n >= 16)
	{
		s[length - 1] = "0123456789ABCDEF"[n % 16];
		length--;
		n /= 16;
	}
	s[length - 1] = "0123456789ABCDEF"[n % 16];
	write(1, s, s_len);
	free(s);
	return (s_len);
}

int	ft_puthex_u(unsigned long n)
{
	size_t	length;
	char	*s;
	size_t	s_len;

	length = ft_intlen(n, 10);
	s_len = length;
	s = (char *)malloc(sizeof(char) * (length + 1));
	if (s == NULL)
		return (0);
	s[length] = '\0';
	while (n >= 10)
	{
		s[length - 1] = n % 10 + '0';
		n /= 10;
		length--;
	}
	s[length - 1] = n % 10 + '0';
	write(1, s, s_len);
	free(s);
	return (s_len);
}
