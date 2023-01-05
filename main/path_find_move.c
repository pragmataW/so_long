/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_find_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:39:12 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/05 22:56:40 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "../libs/libft/libft.h"

void	ft_moveright(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x][*y + 1] = 'C';
	else
		(*map)[*x][*y + 1] = 'E';
	(*map)[*x][*y] = '1';
	(void)*y++;
}

void	ft_moveleft(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x][*y - 1] = 'C';
	else
		(*map)[*x][*y - 1] = 'E';
	(*map)[*x][*y] = '1';
	(void)*y--;
}

void	ft_moveup(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x - 1][*y] = 'C';
	else
		(*map)[*x - 1][*y] = 'E';
	(*map)[*x][*y] = '1';
	(void)*x--;
}

void	ft_movedown(char ***map, int *x, int *y)
{
	if ((*map)[*x][*y] == 'C')
		(*map)[*x + 1][*y] = 'C';
	else
		(*map)[*x + 1][*y] = 'E';
	(*map)[*x][*y] = '1';
	(void)*x++;
}
