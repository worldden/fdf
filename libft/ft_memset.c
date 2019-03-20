/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:27:53 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/20 18:46:17 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int src, size_t len)
{
	unsigned char	*dst;

	dst = str;
	while (len > 0)
	{
		*dst = (unsigned char)src;
		dst++;
		len--;
	}
	return (str);
}
