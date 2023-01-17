/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:38:38 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/17 10:02:17 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define IMG_SIZE 50
# define BG "../textures/bg.xpm"
# define W "../textures/wall.xpm"
# define P "../textures/main_c.xpm"
# define E "../textures/exit_1.xpm"
# define C "../textures/collectable_1.xpm"

typedef struct s_variables
{
	t_stack	*p_l;
	t_stack	*c_l;
	t_stack	*tmp;
	char	**tmp_map;
	int		c_counter;
}				t_variables;

typedef struct s_data
{
	char	**map;
	void	*mlx_ptr;
	void	*win_ptr;
	char	*player_img;
	char	*exit_img;
	char	*collectable_img;
	char	*wall_img;
	char	*bg_img;
	int		coin_count;
	int		exit_control;
}				t_data;

//!map control and map control utils
char	**read_map(char *map_name);
int		map_x_len(char *map_name);
int		map_y_len(char **map);
int		is_line(char **map, char *map_name, int i, int j);
int		first_last_line(char *line);
int		normal_line(char *line);
int		map_control(char **map, char *map_name);
int		is_ber(char *map_name);
int		object_control(char **map);
int		object_ctr(char **map, int p_counter, int e_counter, int c_counter);
int		is_rectangular(char **map, char *map_name);

//!path find
void	free_double(t_variables *var, char **str, int check);
void	no_way(t_stack **stack, int *x, int *y);
void	var_init(t_variables *var, int *is_valid, char **map, char *map_name);
int		path_find(char **tmp_map, t_stack *c_l, t_stack *p_l);
int		is_possible(char **map, char *map_name, int is_valid);
t_stack	*p_locate(char **map, char *map_name);
t_stack	*c_locate(char **map, char *map_name);
int		collectable_counter(char **map, char *map_name);
int		is_turnout(char **map, int x, int y);
char	**create_tmp_map(char *map_name);
void	ft_moveright(char ***map, int *x, int *y);
void	ft_moveleft(char ***map, int *x, int *y);
void	ft_moveup(char ***map, int *x, int *y);
void	ft_movedown(char ***map, int *x, int *y);

//!window and put img
int		c_counter(char **map, char *map_name);
int		e_counter(char **map, char *map_name);
void	data_init(t_data *data, char *map_name);
#endif