/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:46:36 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/20 13:25:43 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	*data;
	char	**map;

	map = read_map(argv[1]);
	if (argc > 2)
		exit(write(1, "Too many argument", sizeof("Too many argument")));
	else if (argc < 2)
		exit(write(1, "Too few argument", sizeof("Too few argument")));
	data = malloc(sizeof(t_data));
	map_control(map, argv[1]);
	data_init(data, argv[1]);
	put_img(data, data->map, 0, 0);
	mlx_key_hook(data->w_p, controller, data);
	mlx_loop(data->m_p);
}
