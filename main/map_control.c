/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 16:06:18 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 01:27:30 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(char **map)
{
	int i;
	int x_len;
	int y_len;

	y_len = ft_strlen(map[0]);
	x_len = map_x_len();
	i = 0;
	
	while (map[i])
	{
		if (i == 0)
			return (first_last_line(map[i]));
		else if	(i == x_len - 1)	
			return (first_last_line(map[i]));
		else
			return (normal_line(map[i]));
	}
	return(0);
}
