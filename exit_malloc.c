/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:11:30 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 17:49:03 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_texture(t_data *d)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (d->check[i] == 1)
			free(d->texture[i - 4]);
		i++;
	}
	free(d->texture);
}

void	ft_exit_error(t_data *d, int code)
{
	ft_free_texture(d);
	free(d->fut);
	if (code == -2)
		ft_free_tab(d, d->l_tab);
	write(2, "Erreur de map !\n", 16);
	d = NULL;
	exit(0);
}

int		ft_exit_line(char *line)
{
	free(line);
	return (-1);
}

void	ft_exit_minilib(t_data *d, int code)
{
	int j;

	if (code >= 3)
		mlx_destroy_window(d->connexion, d->window);
	if (code >= 4)
		mlx_destroy_image(d->connexion, d->fond);
	if (code >= 6)
		free(d->imaget);
	if (code >= 7)
		free(d->strt);
	if (code >= 8)
	{
		j = -1;
		while (++j < 4 + d->check[8] + d->check[9])
		{
			if (j <= code - 8)
				mlx_destroy_image(d->connexion, d->imaget[j]);
		}
	}
}

void	ft_exit_malloc(t_data *d, int code)
{
	ft_free_texture(d);
	if (code > 0)
		free(d->fut);
	if (code > 1)
	{
		ft_free_tab(d, d->l_tab);
		ft_exit_minilib(d, code);
	}
	write(2, "Erreur de malloc !\n", 19);
	d = NULL;
	exit(0);
}
