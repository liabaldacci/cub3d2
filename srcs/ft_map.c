/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:07:08 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 20:10:44 by gadoglio         ###   ########.fr       */
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
		ft_putendl_fd("Error!\nThere is no player position.", 1);
		return (-1);
	}
	return (0);
}

int		ft_check_x(t_vars *strct, int i, int j)
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

int		ft_check_0(t_vars *strct, int i, int j)
{
	if (i == 0 || i == strct->map_height - 1 || j == 0
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
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < strct->map_height)
	{
		while (j < strct->map_width)
		{
			if (strct->map[i][j] == 'X')
			{
				if (ft_check_x(strct, i, j) < 0)
					return (-1);
			}
			else if (strct->map[i][j] == '0')
			{
				if (ft_check_0(strct, i, j) < 0)
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
