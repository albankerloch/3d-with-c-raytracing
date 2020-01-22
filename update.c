/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:02:08 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/19 12:16:52 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_life(t_data *d)
{
	int j;
	int i;

	i = 5;
	while (i < d->l / 32)
	{
		j = 10 + d->l * i;
		while (j < 10 + d->l * i + d->h / 8)
		{
			d->strp[j] = 0;
			j++;
		}
		if (i > 15 && i < d->l / 32 - 10)
		{
			j = 20 + d->l * i;
			while (j < d->l * i + d->h / 8)
			{
				if (j < d->l * i + (d->h / 8 + 20) * d->life / 4)
					d->strp[j] = d->color_floor;
				j++;
			}
		}
		i++;
	}
}

int		ft_update(t_data *d, int option)
{
	t_coordinate c;

	ft_fill_init(d);
	c.t3 = 0;
	c.t = 0;
	c.ix = floor(d->x / d->taille);
	c.iy = floor(d->y / d->taille);
	c.a = d->axe - d->angle / 2;
	c.exp = 3;
	while (c.t3 < d->l)
	{
		c.h3_2 = 0;
		ft_check_left(d, &c);
		ft_rendu(&c, d);
		if (c.h3_2 != 0)
		{
			ft_rendu_texture(&c, d);
		}
		c.t3++;
		c.a = c.a + d->angle / d->l;
	}
	ft_fill_life(d);
	if (option == 1)
		mlx_put_image_to_window(d->connexion, d->window, d->fond, 0, 0);
	return (0);
}

void	ft_exit_error(t_data *d)
{
	free(d->texture);
	write(2, "Erreur de map !\n", 16);
	d = NULL;
	exit(0);
}

void	ft_init_t_coordinates(int axe, t_coordinate *c)
{
	c->a = axe;
	c->up = 1;
	c->side = -1;
	c->alpha = c->a;
}
