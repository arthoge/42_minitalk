/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:23:30 by aoger             #+#    #+#             */
/*   Updated: 2024/11/19 13:11:3 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		print_count;
	va_list	args;

	if (!format)
		return (-1);
	print_count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			++format;
			print_count += ft_handle_specifiers(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			++print_count;
		}
		++format;
	}
	va_end(args);
	return (print_count);
}
