/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:49:45 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/22 13:23:44 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned char	*ptr1_c;
	unsigned char	*ptr2_c;
	size_t			i;
	size_t			j;

	if (num == 0)
		return (0);
	ptr1_c = (unsigned char *)ptr1;
	ptr2_c = (unsigned char *)ptr2;
	i = 0;
	j = 0;
	while (i <= (num - 1) && j <= (num - 1))
	{
		if (ptr1_c[i] != ptr2_c[j])
			return (ptr1_c[i] - ptr2_c[j]);
		i++;
		j++;
	}
	return (0);
}
