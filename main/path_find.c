/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 22:53:09 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/08 22:25:13 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	no_way(t_stack **stack, int *x, int *y)
{
	t_stack	*tmp;

	tmp = ft_stack_pop(stack);
	*x = tmp->x;
	*y = tmp->y;
	free(tmp);
}

int	path_find(char **tmp_map, t_stack *c_l, t_stack *p_l)
{
	t_stack	*stack;

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
			no_way(&stack, &c_l->x, &c_l->y);
		if (c_l->x == p_l->x && c_l->y == p_l->y)
			return (1);
	}
	return (0);
}
//is valid always will be start from one.
int	is_possible(char **map, char *map_name, int is_valid)
{
	t_stack	*p_l;
	t_stack *c_l;
	char	**tmp_map;
	int		c_counter;

	c_counter = collectable_counter(map, map_name);
	p_l = p_locate(map, map_name);
	while (c_counter != 0)
	{
		tmp_map = create_tmp_map(map_name);
		c_l = c_locate(map, map_name);
		is_valid = path_find(tmp_map, c_l, p_l);
		free(tmp_map);
		if (is_valid == 1)
		{
			map[c_l->x][c_l->y] = '0';
			c_counter--;
		}
		else
			break;
	}
	if (c_counter > 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	char **map = read_map(argv[1]);
	char **tmp_map = create_tmp_map(argv[1]);
	//t_stack *c_l = c_locate(map, argv[1]);
	//t_stack *p_l = p_locate(map, argv[1]);
	//int deneme = path_find(tmp_map, c_l, p_l);
	int deneme = is_possible(map, argv[1], 1);
	printf("%d", deneme);
	(void)argc;
	(void)argv;
	return (0);
}
