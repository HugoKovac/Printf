/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkovac <hkovac@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:17:10 by hkovac            #+#    #+#             */
/*   Updated: 2021/12/02 10:30:52 by hkovac           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		is_format(char c);
int		ft_dispatch(const char *format, va_list list);
int		print_hex(va_list list);
int		print_hex_m(va_list list);
int		print_ptr(va_list list);
void	ft_putchar(char c);
int		print_chr(va_list list);
int		ft_strlen(char *str);
int		print_str(va_list list);
int		print_dec(va_list list);
int		print_uns(va_list list);
void	ft_putstr(char *str);

#endif