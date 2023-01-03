/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:53:09 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/03 15:23:39 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_to_p(char *map_name, char ***tmp_map, int c_x, int c_y)
{
	t_stack	**turnouts;

	*turnouts = ft_stack_new(c_x, c_y);
	while (turnouts != NULL)
	{
		if (is_turnout(tmp_map, c_x, c_y))
			ft_stack_push(&turnouts, ft_stack_new(c_x, c_y));
		if (tmp_map[c_x][c_y + 1] == 0)
			ft_moveright(tmp_map, &c_x, &c_y);
		else if (tmp_map[c_x][c_y - 1] == 0)
			ft_moveleft(tmp_map, &c_x, &c_y);
		else if (tmp_map[c_x + 1][c_y] == 0)	//KOD DENENMEDİ, KODU DENE
			ft_movedown(tmp_map, &c_x, &c_y);
		else if (tmp_map[c_x - 1][c_y] == 0)
			ft_moveup(tmp_map, &c_x, &c_y);
		else
			ft_stack_pop(turnouts);
		if (c_x == p_locate(read_map(map_name), map_name)->x
			&& c_y == p_locate(read_map(map_name), map_name)->y)
			return (1);
	}
	return (0);
}

int	path_find(char **map, char *map_name)
{
	return (0);
}

int	main(int argc, char *argv[])
{
	return (0);
}
