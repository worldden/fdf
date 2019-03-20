/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:18:23 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/21 18:09:17 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	char	*i;
	char	*j;

	i = (char *)str1;
	j = (char *)str2;
	while (n > 0)
	{
		*i++ = *j++;
		n--;
	}
	return (str1);
}
