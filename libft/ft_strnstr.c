/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 15:13:05 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/23 15:55:18 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (find[j] && i + j < len)
		{
			if (str[i + j] != find[j])
				break ;
			j++;
		}
		if (find[j] == '\0')
			return ((char *)str + i);
		i++;
	}
	return (0);
}
