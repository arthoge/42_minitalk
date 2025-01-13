/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 20:10:19 by aoger             #+#    #+#             */
/*   Updated: 2024/11/22 23:17:46 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_string(va_list args)
{
	int		len;
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	len = (int)ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (len);
}
