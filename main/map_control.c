/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:06:18 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 14:50:10 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *map_name)
{
	int		i;
	char	ber[4];
	int		j;

	ber[0] = '.';
	ber[1] = 'b';
	ber[2] = 'e';
	ber[3] = 'r';
	i = ft_strlen(map_name) - 1;
	j = 4;
	if (i < 4)
		return (0);
	while (j)
	{
		if (map_name[i] != ber[j - 1])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	object_control(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'E' || map[i][j] == 'P' || map[i][j] == 'C'
				|| map[i][j] == '1' || map[i][j] == '0')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	object_ctr(char **map, int p_counter, int e_counter, int c_counter)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p_counter++;
			if (map[i][j] == 'E')
				e_counter++;
			if (map[i][j] == 'C')
				c_counter++;
			j++;
		}
		i++;
	}
	if (p_counter == 1 && e_counter == 1 && c_counter >= 1)
		return (1);
	return (0);
}

int	map_control(char *map_name)
{
	char	**map;

	map = read_map(map_name);
	if (is_rectangular(map))
		return (0);
	if (!is_ber(map_name))
		return (0);
	if (!object_control(map))
		return (0);
	if (!object_ctr(map, 0, 0, 0))
		return (0);
	return (1);
	free (map);
}
