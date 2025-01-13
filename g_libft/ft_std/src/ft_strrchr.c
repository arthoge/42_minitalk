/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:35:21 by aoger             #+#    #+#             */
/*   Updated: 2024/11/14 19:37:54 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	uc;

	uc = c;
	i = 0;
	while (s[i])
		++i;
	if (uc == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (uc == s[i - 1])
			return ((char *)&s[i - 1]);
		--i;
	}
	return (NULL);
}
