/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:38:38 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 16:24:54 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	**read_map(char *map_name);
int		map_x_len(char *map_name);
int		map_y_len(char **map);
int		is_wall(char **map);
int		first_last_line(char *line);
int		normal_line(char *line);
int		map_control(char *map_name);
int		is_ber(char *map_name);
int		object_control(char **map);
int		object_ctr(char **map, int p_counter, int e_counter, int c_counter);
int		is_rectangular(char **map, char *map_name);

#endif