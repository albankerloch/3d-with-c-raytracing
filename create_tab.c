/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:11:57 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/26 13:32:02 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_tab(t_data *d, int i)
{
	int t;

	t = 0;
	while (t < i)
	{
		free(d->tab[t]);
		t++;
	}
	free(d->tab);
}

void	ft_fill_axe(char *futur_tab, int t, t_data *d)
{
	if (futur_tab[t] == 'W')
		d->axe = 0;
	if (futur_tab[t] == 'N')
		d->axe = 90;
	if (futur_tab[t] == 'E')
		d->axe = 180;
	if (futur_tab[t] == 'S')
		d->axe = 270;
}

void	ft_maj_t_coordinates(int **tab, int i, int j, t_data *d)
{
	if (d->x != 0 || d->y != 0)
		ft_exit_error(d, -2);
	d->x = i * d->taille + d->taille / 2;
	d->y = j * d->taille + d->taille / 2 - 10;
	tab[i][j] = 0;
}

int		ft_tab(int **tab, char *ft, t_data *d)
{
	int i;
	int j;
	int t;

	j = d->h_tab;
	t = 0;
	while (--j >= 0)
	{
		i = -1;
		while (++i < d->l_tab)
		{
			if (ft[t] == 'N' || ft[t] == 'S' || ft[t] == 'E' || ft[t] == 'W')
			{
				ft_maj_t_coordinates(tab, i, j, d);
				ft_fill_axe(ft, t, d);
			}
			else if (ft[t] == '0' || ft[t] == '1' || (ft[t] == \
'2' && d->check[8] == 1) || (ft[t] == '3' && d->check[9] == 1))
				tab[i][j] = ft[t] - 48;
			else
				return (-1);
			t++;
		}
	}
	return (0);
}

int		ft_create_tab(char *ft, t_data *d)
{
	int i;

	if (!(d->tab = malloc(d->l_tab * sizeof(int*))))
		ft_exit_malloc(d, 1);
	i = 0;
	while (i < d->l_tab)
	{
		if (!(d->tab[i] = malloc(sizeof(int) * (d->h_tab + 1))))
		{
			ft_free_tab(d, i);
			ft_exit_malloc(d, 1);
		}
		i++;
	}
	if (ft_tab(d->tab, ft, d))
		return (-1);
	return (0);
}
