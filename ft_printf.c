/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:16:11 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 12:44:02 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		rtn;

	rtn = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			rtn += ft_dispatch(format, list);
			if (is_format(*format))
				format++;
		}
		else
		{
			write (1, format, 1);
			format++;
			rtn++;
		}
	}
	va_end(list);
	return (rtn);
}
