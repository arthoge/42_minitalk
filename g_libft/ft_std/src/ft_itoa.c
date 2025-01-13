/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoger <aoger@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:36:52 by aoger             #+#    #+#             */
/*   Updated: 2024/12/09 18:33:13 by aoger            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static size_t	ft_nbrlen(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		++length;
	while (n)
	{
		++length;
		n /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*strnbr;
	int		sign;
	size_t	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	length = ft_nbrlen(n);
	strnbr = malloc(sizeof(char) * (length + 1));
	if (!strnbr)
		return (NULL);
	if (n < 0)
	{
		strnbr[0] = '-';
		n *= -1;
		sign = 1;
	}
	strnbr[length] = '\0';
	while (length - sign)
	{
		strnbr[--length] = (n % 10) + '0';
		n /= 10;
	}
	return (strnbr);
}
