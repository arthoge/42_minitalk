/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:56:35 by aoger             #+#    #+#             */
/*   Updated: 2024/11/22 23:17:06 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_pointer(va_list args)
{
	void	*p;
	int		ptrlen;

	p = va_arg(args, void *);
	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		ptrlen = 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_fd((unsigned long)p, 1);
		ptrlen = 2 + ft_hexlen((unsigned long)p);
	}
	return (ptrlen);
}
