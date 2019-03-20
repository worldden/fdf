/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:21:36 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/22 12:44:51 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	const char		*m;
	size_t			i;

	m = (const char *)str;
	i = 0;
	while (n > i)
	{
		if (m[i] == (char)c)
			return ((void*)str + i);
		i++;
	}
	return (0);
}
