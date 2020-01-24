/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:09:49 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/24 20:22:07 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_s(int t1, int t2, int t3, char s[9])
{
	char	*base;

	base = "0123456789abcdef";
	s[0] = '0';
	s[1] = '0';
	s[2] = base[t1 / 16];
	s[3] = base[t1 % 16];
	s[4] = base[t2 / 16];
	s[5] = base[t2 % 16];
	s[6] = base[t3 / 16];
	s[7] = base[t3 % 16];
	s[8] = '\0';
}

int		ft_convert_color(char *line)
{
	int		t1;
	int		t2;
	int		t3;
	char	s[9];

	line++;
	t1 = ft_atoi(line);
	line++;
	while ((line[0] > 47 && line[0] < 58) || line[0] == ' ')
		line++;
	line++;
	t2 = ft_atoi(line);
	while ((line[0] > 47 && line[0] < 58) || line[0] == ' ')
		line++;
	line++;
	t3 = ft_atoi(line);
	ft_fill_s(t1, t2, t3, s);
	if (t1 > 255 || t1 < 0 || t2 > 255 || t2 < 0 || t3 > 255 || t3 < 0)
        return (-1);
	return (ft_atoi_base(s, "0123456789abcdef"));
}
