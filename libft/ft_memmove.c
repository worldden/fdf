/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:41:10 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/24 15:37:15 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	size_t		r;
	char		*i;
	const char	*j;

	i = (char *)str1;
	j = (const char *)str2;
	r = 0;
	if (j < i)
	{
		while (n--)
			i[n] = j[n];
	}
	else
		ft_memcpy(str1, str2, n);
	return (str1);
}
