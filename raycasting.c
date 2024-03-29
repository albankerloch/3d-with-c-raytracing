/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:11:00 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/19 12:13:31 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_check_lht(t_data *d, t_coordinate *c)
{
	float n;

	if ((d->tab[c->ixt][c->iyt] == 2 && c->h3_2 == 0) || (d->tab\
[c->ixt][c->iyt] == 3 && c->h3_2 == 0))
	{
		if (!(fabs(c->alpha) < 0.00001))
			n = fabs(c->yt - d->y) / sin(c->alpha * M_PI / 180) * \
cos(fabs(d->axe - c->a) * M_PI / 180);
		else
			n = fabs(c->xt - d->x) * cos(fabs(d->axe - c->a) * \
M_PI / 180);
		c->t_2 = (int)floor((c->xt - c->ixt * d->taille));
		c->h3_2 = (int)floor(d->taille * d->h / (n * 2));
		c->sprite = d->tab[c->ixt][c->iyt] == 2 ? 4 : 5;
	}
}

int		ft_check_lh(t_data *d, t_coordinate *c)
{
	float n;

	if (d->tab[c->ixa][c->iya] == 1)
	{
		if (!(fabs(c->alpha) < 0.00001))
			n = fabs(c->ya - d->y) / sin(c->alpha * M_PI / 180) * \
cos(fabs(d->axe - c->a) * M_PI / 180);
		else
			n = fabs(c->xa - d->x) * cos(fabs(d->axe - c->a) * M_PI / 180);
		c->t = (int)floor((c->xa - c->ixa * d->taille));
		c->h3 = (int)floor(d->taille * d->h / (n * 2));
		c->exp = c->up == 1 ? 0 : 2;
		return (1);
	}
	return (0);
}

int		ft_check_lv(t_data *d, t_coordinate *c)
{
	float n;

	if (d->tab[c->ixb][c->iyb] == 1)
	{
		if (!(fabs(c->alpha) < 0.00001))
			n = fabs(c->yb - d->y) / sin(c->alpha * M_PI / 180) * \
cos(fabs(d->axe - c->a) * M_PI / 180);
		else
			n = fabs(c->xb - d->x) * cos(fabs(d->axe - c->a) * M_PI / 180);
		c->t = (int)floor((c->yb - c->iyb * d->taille));
		c->h3 = (int)floor(d->taille * d->h / (n * 2));
		c->exp = c->side == 1 ? 1 : 3;
		return (1);
	}
	return (0);
}

void	ft_maj_coord(t_data *d, t_coordinate *c, char opt)
{
	if (opt == 'a')
	{
		c->xa = c->xa + c->side * (d->taille) / tan(c->alpha * M_PI / 180);
		c->ya = c->ya + c->up * d->taille;
		c->ixa = (int)floor(c->xa / d->taille);
		c->iya = (int)floor(c->ya / d->taille) - c->delta;
	}
	if (opt == 'b')
	{
		c->xb = c->xb + c->side * d->taille;
		c->yb = c->yb + c->up * (d->taille) * tan(c->alpha * M_PI / 180);
		c->ixb = (int)floor(c->xb / d->taille) - c->delta2;
		c->iyb = (int)floor(c->yb / d->taille);
	}
	if (opt == 't')
	{
		c->xt = c->xt + c->side * (d->taille) / tan(c->alpha * M_PI / 180);
		c->yt = c->yt + c->up * d->taille;
		c->ixt = (int)floor(c->xt / d->taille);
		c->iyt = (int)floor(c->yt / d->taille);
	}
}

int		ft_check_left(t_data *d, t_coordinate *c)
{
	char	next;

	ft_init(d, c);
	while (1)
	{
		next = ft_check_next(c);
		if (next == 'a')
		{
			if (ft_check_lh(d, c))
				return (0);
			ft_maj_coord(d, c, 'a');
		}
		else if (next == 't')
		{
			ft_check_lht(d, c);
			ft_maj_coord(d, c, 't');
		}
		else if (next == 'b')
		{
			if (ft_check_lv(d, c))
				return (0);
			ft_maj_coord(d, c, 'b');
		}
	}
	return (0);
}
