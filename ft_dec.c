/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:02:11 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 12:24:04 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dis_dec(int d)
{
	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (d < 0)
	{
		write(1, "-", 1);
		d = -d;
	}
	if (d < 10)
		ft_putchar(d + '0');
	else
	{
		dis_dec(d / 10);
		dis_dec(d % 10);
	}
}

int	len_dec(int dec)
{
	int	i;

	i = 0;
	if (dec == 0)
		return (1);
	if (dec < 0)
	{
		dec = -dec;
		i++;
	}
	while (dec)
	{
		dec /= 10;
		i++;
	}
	return (i);
}

int	print_dec(va_list list)
{
	int	dec;

	dec = va_arg(list, int);
	dis_dec(dec);
	return (len_dec(dec));
}
