/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 10:52:39 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/12 18:48:56 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_testbase(char *base)
{
	int		i;
	int		j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i] != '\0')
	{
		if (!((base[i] >= '0' && base[i] <= '9') ||
(base[i] <= 'z' && base[i] >= 'a') || (base[i] <= 'Z' && base[i] >= 'A')))
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

static int	ft_nbbase(char c, char *base)
{
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, char *base)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (ft_testbase(base))
	{
		while (ft_isspace(str[i]))
			i++;
		while (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign = sign * (-1);
			i++;
		}
		while (ft_nbbase(str[i], base) != -1 && str[i] != '\0')
		{
			res = res * ft_strlen(base) + ft_nbbase(str[i], base);
			i++;
		}
		return (res * sign);
	}
	return (0);
}
