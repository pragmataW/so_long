/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:51 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 15:01:22 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *map_name)
{
	char	**map;
	int		x_len;
	int		i;
	int		fd;

	i = 0;
	x_len = map_x_len(map_name);
	map = (char **)malloc(sizeof(char *) * (map_x_len(map_name) + 1));
	fd = open(map_name, O_RDONLY);
	while (i < x_len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}

int	map_y_len(char **map)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	ret = 0;
	while (map[i][ret] && map[i][ret] != '\n')
		ret++;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
			j++;
		if (j != ret)
			return (0);
		i++;
	}
	return (ret);
}

int	map_x_len(char *map_name)
{
	int		ctrl;
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	ctrl = open(map_name, O_RDONLY);
	if (!tmp)
	{
		tmp = get_next_line(ctrl);
		if (tmp)
			len++;
	}
	while (tmp)
	{
		tmp = get_next_line(ctrl);
		if (tmp)
			len++;
	}
	close(ctrl);
	free (tmp);
	return (len);
}

int	first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == '1')
		i++;
	if (line[i] == '\n')
		return (1);
	if (line[i] == '\0')
		return (1);
	return (0);
}
