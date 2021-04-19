/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:55:00 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:31:38 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_get_direction(t_vars *strct)
{
	if (strct->player.direction == 'S')
		strct->player.rotation_angle = PI / 2;
	else if (strct->player.direction == 'W')
		strct->player.rotation_angle = PI;
	else if (strct->player.direction == 'N')
		strct->player.rotation_angle = (3 * PI) / 2;
	else if (strct->player.direction == 'E')
		strct->player.rotation_angle = 0;
	else
	{
		ft_putendl_fd("There is no player position.", 1);
		return (-1);
	}
	return (0);
}

int		ft_map_x(t_vars *strct, int i, int j)
{
	if (i != 0)
		if (!ft_strchr("1X", strct->map[i - 1][j]))
			return (-1);
	if (i != strct->map_height - 1)
		if (!ft_strchr("1X", strct->map[i + 1][j]))
			return (-1);
	if (j != 0)
		if (!ft_strchr("1X", strct->map[i][j - 1]))
			return (-1);
	if (j != strct->map_width - 1)
		if (!ft_strchr("1X", strct->map[i][j + 1]))
			return (-1);
	return (0);
}

int		ft_map_0(t_vars *strct, int i, int j)
{
	if (i == 0 || i == strct->map_height - 1 || j == 0 \
			|| j == strct->map_width - 1)
		return (-1);
	else
	{
		if (!ft_strchr("012NSWE", strct->map[i - 1][j]))
			return (-1);
		if (!ft_strchr("012NSWE", strct->map[i + 1][j]))
			return (-1);
		if (!ft_strchr("012NSWE", strct->map[i][j - 1]))
			return (-1);
		if (!ft_strchr("012NSWE", strct->map[i][j + 1]))
			return (-1);
	}
	return (0);
}

int		ft_map_is_valid(t_vars *strct)
{
	int		i;
	int		j;
	int		res;

	i = -1;
	j = 0;
	while (++i < strct->map_height)
	{
		while (++j < strct->map_width)
		{
			if (strct->map[i][j] == 'X')
			{
				if ((res = ft_map_x(strct, i, j)) == -1)
					return (-1);
			}
			else if (strct->map[i][j] == '0')
			{
				if ((res = ft_map_0(strct, i, j)) == -1)
					return (-1);
			}
		}
		j = 0;
	}
	return (0);
}

int		ft_map_aux1(char *str, int i)
{
	while (str[ft_strlen(str) - i] == ' ')
		i++;
	if (str[ft_strlen(str) - i] != '1')
		return (-1);
	return (1);
}
