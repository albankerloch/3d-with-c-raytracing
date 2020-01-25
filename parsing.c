/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:44:56 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 14:17:10 by akerloc-         ###   ########.fr       */
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

char	*ft_add_nl(t_data *d, int fd)
{
	char *line;
	char *futur_tab;

	if (!(futur_tab = malloc(sizeof(char))))
		return (NULL);
	futur_tab[0] = '\0';
	line = NULL;
	while ((get_next_line(fd, &line)))
	{
		if (ft_param(line, d) == -1)
		{
			free(futur_tab);
			return (NULL);
		}
		if (line[0] == '1')
		{
			if (!(futur_tab = ft_catbuff(line, futur_tab, 0, ft_strlen(line))))
				return (NULL);
			d->l_tab = ft_strlen(line);
			d->h_tab = d->h_tab + 1;
		}
		free(line);
	}
	free(line);
	return (futur_tab);
}

int		ft_parsing(t_data *d, char *name)
{
	int		fd;
	char	*futur_tab;

	fd = open(name, O_RDONLY);
	if (fd < 1 || ft_strcmp(&name[ft_strlen(name) - 4], ".cub") != 0)
		return (-1);
	d->h_tab = 0;
	if (!(futur_tab = ft_add_nl(d, fd)))
		return (-1);
	close(fd);
	if (!(d->tab = ft_create_tab(futur_tab, d)))
		return (-1);
	free(futur_tab);
	if (ft_verif_tab(d) == -1)
		return (-1);
	return (0);
}
