/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:32:08 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/19 15:57:37 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_invert_key(t_coordinate *c)
{
	if (c->k == 13 || c->k == 126)
		return (1);
	if (c->k == 1 || c->k == 125)
		return (13);
	if (c->k == 0)
		return (2);
	if (c->k == 2)
		return (0);
	return (13);
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

	nxt = d->tab[(int)floor(x2 / d->taille)][(int)floor(y2 / d->taille)];
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
	c->up = c->up;
	ft_update(d, 1);
}
