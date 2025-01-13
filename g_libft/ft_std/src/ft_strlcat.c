/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:29:02 by aoger             #+#    #+#             */
/*   Updated: 2024/11/13 22:09:55 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lendst = 0;
	while (dst[lendst])
		++lendst;
	lensrc = 0;
	while (src[lensrc])
		++lensrc;
	if (size <= lendst)
		return (lensrc + size);
	i = 0;
	while (src[i] && (i + lendst) < (size - 1))
	{
		dst[lendst + i] = src[i];
		++i;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
