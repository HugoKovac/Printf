/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:13:51 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 12:19:02 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(va_list list)
{
	ft_putchar((char)va_arg(list, int));
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_str(va_list list)
{
	char	*str;

	str = va_arg(list, char *);
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
