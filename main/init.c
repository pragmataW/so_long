/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:06:36 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/17 04:51:15 by yciftci          ###   ########.fr       */
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
	int	width;
	int	height;
	int	y_len;
	int	x_len;

	data->map = read_map(map_name);
	width = map_y_len(data->map) * 50;
	height = map_x_len("map.ber") * 50;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "Agrili Keno");
	data->coin_count = c_counter(data->map, map_name);
	data->exit_control = e_counter(data->map, map_name);
	//buradan sonrası segfault!
	data->bg_img = mlx_xpm_file_to_image(data->mlx_ptr, BG, 50, 50);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, W, 50, 50);
	data->player_img = mlx_xpm_file_to_image(data->mlx_ptr, P, 50, 50);
	data->exit_img = mlx_xpm_file_to_image(data->mlx_ptr, E, 50, 50);
	data->collectable_img = mlx_xpm_file_to_image(data->mlx_ptr, C, 50, 50);
}

int	main(void)
{
	char **map = read_map("map.ber");
	t_data *data = malloc(sizeof(t_data));
	data_init(data,"map.ber");
	//mlx_loop(data->mlx_ptr);
	//(void) data->win_ptr;
	return (0);
}
