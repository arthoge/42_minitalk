/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifiers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:59:47 by aoger             #+#    #+#             */
/*   Updated: 2024/11/23 00:02:56 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_check_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_handle_specifiers(char specifier, va_list args)
{
	int	print_count;

	print_count = 0;
	if (specifier == 'c')
		print_count = ft_handle_char(args);
	else if (specifier == 's')
		print_count = ft_handle_string(args);
	else if (specifier == 'p')
		print_count = ft_handle_pointer(args);
	else if (specifier == 'd' || specifier == 'i')
		print_count = ft_handle_int(args);
	else if (specifier == 'u')
		print_count = ft_handle_uns_int(args);
	else if (specifier == 'x')
		print_count = ft_handle_hex(args);
	else if (specifier == 'X')
		print_count = ft_handle_hex_maj(args);
	else if (specifier == '%' || !ft_check_specifier(specifier))
		print_count = ft_handle_percent();
	else
		return (0);
	return (print_count);
}
