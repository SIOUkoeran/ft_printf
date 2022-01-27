/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_length_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:28:02 by mkim3             #+#    #+#             */
/*   Updated: 2022/01/27 18:56:45 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_intlen(ssize_t n, int base)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (length + 1);
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= base;
		length++;
	}
	return (length);
}

size_t	ft_unsignedlen(unsigned long n, int base)
{
	size_t	length;

	length = 0;
	if (n == 0)
		return (length + 1);
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= base;
		length++;
	}
	return (length);
}
