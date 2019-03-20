/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:34:59 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/22 14:46:36 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t num)
{
	size_t	i;

	i = 0;
	while (src[i] && i < num)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < num)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
