/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:51:59 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/02 17:54:32 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_img(t_fdf *parser, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
		*(int *)(parser->img_data_addr + ((x + y * WIDTH) * 4)) = color;
}

void	find_img_addr(t_fdf *parser, t_img *pin)
{
	pin->bpp = 8;
	pin->sl = 1;
	pin->end = (WIDTH * HEIGHT);
	parser->img_ptr = mlx_new_image(parser->mlx_ptr, WIDTH, HEIGHT);
	parser->img_data_addr = mlx_get_data_addr(parser->img_ptr,
		&pin->bpp, &pin->sl, &pin->end);
}

void	makefdf(t_fdf *parser, t_img *pin)
{
	int i;
	int j;

	i = 0;
	j = 0;
	parser->l = 0.2;
	parser->n = 0.1;
	parser->m = 0.0;
	if (reading(parser) == -1)
	{
		ft_putendl("Error");
		return ;
	}
	parser->skape = ft_scape(parser, WIDTH);
	parser->mlx_ptr = mlx_init();
	parser->win_ptr = mlx_new_window(parser->mlx_ptr, WIDTH, HEIGHT, "fdf");
	parser->startx = fc_center(WIDTH, parser->width, parser->skape);
	parser->starty = fc_center(HEIGHT, parser->line, parser->skape);
	find_img_addr(parser, pin);
	mlx_web(parser);
	mlx_key_hook(parser->win_ptr, deal_key, parser);
	mlx_hook(parser->win_ptr, 2, (1L << 0), deal_key_hook, parser);
	mlx_loop(parser->mlx_ptr);
}

int		get_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		return (-1);
	}
	else
	{
		fd = open(filename, O_RDONLY);
		if (fd > 0)
			return (fd);
		else
			return (-1);
	}
}

int		main(int argc, char **argv)
{
	t_fdf	win;
	t_img	pin;

	win.start_color = 16777215;
	win.width = 0;
	win.min_z = 10;
	win.max_z = 0;
	win.check_color = 0;
	win.color_z = 1;
	if (argc == 2)
	{
		win.name = argv[1];
		win.fd = get_fd(win.name);
		if (win.fd > 0)
			makefdf(&win, &pin);
	}
	else
		ft_putendl("usage: ./fdf file");
	return (0);
}
