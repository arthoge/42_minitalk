/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:51:38 by aoger             #+#    #+#             */
/*   Updated: 2024/12/09 18:34:08 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static size_t	ft_nbwds(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			++i;
		if (s[i] && s[i] != c)
			++count;
		while (s[i] && s[i] != c)
			++i;
	}
	return (count);
}

static void	ft_free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

static char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	dup = malloc(n + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		++i;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	i;
	size_t	j;

	split = malloc(sizeof(char *) * (ft_nbwds(s, c) + 1));
	if (!split)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				++i;
			split[j++] = ft_strndup(&s[start], i - start);
			if (!split[j - 1])
				return (ft_free_split(split), NULL);
		}
		else
			++i;
	}
	return (split[j] = NULL, split);
}
