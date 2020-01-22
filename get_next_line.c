/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:12:52 by akerloc-          #+#    #+#             */
/*   Updated: 2019/11/10 23:56:03 by akerloc-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_check_n(char buffer[BUFFER_SIZE + 1])
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_majbuff(char buffer[BUFFER_SIZE + 1], int i)
{
	int	j;
	int len;

	j = 0;
	len = ft_strlen(buffer);
	while (j + i < len)
	{
		buffer[j] = buffer[j + i + 1];
		j++;
	}
	buffer[j] = '\0';
}

int		ft_check(char buffer[BUFFER_SIZE + 1], char **line)
{
	int	i;

	i = ft_check_n(buffer);
	if (i != -1)
	{
		if (!(*line = ft_catbuff(buffer, *line, 0, i)))
			return (-1);
		ft_majbuff(buffer, i);
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			size;
	int			r;

	if (fd < 0 || line == NULL)
		return (-1);
	if (!(*line = ft_substr(buffer, 0, 0, 0)))
		return (-1);
	if ((r = ft_check(buffer, line)))
		return (r);
	if (!(*line = ft_catbuff(buffer, *line, 0, ft_strlen(buffer))))
		return (-1);
	if ((size = read(fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	while (size > 0)
	{
		buffer[size] = '\0';
		if ((r = ft_check(buffer, line)))
			return (r);
		if (!(*line = ft_catbuff(buffer, *line, 0, size)))
			return (-1);
		size = read(fd, buffer, BUFFER_SIZE);
	}
	buffer[0] = '\0';
	return (0);
}
