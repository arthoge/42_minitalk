/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:38:54 by aoger             #+#    #+#             */
/*   Updated: 2024/12/09 18:32:57 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*array;
	size_t			total_size;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	array = malloc(sizeof(unsigned char) * total_size);
	if (!array)
		return (NULL);
	return (ft_memset(array, 0, total_size));
}
