/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:06:36 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/17 10:01:06 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	c_counter(char **map, char *map_name)
{
	int	rvalue;
	int	x;
	int	y;

	x = 0;
	rvalue = 0;
	while (x < map_x_len(map_name))
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'C')
				rvalue++;
			y++;
		}
		x++;
	}
	return (rvalue);
}

int	e_counter(char **map, char *map_name)
{
	int	rvalue;
	int	x;
	int	y;

	x = 0;
	rvalue = 0;
	while (x < map_x_len(map_name))
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 'E')
				rvalue++;
			y++;
		}
		x++;
	}
	return (rvalue);
}

void	data_init(t_data *data, char *map_name)
{
	int	w;
	int	h;
	int	y_len;
	int	x_len;

	data->map = read_map(map_name);
	w = map_y_len(data->map) * 50;
	h = map_x_len("map.ber") * 50;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, w, h, "Agrili Keno");
	data->coin_count = c_counter(data->map, map_name);
	data->exit_control = e_counter(data->map, map_name);
	data->bg_img = mlx_xpm_file_to_image(data->mlx_ptr, BG, &w, &h);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, W, &w, &h);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, P, &w, &h);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, E, &w, &h);
	data->collectable_img = mlx_xpm_file_to_image(data->mlx_ptr, C, &w, &h);
}
