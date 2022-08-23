/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:40:01 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 12:38:53 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dis_hex(unsigned int d, char *base)
{
	if (d < 16)
		write(1, &base[d], 1);
	else
	{
		dis_hex(d / 16, base);
		dis_hex(d % 16, base);
	}
}

int	len_hex(unsigned int hex)
{
	int	i;

	i = 0;
	if (hex == 0)
		return (1);
	while (hex)
	{
		hex /= 16;
		i++;
	}
	return (i);
}

int	print_hex(va_list list)
{
	unsigned int	hex;

	hex = va_arg(list, unsigned int);
	dis_hex(hex, "0123456789abcdef");
	return (len_hex(hex));
}

int	print_hex_m(va_list list)
{
	unsigned int	hex;

	hex = va_arg(list, unsigned int);
	dis_hex(hex, "0123456789ABCDEF");
	return (len_hex(hex));
}
