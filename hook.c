/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:04:17 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 19:46:48 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_convert(int axe, t_coordinate *c)
{
	ft_init_t_coordinates(axe, c);
	if (c->a < 0)
		c->alpha = -c->a;
	if (c->a < 0)
		c->up = -1;
	if (c->a >= 90 && c->a < 180)
		c->alpha = 180 - c->a;
	if (c->a >= 90 && c->a < 180)
		c->side = 1;
	if (c->a >= 180 && c->a < 270)
	{
		c->alpha = c->a - 180;
		c->side = 1;
		c->up = -1;
	}
	if (c->a >= 270 && c->a < 360)
		c->alpha = 360 - c->a;
	if (c->a >= 270 && c->a < 360)
		c->up = -1;
	if (c->a >= 360)
		c->alpha = c->a - 360;
	c->delta = c->up == -1 ? 1 : 0;
	c->delta2 = c->side == -1 ? 1 : 0;
}

void	ft_change_lateral(int pas, t_coordinate *c, t_data *d)
{
	if (c->k == 0)
	{
		ft_convert(d->axe - 90, c);
		d->y2 = d->y + c->up * pas * sin(c->alpha * M_PI / 180);
		d->x2 = d->x + c->side * pas * cos(c->alpha * M_PI / 180);
		ft_collision(d, c, d->y2, d->x2);
	}
	if (c->k == 2)
	{
		ft_convert(d->axe + 90, c);
		d->y2 = d->y + c->up * pas * sin(c->alpha * M_PI / 180);
		d->x2 = d->x + c->side * pas * cos(c->alpha * M_PI / 180);
		ft_collision(d, c, d->y2, d->x2);
	}
}

void	ft_change_cam(int pas, t_coordinate *c, t_data *d)
{
	if (c->k == 123)
	{
		d->axe = d->axe - 4;
		if (d->axe < 0)
			d->axe = 359;
		ft_update(d, 1);
	}
	if (c->k == 124)
	{
		d->axe = d->axe + 4;
		if (d->axe > 360)
			d->axe = 0;
		ft_update(d, 1);
	}
	ft_change_lateral(pas, c, d);
}

int		deal_key(int key, t_data *d)
{
	int				pas;
	t_coordinate	c;

	pas = d->taille / 8;
	c.k = key;
	if (c.k == 0 || c.k == 2 || c.k == 123 || c.k == 124)
		ft_change_cam(pas, &c, d);
	if (c.k == 13 || c.k == 126)
	{
		ft_convert(d->axe, &c);
		d->y2 = d->y + c.up * pas * sin(c.alpha * M_PI / 180);
		d->x2 = d->x + c.side * pas * cos(c.alpha * M_PI / 180);
		ft_collision(d, &c, d->y2, d->x2);
	}
	if (c.k == 1 || c.k == 125)
	{
		ft_convert(d->axe, &c);
		d->y2 = d->y - c.up * pas * sin(c.alpha * M_PI / 180);
		d->x2 = d->x - c.side * pas * cos(c.alpha * M_PI / 180);
		ft_collision(d, &c, d->y2, d->x2);
	}
	if (c.k == 53)
		ft_exit(d);
	return (0);
}

int		ft_exit(t_data *d)
{
	int j;

	j = -1;
	mlx_destroy_image(d->connexion, d->fond);
	while (++j < 4 + d->check[8] + d->check[9])
	{
		mlx_destroy_image(d->connexion, d->imaget[j]);
		free(d->texture[j]);
	}
	free(d->strt);
	free(d->imaget);
	free(d->texture);
	j = -1;
	while (++j < d->l_tab)
		free(d->tab[j]);
	free(d->tab);
	mlx_destroy_window(d->connexion, d->window);
	d = NULL;
	exit(0);
	return (0);
}
