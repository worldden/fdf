/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 16:41:12 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/02 17:08:37 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_put_win(t_fdf *parser)
{
	mlx_put_image_to_window(parser->mlx_ptr, parser->win_ptr,
						parser->img_ptr, 0, 0);
	put_info(parser);
}

void	ft_chenge_color_help(t_fdf *parser)
{
	int x;
	int y;

	y = 0;
	while (y < parser->line)
	{
		x = 0;
		while (x < parser->width)
		{
			if (parser->color[y][x] == parser->first_color)
				parser->color[y][x] = parser->start_color;
			x++;
		}
		y++;
	}
	mlx_web(parser);
}

void	ft_chenge_color(t_fdf *parser)
{
	parser->first_color = parser->start_color;
	ft_memset(parser->img_data_addr, 0, ((WIDTH * HEIGHT) * 5));
	parser->check_color += 1;
	if (parser->check_color == 7)
		parser->check_color = 0;
	if (parser->check_color == 0)
		parser->start_color = 16777215;
	if (parser->check_color == 1)
		parser->start_color = 255;
	if (parser->check_color == 2)
		parser->start_color = 65535;
	if (parser->check_color == 3)
		parser->start_color = 65280;
	if (parser->check_color == 4)
		parser->start_color = 16711935;
	if (parser->check_color == 5)
		parser->start_color = 16711680;
	if (parser->check_color == 6)
		parser->start_color = 16776960;
	ft_chenge_color_help(parser);
}

void	ft_chenge_color_z(t_fdf *parser)
{
	int	x;
	int	y;

	y = -1;
	ft_memset(parser->img_data_addr, 0, ((WIDTH * HEIGHT) * 5));
	while (++y < parser->line)
	{
		x = -1;
		while (++x < parser->width)
		{
			if (parser->map[y][x] > 0 && parser->map[y][x] != parser->min_z)
			{
				if (parser->color_z == 19)
					parser->color[y][x] = (16711680 / parser->map[y][x]);
				else
					parser->color[y][x] = (16777215 / ((parser->color_z * 1)
						* parser->map[y][x]));
			}
			if (parser->color[y][x] == 0)
				parser->color[y][x] = 16711680;
		}
	}
	mlx_web(parser);
}
