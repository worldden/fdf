/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:27:55 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/02 17:04:21 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# define WIDTH 2000
# define HEIGHT 1200

typedef struct	s_mfd
{
	double		x1;
	double		y1;
	double		z1;
	double		x2;
	double		y2;
	double		z2;
	double		x3;
	double		y3;
	double		z3;
	double		yc;
	double		xc;
	double		zc;
}				t_mfd;

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_img
{
	int			bpp;
	int			sl;
	int			end;
}				t_img;

typedef struct	s_read
{
	char		*line;
	char		**tab;
	int			i;
	int			j;
	int			k;
}				t_read;

typedef struct	s_fdf
{
	int			fd;
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	int			**map;
	int			**color;
	int			line;
	int			width;
	int			skape;
	int			startx;
	int			starty;
	double		l;
	double		n;
	double		m;
	int			z;
	char		*img_data_addr;
	void		*img_ptr;
	int			min_z;
	int			max_z;
	int			start_color;
	int			first_color;
	int			check_color;
	int			color_z;
}				t_fdf;

typedef struct	s_brz
{
	int			dx;
	int			dy;
	int			lengthx;
	int			lengthy;
	int			length;
	int			x;
	int			y;
	int			d;
	int			color;
	t_fdf		*win;
}				t_brz;

int				valid_line(char *line);
int				valid(t_fdf *parser);
int				find_color(char **tab, int k, t_fdf *parser, int m, int l);
int				reading(t_fdf *parser);
void			reading_help(t_fdf *parser, t_read *rd);
void			mlx_web(t_fdf *parser);
t_vec			md_vec(int x, int y, double z, t_fdf *parser);
void			ft_create_img(t_fdf *parser, int x, int y, int color);
void			ft_line(t_fdf *win, t_vec vec, t_vec k_vec, int color);
void			ft_line_x(t_fdf *win, t_brz *tip, int x1, int y1);
void			ft_line_y(t_fdf *win, t_brz *tip, int x1, int y1);
int				fc_center(int large, int root, int skape);
int				ft_scape(t_fdf *parser, int width);
void			ft_chenge2(t_fdf *parser);
void			ft_chenge3(t_fdf *parser);
void			ft_chenge(t_fdf *parser);
void			put_info(t_fdf *parser);
int				deal_key_hook_two(int key, t_fdf *parser);
int				deal_key_hook(int key, t_fdf *parser);
int				deal_key(int key);
void			makefdf(t_fdf *parser, t_img *pin);
void			mlx_put_win(t_fdf *parser);
void			ft_chenge_color(t_fdf *parser);
void			ft_chenge_color_help(t_fdf *parser);
void			ft_chenge_color_z(t_fdf *parser);
int				deal_key_hook_two(int key, t_fdf *parser);
int				deal_key_hook_three(int key, t_fdf *parser);
int				get_fd(char *filename);

#endif
