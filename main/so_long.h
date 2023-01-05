/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:38:38 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/05 15:48:22 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	**read_map(char *map_name);
int		map_x_len(char *map_name);
int		map_y_len(char **map);
int		is_line(char **map, char *map_name, int i, int j);
int		first_last_line(char *line);
int		normal_line(char *line);
int		map_control(char *map_name);
int		is_ber(char *map_name);
int		object_control(char **map);
int		object_ctr(char **map, int p_counter, int e_counter, int c_counter);
int		is_rectangular(char **map, char *map_name);

//path find
t_stack	*p_locate(char **map, char *map_name);
t_stack	*c_locate(char **map, char *map_name);
int		collectable_counter(char **map, char *map_name);
int		is_turnout(char **map, int x, int y);
void	ft_moveright(char ***map, int *x, int *y);
void	ft_moveleft(char ***map, int *x, int *y);
void	ft_moveup(char ***map, int *x, int *y);
void	ft_movedown(char ***map, int *x, int *y);
char	**create_tmp_map(char *map_name);

#endif