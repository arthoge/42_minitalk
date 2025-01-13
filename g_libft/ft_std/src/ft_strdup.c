/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:34:15 by aoger             #+#    #+#             */
/*   Updated: 2024/11/21 16:44:06 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	size_t	i;
	char	*cp;

	len_s = 0;
	while (s[len_s])
		++len_s;
	cp = malloc(sizeof(char) * (len_s + 1));
	if (!cp)
		return (NULL);
	i = 0;
	while (i < len_s)
	{
		cp[i] = s[i];
		++i;
	}
	cp[i] = '\0';
	return (cp);
}
