/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:46:49 by aoger             #+#    #+#             */
/*   Updated: 2024/11/22 23:16:25 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_hex(va_list args)
{
	int				len;
	unsigned int	n;

	len = 0;
	n = va_arg(args, unsigned int);
	ft_puthex_fd((unsigned long)n, 1);
	len += ft_hexlen((unsigned long)n);
	return (len);
}
