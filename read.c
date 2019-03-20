/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 12:23:16 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/06/02 18:51:09 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		valid_line(char *line)
{
	char	**tab;
	int		i;
	int		k;

	tab = ft_strsplit(line, ' ');
	i = 0;
	k = 0;
	while (tab[i])
	{
		if (ft_isdigit(tab[i][0]) == 0 && tab[i][0] != '-')
			return (-1);
		i++;
	}
	k = i;
	i = -1;
	while (tab[++i])
		ft_strdel(&tab[i]);
	free(tab);
	return (k);
}

int		valid(t_fdf *parser)
{
	char	*line;
	int		i;

	parser->line = 0;
	while (get_next_line(parser->fd, &line) == 1)
	{
		i = valid_line(line);
		if (i < 1)
			return (0);
		if (parser->width == 0)
			parser->width = i;
		if (parser->width != i)
			return (0);
		parser->line += 1;
		free(line);
		line = NULL;
	}
	parser->width = i;
	parser->map = (int **)malloc(sizeof(int *) * (parser->line));
	parser->color = (int **)malloc(sizeof(int *) * (parser->line));
	close(parser->fd);
	parser->fd = open(parser->name, O_RDONLY);
	if (parser->line < 2)
		return (0);
	return (1);
}

int		ft_find_color(char **tab, int k, t_fdf *parser)
{
	int	i;
	int	color;

	i = 0;
	color = 0;
	while (tab[k][i] != ',')
		i++;
	if (tab[k][i + 1] != '0' || tab[k][i + 2] != 'x')
		return (parser->start_color);
	i += 3;
	while ((tab[k][i] >= 'A' && tab[k][i] <= 'F') || (tab[k][i] >= 'a' &&
			tab[k][i] <= 'f') || (ft_isdigit(tab[k][i]) != 0))
	{
		if (tab[k][i] >= 'A' && tab[k][i] <= 'F')
			color = color * 16 + (tab[k][i] - 55);
		else if (tab[k][i] >= '0' && tab[k][i] <= '9')
			color = color * 16 + (tab[k][i] - 48);
		else if (tab[k][i] >= 'a' && tab[k][i] <= 'f')
			color = color * 16 + (tab[k][i] - 87);
		i++;
	}
	return (color);
}

void	reading_help(t_fdf *parser, t_read *rd)
{
	parser->z = 0;
	if (!(ft_strchr(rd->tab[rd->k], ',') != 0))
		parser->color[rd->j][rd->k] = parser->start_color;
	else
		parser->color[rd->j][rd->k] = ft_find_color(rd->tab,
			rd->k, parser);
	parser->map[rd->j][rd->k] = ft_atoi(rd->tab[rd->k]);
	if (ft_atoi(rd->tab[rd->k]) < parser->min_z)
		parser->min_z = ft_atoi(rd->tab[rd->k]);
	if (ft_atoi(rd->tab[rd->k]) > parser->max_z)
		parser->max_z = ft_atoi(rd->tab[rd->k]);
	free(rd->tab[rd->k]);
}

int		reading(t_fdf *parser)
{
	t_read	rd;

	rd.i = 0;
	rd.j = 0;
	if (valid(parser) != 0)
	{
		while (get_next_line(parser->fd, &rd.line))
		{
			rd.tab = ft_strsplit(rd.line, ' ');
			parser->map[rd.j] = (int *)malloc(sizeof(int) * (parser->width));
			parser->color[rd.j] = (int *)malloc(sizeof(int) * (parser->width));
			rd.k = 0;
			while (rd.k < parser->width)
			{
				reading_help(parser, &rd);
				rd.k++;
			}
			rd.j++;
			free(rd.tab);
			free(rd.line);
			rd.line = NULL;
		}
		return (0);
	}
	return (-1);
}
