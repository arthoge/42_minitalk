/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:04:18 by aoger             #+#    #+#             */
/*   Updated: 2024/11/22 23:24:33 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_int(va_list args)
{
	int	len;
	int	nbr;

	nbr = va_arg(args, int);
	ft_putnbr_fd(nbr, 1);
	len = ft_intlen(nbr);
	return (len);
}
