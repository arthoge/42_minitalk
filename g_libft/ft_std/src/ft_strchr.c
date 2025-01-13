/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:12:52 by aoger             #+#    #+#             */
/*   Updated: 2024/11/14 19:30:57 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = c;
	i = 0;
	while (s[i])
	{
		if (s[i] == uc)
			return ((char *)&s[i]);
		++i;
	}
	if (uc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
