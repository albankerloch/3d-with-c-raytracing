/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:24:37 by akerloc-          #+#    #+#             */
/*   Updated: 2019/11/09 18:52:18 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_catbuff(char *buffer, char *line, int start, int end)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(line) +
end - start + 1))))
		return (NULL);
	j = 0;
	while (line[j])
	{
		res[j] = line[j];
		j++;
	}
	i = start;
	while (i < (size_t)end)
	{
		res[j] = buffer[i];
		j++;
		i++;
	}
	res[j] = '\0';
	free(line);
	return (res);
}

int		ft_strlen(const char *str)
{
	int	a;

	a = 0;
	if (!(str))
		return (0);
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

char	*ft_substr(char *s, int start, int len, int n)
{
	char	*dest;
	int		i;
	int		j;

	dest = NULL;
	if (!(dest = (char*)malloc(ft_strlen(s) + 1)))
		return (dest);
	j = 0;
	i = start;
	while (s[i] != '\0' && j < len)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	if (n)
		free(s);
	return (dest);
}
