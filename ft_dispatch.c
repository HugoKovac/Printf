/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:31:59 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/01 16:44:58 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dispatch(const char *format, va_list list)
{
	int	rtn;

	rtn = 0;
	if (*format == 'c')
		rtn += print_chr(list);
	if (*format == 's')
		rtn += print_str(list);
	if (*format == 'd' || *format == 'i')
		rtn += print_dec(list);
	if (*format == 'u')
		rtn += print_uns(list);
	if (*format == 'x')
		rtn += print_hex(list);
	if (*format == 'X')
		rtn += print_hex_m(list);
	if (*format == 'p')
		rtn += print_ptr(list);
	if (*format == '%')
	{
		ft_putchar('%');
		rtn++;
	}
	return (rtn);
}
