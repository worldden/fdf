/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:42:03 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/27 15:42:03 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_char_next(char const *a)
{
	size_t	i;

	i = 0;
	while ((a[i] == ' ' || a[i] == '\t' || a[i] == '\n') && a[i] != '\0')
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (0);
	i = ft_char_next(s);
	k = ft_strlen(s);
	j = 0;
	while ((s[k] == ' ' || s[k] == '\t' || s[k] == '\n'
		|| s[k] == '\0') && (k > i))
		k--;
	if (i == k && (s[k] == ' ' || s[k] == '\t' || s[k] == '\n' || s[k] == '\0'))
		return (ft_strsub(s, i, k - i));
	return (ft_strsub(s, i, k - i + 1));
}
