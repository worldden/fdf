/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 13:45:52 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/24 17:55:32 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*st;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	st = (char*)malloc(sizeof(*src) * (i + 1));
	if (st == 0)
		return (0);
	while (src[j] != '\0')
	{
		st[j] = src[j];
		j++;
	}
	st[j] = '\0';
	return (st);
}
