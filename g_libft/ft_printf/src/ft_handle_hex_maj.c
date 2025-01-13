/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex_maj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:46:49 by aoger             #+#    #+#             */
/*   Updated: 2024/11/22 23:21:40 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_hex_maj(va_list args)
{
	int				len;
	unsigned int	n;

	len = 0;
	n = va_arg(args, unsigned int);
	ft_puthex_maj_fd((unsigned long)n, 1);
	len += ft_hexlen((unsigned long)n);
	return (len);
}
