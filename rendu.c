/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:58:25 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 17:21:40 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rendu(t_coordinate *c, t_data *d)
{
	int		i;
	float	ratio;
	int		j;
	float	k;

	ratio = (float)d->h2 / c->h3;
	k = 0;
	i = ((d->h - c->h3) / 2) * d->l + c->t3;
	if (i < 0)
	{
		k = k + (int)floor(-i / d->l) * ratio;
		i = i + (int)floor(-i / d->l) * d->l;
	}
	j = c->t;
	while (i < (((d->h - c->h3) / 2 + c->h3) * d->l + c->t3) && i < d->h * d->l)
	{
		if (i > 0)
			d->strp[i] = d->strt[c->exp][j];
		k = k + ratio;
		j = c->t + (int)floor(k) * d->l2;
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
	if (i < 0)
	{
		k = k + (int)floor(-i / d->l) * ratio;
		i = i + (int)floor(-i / d->l) * d->l;
	}
	j = c->t_2;
	while (i < (((d->h - c->h3_2) / 2 + c->h3_2) * d->l + c->t3\
) && i < d->h * d->l)
	{
		if (i > 0)
			d->strp[i] = d->strt[c->sprite][j];
		k = k + ratio;
		j = c->t_2 + (int)floor(k) * d->l2;
		i = i + d->l;
	}
}
