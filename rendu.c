/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:58:25 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 11:13:05 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_bord(t_data *d, int x, int y)
{
	if (y <= d->taille || y >= d->l * (d->taille - 1))
		return (0);
	if (x <= d->taille || x >= d->h * (d->taille - 1))
		return (0);
	return (0);
}

void	ft_rendu(t_coordinate *c, t_data *d)
{
	int		i;
	float	ratio;
	int		j;
	float	k;

	ratio = (float)d->h2 / c->h3;
	k = 0;
	i = ((d->h - c->h3) / 2) * d->l + c->t3;
	j = c->t;
	while (i < (((d->h - c->h3) / 2 + c->h3) * d->l + c->t3) && i < d->h * d->l)
	{
		if (i > 0)
			d->strp[i] = d->strt[c->exp][j];
		k = k + ratio;
		j = c->t + floor(k) * d->l2;
		i = i + d->l;
	}
}

void	ft_rendu_texture(t_coordinate *c, t_data *d)
{
	int		i;
	float	ratio;
	int		j;
	float	k;

	ratio = (float)d->h2 / c->h3_2;
	k = 0;
	i = ((d->h - c->h3_2) / 2) * d->l + c->t3;
	j = c->t_2;
	while (i < (((d->h - c->h3_2) / 2 + c->h3_2) * d->l + c->t3\
) && i < d->h * d->l)
	{
		if (i > 0)
			d->strp[i] = d->strt[c->sprite][j];
		k = k + ratio;
		j = c->t_2 + floor(k) * d->l2;
		i = i + d->l;
	}
}
