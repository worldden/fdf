/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 13:59:17 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/24 17:53:39 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char			*i;
	const char		*j;
	size_t			siz;
	size_t			dlen;

	i = dst;
	j = src;
	siz = n;
	while (n-- != 0 && *i != '\0')
		i++;
	dlen = i - dst;
	n = siz - dlen;
	if (n == 0)
		return (dlen + ft_strlen(j));
	while (*j != '\0')
	{
		if (n != 1)
		{
			*i++ = *j;
			n--;
		}
		j++;
	}
	*i = '\0';
	return (dlen + (j - src));
}
