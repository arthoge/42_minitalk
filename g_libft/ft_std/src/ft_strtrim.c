/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 12:43:37 by aoger             #+#    #+#             */
/*   Updated: 2024/11/13 22:10:09 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_isset(int c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	size_t	i;
	size_t	start;
	size_t	end;
	size_t	len;

	start = 0;
	i = 0;
	while (s1[start] && ft_isset(s1[start], set))
		++start;
	end = start;
	while (s1[end])
		++end;
	while (end > start && ft_isset(s1[end - 1], set))
		--end;
	len = end - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (++i < len)
		new[i] = s1[start + i];
	new[len] = '\0';
	return (new);
}
