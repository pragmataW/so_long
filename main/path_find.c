/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:53:09 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/06 10:13:23 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_to_p(char *map_name, char **tmp_map, t_stack *c_l, t_stack *p_l)
{
	t_stack	*stack;

	stack = ft_stack_new(c_l->x, c_l->y);
	return (0);
}

int	path_find(char **map, char *map_name, int is_find_p)
{
	char	**tmp_map;
	int		c_cntr;
	t_stack	*c_l;
	t_stack	*p_l;

	c_cntr = collectable_counter(map, map_name);
	tmp_map = create_tmp_map(map_name);
	p_l = p_locate(map, map_name);
	while (c_l != NULL && is_find_p)
	{
		c_l = c_locate(map, map_name);
		is_find_p = go_to_p(map_name, tmp_map, c_l, p_l);
		if (c_l != NULL)
			map[c_l->x][c_l->y] = '0';
		if (is_find_p)
			c_cntr--;
		free(c_l);
	}
	free(p_l);
	free(tmp_map);
	if (c_cntr == 0 || c_l == NULL)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	return (0);
}
