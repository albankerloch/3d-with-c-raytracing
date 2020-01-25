/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:11:30 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 16:07:15 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_texture(t_data *d)
{
	int i;

	i = 0;
	while (i <  10)
	{
		if (d->check[i] == 1)
			free(d->texture[i - 4]);
		 i++;
	}
}

void	ft_exit_error(t_data *d, int code)
{
	int t;

	free(d->texture);
	ft_free_texture(d);
	if (code == -2)
	{
		t = 0;
		while (t < d->l_tab - 1)
		{
			free(d->tab[t]);
			t++;
		}
		free(d->tab);
	}
	write(2, "Erreur de map !\n", 16);
	d = NULL;
	exit(0);
}

int		ft_exit_line(t_data *d, char *line)
{

	free(d->fut);
	free(line);
	return (-1);
}

void	ft_exit_malloc(t_data *d, int code)
{
	(void)code;
	free(d->texture);
	ft_free_texture(d);
	if (code == 1)
		free(d->fut);
	write(2, "Erreur de malloc !\n", 19);
	d = NULL;
	exit(0);
}

