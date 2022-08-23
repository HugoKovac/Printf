/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:19:26 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 12:30:05 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dis_ptr(unsigned long long d, char *base)
{
	if (d == (unsigned long long)-2147483648)
		write(1, "-80000000", 9);
	if (d < 16)
		write(1, &base[d], 1);
	else
	{
		dis_ptr(d / 16, base);
		dis_ptr(d % 16, base);
	}
}

int	len_ptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

int	print_ptr(va_list list)
{
	unsigned long long	ptr;

	ptr = va_arg(list, unsigned long long);
	write(1, "0x", 2);
	dis_ptr(ptr, "0123456789abcdef");
	return (len_ptr(ptr) + 2);
}
