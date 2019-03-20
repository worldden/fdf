/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 14:44:30 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/23 15:09:39 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int	i;
	int	j;

	i = 0;
	if (*find == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (find[j])
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
