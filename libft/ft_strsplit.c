/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:42:15 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/27 15:42:16 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_char(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (i == 1 && *s == c)
			i = 0;
		if (i == 0 && *s != c)
		{
			i = 1;
			j++;
		}
		s++;
	}
	return (j);
}

static int	ft_world(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**dst;

	if (!s)
		return (0);
	i = 0;
	j = ft_len_char((const char *)s, c);
	dst = (char **)malloc(sizeof(*dst) * (ft_len_char((const char *)s, c) + 1));
	if (!dst)
		return (0);
	while (j--)
	{
		while (*s == c & *s != '\0')
			s++;
		dst[i] = ft_strsub((const char *)s, 0, ft_world((const char *)s, c));
		if (dst[i] == 0)
			return (0);
		s = s + ft_world(s, c);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
