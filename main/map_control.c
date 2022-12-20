/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:06:18 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 09:50:21 by yciftci          ###   ########.fr       */
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
	while(j)
	{
		if (map_name[i] != ber[j - 1])
			return (0);
		i--;
		j--;
	}
	return (1);
}

int	map_control(char *map_name)
{
	char **map;
	
	map = read_map();
	if (!is_ber(map_name))
		return (0);
}