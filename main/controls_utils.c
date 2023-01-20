/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:01:43 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/20 13:45:14 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_stack	*e_locate(char **map)
{
	t_stack	*rvalue;
	int		x_counter;
	int		y_counter;

	rvalue = (t_stack *)malloc(sizeof(t_stack));
	x_counter = 0;
	while (map[x_counter])
	{
		y_counter = 0;
		while (map[x_counter][y_counter] != '\0')
		{
			if (map[x_counter][y_counter] == 'E')
			{
				rvalue->x = x_counter;
				rvalue->y = y_counter;
				rvalue->next = NULL;
				return (rvalue);
			}
			y_counter++;
		}
		x_counter++;
	}
	return (NULL);
}

void	loc_init(int *x, int *y, t_stack *p, char direct)
{
	*x = p->x;
	*y = p->y;
	if (direct == 'u')
		*x = p->x - 1;
	else if (direct == 'd')
		*x = p->x + 1;
	else if (direct == 'l')
		*y = p->y - 1;
	else
		*y = p->y + 1;
}

void	put_exit(t_data *d, char **map, t_stack *p, char direct)
{
	int	x;
	int	y;

	loc_init(&x, &y, p, direct);
	mlx_put_image_to_window(d->m_p, d->w_p, d->e_img, p->y * 50, p->x * 50);
	mlx_put_image_to_window(d->m_p, d->w_p, d->p_img, y * 50, x * 50);
	map[p->x][p->y] = 'E';
	map[x][y] = 'P';
}
