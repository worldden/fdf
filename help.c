/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:24:02 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/02 16:06:26 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fc_center(int large, int root, int skape)
{
	int	start;
	int	large_map;

	large_map = skape * root;
	start = (large - large_map) / 2;
	return (start);
}

int		ft_scape(t_fdf *parser, int width)
{
	int	skape;

	skape = (width / parser->width) * 0.7;
	return (skape);
}

void	ft_chenge2(t_fdf *parser)
{
	ft_memset(parser->img_data_addr, 0, ((WIDTH * HEIGHT) * 5));
	if (parser->skape > 4)
	{
		parser->startx -= ((parser->width * 4) / 2);
		parser->starty -= ((parser->line * 4) / 2);
	}
	mlx_web(parser);
}

void	ft_chenge3(t_fdf *parser)
{
	ft_memset(parser->img_data_addr, 0, ((WIDTH * HEIGHT) * 5));
	if (parser->skape != 0)
	{
		parser->startx += ((parser->width * 4) / 2);
		parser->starty += ((parser->line * 4) / 2);
	}
	mlx_web(parser);
}

void	ft_chenge(t_fdf *parser)
{
	ft_memset(parser->img_data_addr, 0, ((WIDTH * HEIGHT) * 5));
	mlx_web(parser);
}
