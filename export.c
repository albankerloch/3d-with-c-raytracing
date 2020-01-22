/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 14:03:09 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/12 16:11:23 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_header(int fd, int w, int h)
{
	static unsigned char	header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, \
0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};
	unsigned int			*var;

	var = (unsigned int *)&header[2];
	*var = 54 + w * h * 3 + (w % 4) * w;
	var = (unsigned int *)&header[18];
	*var = w;
	var = (unsigned int *)&header[22];
	*var = h;
	var = (unsigned int *)&header[34];
	*var = w * h * 3 + (w % 4) * w;
	var = (unsigned int *)&header[38];
	*var = 3780;
	var = (unsigned int *)&header[42];
	*var = 3780;
	write(fd, header, 54);
}

void	ft_write_color(unsigned char *p, int fd)
{
	write(fd, &p[0], 1);
	write(fd, &p[1], 1);
	write(fd, &p[2], 1);
}

int		ft_export(char *path, t_data *d)
{
	int				fd;
	int				i;
	unsigned char	*p;
	int				ligne;
	int				t;

	fd = open(path, O_TRUNC | O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | \
S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	init_header(fd, d->l, d->h);
	ligne = d->h + 1;
	while (--ligne > 0)
	{
		i = (ligne - 1) * d->l;
		t = 0;
		while (t < d->l)
		{
			p = (unsigned char*)&d->strp[i];
			ft_write_color(p, fd);
			i++;
			t++;
		}
		write(fd, &p[0], d->l % 4);
	}
	close(fd);
	return (0);
}
