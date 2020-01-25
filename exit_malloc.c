/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:11:30 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/25 14:04:23 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_exit_error(t_data *d)
{
	free(d->texture);
	write(2, "Erreur de map !\n", 16);
	d = NULL;
	exit(0);
}

void	ft_exit_malloc(t_data *d, int code)
{
	(void)code;
	free(d->texture);
	write(2, "Erreur de malloc !\n", 19);
	d = NULL;
	exit(0);
}

