/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:46:36 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 16:26:02 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc > 2)
	{
		ft_putstr_fd("Too many argument", 2);
		return (0);
	}
	else if (argc < 2)
	{
		ft_putstr_fd("Too few argument", 2);
		return (0);
	}
	map = read_map(argv[1]);
	ft_printf("%d", is_rectangular(map, argv[1]));
	return (0);
}
