/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:42:30 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/28 15:58:24 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*dst;
	unsigned int	nc;

	len = get_len(n);
	nc = n;
	if (n < 0)
	{
		nc = -n;
		len++;
	}
	if (!(dst = ft_strnew(len)))
		return (0);
	dst[--len] = nc % 10 + '0';
	while (nc /= 10)
		dst[--len] = nc % 10 + '0';
	if (n < 0)
		*(dst + 0) = '-';
	return (dst);
}
