/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:56:28 by aoger             #+#    #+#             */
/*   Updated: 2024/11/14 17:50:53 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	i;

	len_src = 0;
	while (src[len_src])
		++len_src;
	if (size == 0)
		return (len_src);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len_src);
}
