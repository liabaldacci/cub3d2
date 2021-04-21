/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 19:26:21 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 20:10:27 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_eval_aux1(t_vars *strct, char *l, int i)
{
	if ((l[i] == 'R') && l[i + 1] == ' ')
	{
		if (ft_resolution(l, strct) == -1)
			return (-1);
		return (42);
	}
	if ((l[i] == 'F' || l[i] == 'C') && l[i + 1] == ' ')
	{
		if (ft_colors(l, strct) == -1)
			return (-1);
		return (42);
	}
	if (((l[i] == 'N' || l[i] == 'S') && l[i + 1] == 'O' && l[i + 2] == ' ')
		|| (l[i] == 'W' && l[i + 1] == 'E' && l[i + 2] == ' ')
		|| (l[i] == 'E' && l[i + 1] == 'A' && l[i + 2] == ' ')
		|| (l[i] == 'S' && l[i + 1] == ' '))
	{
		if (ft_textures(l, strct) == -1)
			return (-1);
		return (42);
	}
	return (0);
}

int		ft_eval_aux2(t_vars *strct, char *line, int i)
{
	if ((line[i] >= 8 && line[i] <= 13) || (ft_strncmp(line, "\000", 5) == 0))
		return (42);
	if (line[i] == ' ' || line[i] == '1')
	{
		if (strct->win_w != 0 && strct->color_id == 1 && strct->tex_id == 1)
			if (ft_strchr(line, '1') != 0)
			{
				if (ft_strlen(line) > strct->map_width)
					strct->map_width = ft_strlen(line);
				strct->map_height++;
				ft_count_sprites(strct, line);
				return (42);
			}
			else
				return (42);
		else
			return (-1);
	}
	return (0);
}

int		ft_eval_line(char *line, t_vars *strct)
{
	int	i;
	int	res;

	i = 0;
	res = ft_eval_aux1(strct, line, i);
	if (res == -1)
		return (-1);
	else if (res == 0)
		res = ft_eval_aux2(strct, line, i);
	if (res == 0)
	{
		ft_putendl_fd("Error!\nMap is not valid", 1);
		return (-1);
	}
	else if (res == -1)
	{
		ft_putendl_fd("Error!\nMap is not the last item in the config file", 1);
		return (-1);
	}
	return (0);
}
