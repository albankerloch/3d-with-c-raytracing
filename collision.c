/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:32:08 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 19:25:05 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_bord(t_data *d, int x, int y)
{
	if (y <= d->taille || y >= d->l * (d->taille - 1))
		return (0);
	if (x <= d->taille || x >= d->h * (d->taille - 1))
		return (0);
	if (d->tab[(int)floor(x / d->taille)][(int)floor(y / d->taille)] == 1)
		return (0);
	return (1);
}

int		ft_next(t_data *d, int x, t_coordinate *c, int code)
{
	if (x % d->taille == 0 && c->up == -1 && code == 1)
		return ((int)floor(x / d->taille) - 1);
	if (x % d->taille == 0 && c->side == -1 && code == 2)
		return ((int)floor(x / d->taille) - 1);
	return ((int)floor(x / d->taille));
}

void	ft_collision_objet(t_data *d, int nxt, int y2, int x2)
{
	if (nxt == 3)
		d->life = d->life > 0 ? d->life - 1 : 0;
	else
		d->life = d->life < 4 ? d->life + 1 : 4;
	d->tab[(int)floor(x2 / d->taille)][(int)floor(y2 / d->taille)] = 0;
}

void	ft_collision(t_data *d, t_coordinate *c, int y2, int x2)
{
	int nxt;

	if (ft_bord(d, x2, y2))
	{
		nxt = d->tab[ft_next(d, x2, c, 1)][ft_next(d, y2, c, 2)];
		if (nxt == 2 || nxt == 3)
		{
			if (d->y % d->taille > d->taille / 2 && d->y2 % d->taille <= \
d->taille / 2)
				ft_collision_objet(d, nxt, y2, x2);
			if (d->y % d->taille < d->taille / 2 && d->y2 % d->taille >= \
d->taille / 2)
				ft_collision_objet(d, nxt, y2, x2);
		}
		d->x = x2;
		d->y = y2;
		ft_update(d, 1);
	}
}
