/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:38:38 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 09:09:30 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/libft/libft.h"

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	**read_map(void);
int		map_x_len(void);
size_t	ft_modify_strlen(const char *s);
int     is_wall(char **map);
int     first_last_line(char *line);
int     normal_line(char *line);
int     map_control(char *map_name);
int     is_ber(char *map_name);

#endif