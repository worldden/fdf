/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:23:42 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/27 15:23:44 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	i;

	if (size > 0)
	{
		dst = (char *)malloc(sizeof(unsigned char) * size);
		if (dst == 0)
			return (0);
		i = 0;
		while (i < size)
		{
			dst[i] = 0;
			i++;
		}
		return (dst);
	}
	else
		return (0);
}
