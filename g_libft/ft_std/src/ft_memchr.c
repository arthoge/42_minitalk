/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:09:31 by aoger             #+#    #+#             */
/*   Updated: 2024/11/13 22:09:36 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		val;

	val = (unsigned char)c;
	str = s;
	i = 0;
	while (i < n)
	{
		if (val == str[i])
			return ((void *)&str[i]);
		++i;
	}
	return (NULL);
}
