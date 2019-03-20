/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:34:55 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/02 17:39:30 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_info(t_fdf *parser)
{
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 20, 0xFFFFFF,
				"rotation of the x-axis : '[' / ']' ");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 40, 0xFFFFFF,
				"rotation of the y-axis : 'o' / 'p' ");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 60, 0xFFFFFF,
				"rotation of the z-axis : 'u' / 'i' ");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 80, 0xFFFFFF,
				"change height : ',' / '.' ");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 100, 0xFFFFFF,
				"zoom : '+' / '-' ");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 120, 0xFFFFFF,
				"move : 'left', 'right', 'up', 'down'");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 140, 0xFFFFFF,
				"change color : 'j'");
	mlx_string_put(parser->mlx_ptr, parser->win_ptr, 1600, 160, 0xFFFFFF,
				"change color of height : '7' / '9'");
}

int		deal_key_hook_three(int key, t_fdf *parser)
{
	if (key == 38)
		ft_chenge_color(parser);
	if (key == 25)
	{
		parser->color_z += 1;
		if (parser->color_z == 20)
			parser->color_z = 1;
		ft_chenge_color_z(parser);
	}
	if (key == 26)
	{
		parser->color_z -= 1;
		if (parser->color_z == 0)
			parser->color_z = 20;
		ft_chenge_color_z(parser);
	}
	return (0);
}

int		deal_key_hook_two(int key, t_fdf *parser)
{
	if (key == 123)
		parser->startx -= 10;
	if (key == 124)
		parser->startx += 10;
	if (key == 125)
		parser->starty += 10;
	if (key == 126)
		parser->starty -= 10;
	ft_chenge(parser);
	if (key == 24)
	{
		parser->skape += 4;
		ft_chenge2(parser);
	}
	if (key == 27)
	{
		parser->skape -= 4;
		if (parser->skape <= 0)
			parser->skape = 0;
		ft_chenge3(parser);
	}
	if (key == 25 || key == 26 || key == 26 || key == 38)
		deal_key_hook_three(key, parser);
	return (0);
}

int		deal_key_hook(int key, t_fdf *parser)
{
	if ((key >= 30 && key <= 35) || ((key >= 123 && key <= 126)) ||
		(key >= 24 && key <= 27) || (key == 43 || key == 47 || key == 38))
	{
		mlx_clear_window(parser->mlx_ptr, parser->win_ptr);
		if (key == 30)
			parser->l += 0.1;
		if (key == 33)
			parser->l -= 0.1;
		if (key == 35)
			parser->n += 0.1;
		if (key == 31)
			parser->n -= 0.1;
		if (key == 32)
			parser->m += 0.1;
		if (key == 34)
			parser->m -= 0.1;
		if (key == 47)
			parser->z -= 1;
		if (key == 43)
			parser->z += 1;
		ft_chenge(parser);
		if ((key >= 123 && key <= 126) || (key >= 24 && key <= 27) || key == 38)
			deal_key_hook_two(key, parser);
	}
	return (0);
}

int		deal_key(int key)
{
	if (key == 53)
	{
		exit(1);
	}
	return (0);
}
