/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 16:24:59 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/23 18:11:21 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j] && s1[i] != '\0' &&
		(n - 1) > i && s2[j] != '\0' && (n - 1) > j)
	{
		i++;
		j++;
	}
	if (n)
		return ((unsigned char)s1[i] - (unsigned char)s2[j]);
	return (0);
}
