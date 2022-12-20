/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yciftci <yciftci@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 22:34:51 by yciftci           #+#    #+#             */
/*   Updated: 2022/12/20 01:28:45 by yciftci          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_modify_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	map_x_len(void)
{
	int		ctrl;
	char	*tmp;
	int		len;

	len = 0;
	tmp = NULL;
	ctrl = open("map.ber", O_RDONLY);
	if (!tmp)
	{
		tmp = get_next_line(ctrl);
		if (tmp)
			len++;
	}
	while (tmp)
	{
		tmp = get_next_line(ctrl);
		if (tmp)
			len++;
	}

	close(ctrl);
	free (tmp);
	return (len);
}

char	**read_map(void)
{
	char	**map;
	int		x_len;
	int		i;
	int		fd;

	i = 0;
	x_len = map_x_len();
	map = (char **)malloc(sizeof(char *) * (map_x_len() + 1));
	fd = open("map.ber", O_RDONLY);
	while (i < x_len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	first_last_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] == '1')
		i++;
	if (line[i] == '\n')
		return (1);
	if (line[i] == '\0')
		return (1);
	return (0);
}

int	normal_line(char *line)
{
	size_t	len;

	len = ft_modify_strlen(line) - 1;
	if (line[0] == '1' && line[len] == '1')
		return (1);
	return (0);
}