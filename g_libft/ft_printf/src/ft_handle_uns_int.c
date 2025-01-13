/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_uns_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:27:05 by aoger             #+#    #+#             */
/*   Updated: 2024/11/22 23:17:56 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_uns_int(va_list args)
{
	int				len;
	unsigned int	num;

	num = va_arg(args, unsigned int);
	ft_putnbr_uns_fd(num, 1);
	len = ft_uns_intlen(num);
	return (len);
}
