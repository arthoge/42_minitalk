/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:57:54 by aoger             #+#    #+#             */
/*   Updated: 2024/12/09 18:34:31 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	size_t	length;
	char	*new;

	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	length = len_s - start;
	if (len < length)
		length = len;
	new = malloc(sizeof(char) * (length + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i < length && s[start + i])
	{
		new[i] = s[start + i];
		++i;
	}
	new[i] = '\0';
	return (new);
}
