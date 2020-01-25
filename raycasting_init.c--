/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:02:25 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/12 18:03:01 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_convert(t_coordinate *c)
{
	if (c->a < 0)
	{
		c->alpha = -c->a;
		c->up = -1;
	}
	if (c->a >= 90 && c->a < 180)
	{
		c->alpha = 180 - c->a;
		c->side = 1;
	}
	if (c->a >= 180 && c->a < 270)
	{
		c->alpha = c->a - 180;
		c->side = 1;
		c->up = -1;
	}
	if (c->a >= 270 && c->a < 360)
	{
		c->alpha = 360 - c->a;
		c->up = -1;
	}
	if (c->a >= 360)
	{
		c->alpha = c->a - 360;
	}
}

void	ft_init_coord(t_data *d, t_coordinate *c)
{
	c->xa = d->x + c->side * c->u2 / tan(c->alpha * M_PI / 180);
	c->ya = d->y + c->up * c->u2;
	c->ixa = floor(c->xa / d->taille);
	c->iya = floor(c->ya / d->taille) - c->delta;
	c->xb = d->x + c->side * c->u;
	c->yb = d->y + c->up * c->u * tan(c->alpha * M_PI / 180);
	c->ixb = floor(c->xb / d->taille) - c->delta2;
	c->iyb = floor(c->yb / d->taille);
}

void	ft_init(t_data *d, t_coordinate *c)
{
	c->up = 1;
	c->side = -1;
	c->alpha = c->a;
	ft_init_convert(c);
	c->delta = c->up == -1 ? 1 : 0;
	c->delta2 = c->side == -1 ? 1 : 0;
	c->u = c->side == -1 ? d->x % d->taille : d->taille - (d->x % d->taille);
	c->u2 = c->up == -1 ? d->y % d->taille : d->taille - (d->y % d->taille);
	ft_init_coord(d, c);
	if (d->y % d->taille >= d->taille / 2)
	{
		c->xt = d->x + c->side * (c->u2 + c->up * d->taille / 2) / \
tan(c->alpha * M_PI / 180);
		c->yt = d->y + c->up * (c->u2 + c->up * d->taille / 2);
	}
	else
	{
		c->xt = d->x + c->side * (c->u2 - c->up * d->taille / 2) / \
tan(c->alpha * M_PI / 180);
		c->yt = d->y + c->up * (c->u2 - c->up * d->taille / 2);
	}
	c->ixt = floor(c->xt / d->taille);
	c->iyt = floor(c->yt / d->taille);
}

char	ft_check_down(t_coordinate *c)
{
	if (c->ya >= c->yb)
	{
		if (c->ya >= c->yt)
			return ('a');
		else
			return ('t');
	}
	else
	{
		if (c->yb >= c->yt)
			return ('b');
		else
			return ('t');
	}
	return ('z');
}

char	ft_check_next(t_coordinate *c)
{
	if (c->up == 1)
	{
		if (c->ya <= c->yb)
		{
			if (c->ya <= c->yt)
				return ('a');
			else
				return ('t');
		}
		else
		{
			if (c->yb <= c->yt)
				return ('b');
			else
				return ('t');
		}
	}
	if (c->up == -1)
	{
		return (ft_check_down(c));
	}
	return ('z');
}
