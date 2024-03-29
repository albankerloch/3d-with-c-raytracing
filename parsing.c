/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:44:56 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/26 13:32:21 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_verif_totalite(t_data *d)
{
	int i;

	i = 1;
	while (i < 8)
	{
		if (d->check[i] != 1)
			return (-1);
		i++;
	}
	if (d->x == 0 && d->y == 0)
		return (-1);
	return (0);
}

int		ft_verif_chemin_texture(t_data *d)
{
	int		i;
	char	buff[1];
	int		fd;

	i = 0;
	while (i < 4 + d->check[8] + d->check[9])
	{
		if ((fd = open(d->texture[i], O_RDONLY)) < 0)
			return (-1);
		if (read(fd, buff, 0) < 0)
		{
			close(fd);
			return (-1);
		}
		close(fd);
		i++;
	}
	return (ft_verif_totalite(d));
}

int		ft_verif_tab(t_data *d)
{
	int i;

	i = 0;
	while (i < d->h_tab)
	{
		if (d->tab[0][i] != 1 || d->tab[d->l_tab - 1][i] != 1)
			return (-1);
		i++;
	}
	i = 0;
	while (i < d->l_tab)
	{
		if (d->tab[i][0] != 1 || d->tab[i][d->h_tab - 1] != 1)
			return (-1);
		i++;
	}
	return (ft_verif_chemin_texture(d));
}

int		ft_add_nl(t_data *d, int fd)
{
	char	*line;
	int		ret;

	line = NULL;
	while ((ret = get_next_line(fd, &line)) && ret != 0)
	{
		if (ret == -1)
			ft_exit_malloc(d, 1);
		if (ft_param(line, d) == -1)
			return (ft_exit_line(line));
		if (line[0] == '1')
		{
			if (!(d->fut = ft_catbuff(line, d->fut, 0, ft_strlen(line))))
			{
				free(line);
				ft_exit_malloc(d, 1);
			}
			d->l_tab = ft_strlen(line);
			d->h_tab = d->h_tab + 1;
		}
		free(line);
	}
	free(line);
	return (0);
}

int		ft_parsing(t_data *d, char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd < 1 || ft_strcmp(&name[ft_strlen(name) - 4], ".cub") != 0)
		return (-1);
	d->h_tab = 0;
	if (!(d->fut = malloc(sizeof(char))))
		ft_exit_malloc(d, 0);
	d->fut[0] = '\0';
	if (ft_add_nl(d, fd))
		return (-1);
	close(fd);
	if (ft_create_tab(d->fut, d))
		return (-2);
	free(d->fut);
	if (ft_verif_tab(d) == -1)
		return (-3);
	return (0);
}
