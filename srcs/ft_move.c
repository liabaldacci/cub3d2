/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 21:46:50 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/20 01:37:44 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_calc_new_xy(t_vars *strct, t_xy *newxy)
{
	double	move_step_x;
	double	move_step_y;

	if (strct->player.is_mov_right == 0)
	{
		strct->player.rotation_angle += strct->player.turn_direction
			* strct->player.turn_speed;
		move_step_x = strct->player.walk_direction * strct->player.walk_speed;
		newxy->x = strct->player.x + cos(strct->player.rotation_angle)
			* move_step_x;
		newxy->y = strct->player.y + sin(strct->player.rotation_angle)
			* move_step_x;
	}
	else
	{
		move_step_x = sin(strct->player.rotation_angle)
			* strct->player.walk_speed;
		move_step_y = -cos(strct->player.rotation_angle)
			* strct->player.walk_speed;
		newxy->x = strct->player.x + (move_step_x * strct->player.is_mov_right);
		newxy->y = strct->player.y + (move_step_y * strct->player.is_mov_right);
	}
	return (0);
}

int			ft_move(t_vars *strct)
{
	double	new_position;
	t_xy	newxy;

	ft_calc_new_xy(strct, &newxy);
	if (ft_has_wall_at(strct, newxy.x, newxy.y) == 0)
	{
		strct->player.x = newxy.x;
		strct->player.y = newxy.y;
	}
	return (0);
}

int			ft_has_wall_at(t_vars *strct, double x, double y)
{
	int		i;
	int		j;
	int		value;

	if (x < 0 || x + strct->player.width > strct->win_w
		|| y < 0 || y + strct->player.height > strct->win_h)
		return (1);
	i = floor(x / strct->tile_x);
	j = floor(y / strct->tile_y);
	value = strct->map[j][i] == '1';
	return (value);
}
