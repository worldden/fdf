/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:33:24 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/21 18:08:12 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	size_t	k;
	char	*i;
	char	*j;

	i = (char *)str1;
	j = (char *)str2;
	k = 0;
	while (n > k)
	{
		i[k] = j[k];
		if (j[k] == (char)c)
			return ((unsigned char *)str1 + k + 1);
		k++;
	}
	return (0);
}
