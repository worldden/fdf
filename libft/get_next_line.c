/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddehtyar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 16:27:05 by ddehtyar          #+#    #+#             */
/*   Updated: 2018/05/09 17:59:32 by ddehtyar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*findintreads(char *line, t_list *lst)
{
	int		len;
	char	*rem;

	len = 0;
	if ((ft_strchr(lst->content, '\n') == 0) && (ft_strlen(lst->content) == 0))
		return (NULL);
	if (ft_strchr(lst->content, '\n') != 0)
		len = ft_strlen(lst->content) - ft_strlen(ft_strchr(lst->content,
		'\n'));
	else if (lst->content)
	{
		len = ft_strlen(lst->content);
		line = ft_strsub(lst->content, 0, len);
		rem = ft_strsub(lst->content, len, (ft_strlen(lst->content)));
		free(lst->content);
		lst->content = ft_strdup(rem);
		ft_strdel(&rem);
		return (line);
	}
	line = ft_strsub(lst->content, 0, len);
	rem = ft_strsub(lst->content, len + 1, (ft_strlen(lst->content)));
	free(lst->content);
	lst->content = ft_strdup(rem);
	ft_strdel(&rem);
	return (line);
}

static t_list	*find_list(t_list **new, int fd, char *mod)
{
	char	*dest;
	t_list	*tmp;

	dest = NULL;
	tmp = *new;
	while (tmp)
	{
		if ((int)tmp->fd == fd)
		{
			dest = ft_strdup(tmp->content);
			free(tmp->content);
			tmp->content = ft_strjoin(dest, mod);
			free(dest);
			return (tmp);
		}
		tmp = tmp->next;
	}
	tmp = ft_lstnew(mod, ft_strlen(mod) + 1);
	tmp->fd = fd;
	ft_lstadd(new, tmp);
	tmp = *new;
	return (tmp);
}

static char		*ftfind(char *line, int fd, int ret, t_list *new)
{
	static t_list	*lst = NULL;
	char			buf[BUFF_SIZE + 1];
	char			*mod;
	char			*temp;

	mod = ft_strnew(1);
	if (lst && (ft_strchr(lst->content, '\n') != 0) && (fd == lst->fd))
	{
		line = findintreads(line, lst);
		ft_strdel(&mod);
		return (line);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = mod;
		mod = ft_strjoin(mod, buf);
		ft_strdel(&temp);
		if (ft_strchr(mod, '\n') != 0)
			break ;
	}
	new = find_list(&lst, fd, mod);
	line = findintreads(line, new);
	ft_strdel(&mod);
	return (line);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[1];
	int				ret;
	t_list			*new;

	new = NULL;
	ret = 0;
	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || read(fd, buf, 0) < 0 ||
		fd > 4864)
		return (-1);
	*line = ftfind(*line, fd, ret, new);
	if (*line == NULL)
		return (0);
	return (1);
}
