/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:23:51 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/07/23 20:44:31 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mlx_web(t_fdf *parser)
{
	t_vec	vec;
	t_vec	k_vec;
	t_vec	y_vec;
	int		x;
	int		y;

	y = 0;
	while (y < parser->line)
	{
		x = -1;
		while (++x < parser->width)
		{
			vec = md_vec(x, y, (parser->map[y][x]), parser);
			k_vec = md_vec((x + 1), y, parser->map[y][x + 1], parser);
			if (x != parser->width - 1)
				ft_line(parser, vec, k_vec, parser->color[y][x]);
			if (y != parser->line - 1)
			{
				y_vec = md_vec(x, (y + 1), (parser->map[y + 1][x]), parser);
				ft_line(parser, vec, y_vec, parser->color[y][x]);
			}
		}
		y++;
	}
	mlx_put_win(parser);
}

t_vec	md_vec(int x, int y, double z, t_fdf *parser)
{
	t_vec	ret;
	t_mfd	rc;
	double	yc;
	double	xc;
	double	zc;

	if (z == parser->max_z)
		z = z + parser->z;
	yc = parser->line / 2;
	xc = parser->width / 2;
	zc = z / 2;
	rc.x1 = x;
	rc.y1 = yc + (y - yc) * cos(parser->l) + (zc - z) * sin(parser->l);
	rc.z1 = zc + (y - yc) * sin(parser->l) + (z - zc) * cos(parser->l);
	rc.x2 = xc + (rc.x1 - xc) * cos(parser->n) + (rc.z1 - zc) * sin(parser->n);
	rc.y2 = rc.y1;
	rc.z2 = zc + (xc - rc.x1) * sin(parser->n) + (rc.z1 - zc) * cos(parser->n);
	rc.x3 = xc + (rc.x2 - xc) * cos(parser->m) + (yc - rc.y2) * sin(parser->m);
	rc.y3 = yc + (rc.x2 - xc) * sin(parser->m) + (rc.y2 - yc) * cos(parser->m);
	rc.z3 = rc.z2;
	ret.x = rc.x3 * parser->skape + parser->startx;
	ret.y = rc.y3 * parser->skape + parser->starty;
	return (ret);
}

void	ft_line(t_fdf *win, t_vec vec, t_vec k_vec, int color)
{
	t_brz	tip;
	int		x2;
	int		x1;
	int		y2;
	int		y1;

	x2 = k_vec.x;
	x1 = vec.x;
	y2 = k_vec.y;
	y1 = vec.y;
	tip.color = color;
	tip.dx = (x2 - x1 >= 0 ? 1 : -1);
	tip.dy = (y2 - y1 >= 0 ? 1 : -1);
	tip.lengthx = abs(x2 - x1);
	tip.lengthy = abs(y2 - y1);
	tip.length = (tip.lengthx > tip.lengthy ? tip.lengthx : tip.lengthy);
	if (tip.length == 0)
		ft_create_img(win, x1, y2, tip.color);
	if (tip.lengthy <= tip.lengthx)
		ft_line_x(win, &tip, x1, y1);
	else
		ft_line_y(win, &tip, x1, y1);
}

void	ft_line_x(t_fdf *win, t_brz *tip, int x1, int y1)
{
	tip->x = x1;
	tip->y = y1;
	tip->d = -tip->lengthx;
	tip->length++;
	while (tip->length--)
	{
		ft_create_img(win, tip->x, tip->y, tip->color);
		tip->x += tip->dx;
		tip->d += 2 * tip->lengthy;
		if (tip->d > 0)
		{
			tip->d -= 2 * tip->lengthx;
			tip->y += tip->dy;
		}
	}
}

void	ft_line_y(t_fdf *win, t_brz *tip, int x1, int y1)
{
	tip->x = x1;
	tip->y = y1;
	tip->d = -tip->lengthy;
	tip->length++;
	while (tip->length--)
	{
		ft_create_img(win, tip->x, tip->y, tip->color);
		tip->y += tip->dy;
		tip->d += 2 * tip->lengthx;
		if (tip->d > 0)
		{
			tip->d -= 2 * tip->lengthy;
			tip->x += tip->dx;
		}
	}
}
