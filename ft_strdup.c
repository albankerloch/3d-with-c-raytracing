/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 00:05:58 by akerloc-          #+#    #+#             */
/*   Updated: 2020/01/22 23:25:30 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (src[j] == ' ')
		j++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *src)
{
	char *s;

	s = NULL;
	if (!(s = (char*)malloc(ft_strlen(src) + 1)))
		return (s);
	ft_strcpy(s, src);
	return (s);
}
