/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:26:21 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 19:01:52 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_input(t_vars *strct)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	fd = open(strct->map_path, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_eval_line(line, strct) == -1)
		{
			ft_close_free_gnl(fd, line);
			return (-1);
		}
		free(line);
	}
	if (ft_eval_line(line, strct) == -1)
	{
		ft_close_free_gnl(fd, line);
		return (-1);
	}
	ft_close_free_gnl(fd, line);
	strct->tile_x = strct->win_w / strct->map_width;
	strct->tile_y = strct->win_h / strct->map_height;
	rgb_maker(strct);
	return (0);
}

void	ft_count_sprites(t_vars *strct, char *line)
{
	int		i;
	int		len;

	i = 0;
	len = (ft_strlen(line));
	while (i < len)
	{
		if (line[i] == '2')
			strct->num_of_sprites++;
		i++;
	}
}

void	ft_eval_aux1(t_vars *strct, char *line)
{
	if (ft_strlen(line) > strct->map_width)
		strct->map_width = ft_strlen(line);
	strct->map_height++;
	ft_count_sprites(strct, line);
}

int		ft_eval_line(char *line, t_vars *strct)
{
	int		i;
	int		res;

	i = 0;
	res = ft_1(strct, line, i);
	if (strct->check != 0 && res != -1)
		res = ft_2(strct, line, i);
	if (strct->check != 0 && res != -1)
		res = ft_3(strct, line, i);
	if (strct->check != 0 && res != -1)
		res = ft_4(strct, line, i);
	if (strct->check != 0 && res != -1)
		res = ft_5(strct, line, i);
	else
	{
		ft_putendl_fd("Map is not valid", 1);
		return (-1);
	}
	if (res == -1)
		return (-1);
	return (1);
}
