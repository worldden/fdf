/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:40:03 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/03/27 15:40:04 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*dst;

	i = 0;
	if (s == 0 || f == 0)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dst == 0)
		return (0);
	while (s[i] != 0)
	{
		dst[i] = f(s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
