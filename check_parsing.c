/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 23:34:52 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 17:44:14 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_verif_texture(char *line, t_data *d)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (d->check[6] == 1)
			return (-1);
		if (!(d->texture[2] = ft_strdup(&line[3])))
			return (-1);
		d->check[6] = 1;
		return (0);
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (d->check[5] == 1)
			return (-1);
		if (!(d->texture[1] = ft_strdup(&line[3])))
			return (-1);
		d->check[5] = 1;
		return (0);
	}
	return (1);
}

int		ft_verif_sprite(char *line, t_data *d)
{
	if (line[0] == 'E' && line[1] == 'A')
	{
		if (d->check[7] == 1)
			return (-1);
		if (!(d->texture[3] = ft_strdup(&line[3])))
			return (-1);
		d->check[7] = 1;
		return (0);
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (d->check[4] == 1)
			return (-1);
		if (!(d->texture[0] = ft_strdup(&line[3])))
			return (-1);
		d->check[4] = 1;
		return (0);
	}
	return (1);
}

int		ft_verif_floor(char *line, t_data *d)
{
	if (line[0] == 'C' && d->check[3] == 0)
	{
		if (d->check[3] == 1)
			return (-1);
		d->color_roof = ft_convert_color(line);
		if (d->color_roof == -1)
			return (-1);
		d->check[3] = 1;
		return (0);
	}
	else if (line[0] == 'S' && line[1] == ' ')
	{
		if (d->check[8] == 1)
			return (-1);
		if (!(d->texture[4] = ft_strdup(&line[2])))
			return (-1);
		d->check[8] = 1;
		return (0);
	}
	return (1);
}

int		ft_verif_res(char *line, t_data *d)
{
	if (line[0] == 'R')
	{
		if (d->check[1] == 1)
			return (-1);
		line++;
		d->l = ft_borne_atoi(ft_atoi(line), 1);
		while (line[0] == ' ')
			line++;
		while (line[0] > 47 && line[0] < 58)
			line++;
		d->h = ft_borne_atoi(ft_atoi(line), 2);
		d->check[1] = 1;
		return (0);
	}
	else if (line[0] == 'F')
	{
		if (d->check[2] == 1)
			return (-1);
		if ((d->color_floor = ft_convert_color(line)) == -1)
			return (-1);
		d->check[2] = 1;
		return (0);
	}
	return (1);
}

int		ft_param(char *line, t_data *d)
{
	int r;

	if ((r = ft_verif_res(line, d)) != 1)
		return (r);
	else if ((r = ft_verif_floor(line, d)) != 1)
		return (r);
	else if ((r = ft_verif_sprite(line, d)) != 1)
		return (r);
	else if ((r = ft_verif_texture(line, d)) != 1)
		return (r);
	else if (line[0] == 'T' && line[1] == ' ')
	{
		if (d->check[9] == 1)
			return (-1);
		if (!(d->texture[5] = ft_strdup(&line[2])))
			return (-1);
		d->check[9] = 1;
		return (0);
	}
	else if (line[0] != '\0' && line[0] != '1')
		return (-1);
	return (0);
}
