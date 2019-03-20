/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 15:13:50 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/24 15:29:22 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int s)
{
	int i;

	i = 0;
	if (s == 0)
		return (ft_strlen((char *)str) + (char *)str);
	while (str[i])
	{
		if (str[i] == s)
			return ((char *)str + i);
		i++;
	}
	return (0);
}
