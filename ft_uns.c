/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uns.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:10:30 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 12:27:29 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dis_uns(unsigned int d)
{
	if (d < 10)
		ft_putchar(d + '0');
	else
	{
		dis_uns(d / 10);
		dis_uns(d % 10);
	}
}

int	len_uns(unsigned int dec)
{
	int	i;

	i = 0;
	if (dec == 0)
		return (1);
	while (dec)
	{
		dec /= 10;
		i++;
	}
	return (i);
}

int	print_uns(va_list list)
{
	unsigned int	uns;

	uns = va_arg(list, unsigned int);
	dis_uns(uns);
	return (len_uns(uns));
}
