/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:18:26 by yciftci           #+#    #+#             */
/*   Updated: 2023/01/20 02:25:39 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_data *d, char **map, int i, int j)
{
	int	w;
	int	h;

	while (map[i] != NULL)
	{
		h = i * 50;
		j = 0;
		while (map[i][j] != '\0')
		{
			w = j * 50;
			if (map[i][j] == '1')
				mlx_put_image_to_window(d->m_p, d->w_p, d->w_img, w, h);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(d->m_p, d->w_p, d->bg_img, w, h);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(d->m_p, d->w_p, d->p_img, w, h);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(d->m_p, d->w_p, d->e_img, w, h);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(d->m_p, d->w_p, d->c_img, w, h);
			j++;
		}
		i++;
	}
}
