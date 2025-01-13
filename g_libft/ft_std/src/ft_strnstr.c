/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:08:31 by aoger             #+#    #+#             */
/*   Updated: 2024/11/13 22:08:30 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		if (little[j] == big[i])
		{
			while (little[j] && little[j] == big[i + j] && (i + j) < len)
				++j;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		++i;
	}
	return (NULL);
}
