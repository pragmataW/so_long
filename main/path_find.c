/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:53:09 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/06 13:11:50 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	go_to_p(char **tmp_map, t_stack *c_l, t_stack *p_l, char *map_name)
{
	t_stack	*stack;
	t_stack	*tmp;

	stack = ft_stack_new(c_l->x, c_l->y);
	while (stack != NULL)
	{
		if (is_turnout(tmp_map, c_l->x, c_l->y) > 1)
			ft_stack_push(&stack, ft_stack_new(c_l->x, c_l->y));
		if (tmp_map[c_l->x][c_l->y + 1] == '0')
			ft_moveright(&tmp_map, &c_l->x, &c_l->y);
		else if (tmp_map[c_l->x][c_l->y - 1] == '0')
			ft_moveleft(&tmp_map, &c_l->x, &c_l->y);
		else if (tmp_map[c_l->x + 1][c_l->y] == '0')
			ft_movedown(&tmp_map, &c_l->x, &c_l->y);
		else if (tmp_map[c_l->x - 1][c_l->y] == '0')
			ft_moveup(&tmp_map, &c_l->x, &c_l->y);
		else
		{
			tmp = ft_stack_pop(&stack);
			c_l->x = tmp->x;
			c_l->y = tmp->y;
		}
		if (c_l->x == p_l->x && c_l->y == p_l->y)
			return (1);
	}
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
	c_l = c_locate(map, map_name);
	while (c_l != NULL && is_find_p)
	{
		is_find_p = go_to_p(tmp_map, c_l, p_l, map_name);
		map[c_l->x][c_l->y] = '0';
		if (is_find_p)
			c_cntr--;
		free(c_l);
		c_l = c_locate(map, map_name);
	}
	free(p_l);
	free(c_l);
	free(tmp_map);
	if (c_cntr == 0 || c_l == NULL)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	char **map = read_map(argv[1]);
	char **tmp_map = create_tmp_map(argv[1]);
	t_stack *c_l = c_locate(map, argv[1]);
	t_stack *p_l = p_locate(map, argv[1]);
	int deneme = go_to_p(tmp_map, c_l, p_l, argv[1]);
	printf("%d", deneme);
	(void)argc;
	(void)argv;
	return (0);
}
