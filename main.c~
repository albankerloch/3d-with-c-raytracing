/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:05:54 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 16:00:54 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_initialisation_d(t_data *d)
{
	int i;

	d->life = 4;
	d->taille = 512;
	d->angle = 60;
	d->h_tab = 0;
	i = 1;
	while (i < 10)
	{
		d->check[i] = 0;
		i++;
	}
	d->x = 0;
	d->y = 0;
}

void	ft_fill_init(t_data *d)
{
	int	j;

	j = 0;
	while (j < (d->l * d->h / 2))
	{
		d->strp[j] = d->color_roof;
		j++;
	}
	while (j < (d->l * d->h))
	{
		d->strp[j] = d->color_floor;
		j++;
	}
}

int		ft_create_images(t_data *d, int j)
{
	if (!(d->imaget[j] = mlx_xpm_file_to_image(d->connexion, \
d->texture[j], &(d->l2), &(d->h2))))
		ft_exit_error(d, -3);
	if (!(d->strt[j] = (int*)mlx_get_data_addr(d->imaget[j], \
&d->bitpp2, &d->size2, &d->endian2)))
		return (-1);
	return (0);
}

int		ft_init_images(t_data *d)
{
	int j;

	if (!(d->connexion = mlx_init()))
		return (-1);
	if (!(d->window = mlx_new_window(d->connexion, d->l, d->h, "Cubi3D")))
		return (-1);
	if (!(d->fond = mlx_new_image(d->connexion, d->l, d->h)))
		return (-1);
	if (!(d->strp = (int*)mlx_get_data_addr(d->fond, &d->bitpp, \
&d->size, &d->endian)))
		return (-1);
	if (!(d->imaget = (void**)malloc(6 * sizeof(void*))))
		return (-1);
	if (!(d->strt = (int**)malloc(6 * sizeof(int*))))
		return (-1);
	j = -1;
	while (++j < 4 + d->check[8] + d->check[9])
	{
		if (ft_create_images(d, j))
			return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_data	d;
	int		ret;

	ft_initialisation_d(&d);
	if (ac == 2 || (ac == 3 && ft_strcmp(av[2], "--save") == 0))
	{
		if (!(d.texture = (char**)malloc(6 * sizeof(char*))))
			return (-1);
		if ((ret = ft_parsing(&d, av[1])))
			ft_exit_error(&d, ret);
		if (ft_init_images(&d))
			return (-1);
		if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
		{
			ft_update(&d, 0);
			ft_export("save.bmp", &d);
			return (0);
		}
		ft_update(&d, 1);
		mlx_hook(d.window, 17, 0, ft_exit, (void*)&d);
		mlx_hook(d.window, 2, 0, deal_key, (void*)&d);
		mlx_loop(d.connexion);
	}
	write(2, "Erreur d'argument\n", 18);
	return (0);
}
