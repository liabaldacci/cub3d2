/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 19:51:29 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 16:48:12 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void		init_horz(t_dbxy *intercept, t_dbxy *step, t_dbxy *next_touch,
				t_vars *strct)
{
	intercept->y = (floor(strct->player.y / strct->tile_Y)) * strct->tile_Y;
	intercept->y += strct->rays.is_facing_down ? strct->tile_Y : 0;
	intercept->x = strct->player.x + ((intercept->y - strct->player.y)
		/ tan(strct->ray_angle));
	step->y = strct->tile_Y;
	step->y *= strct->rays.is_facing_up ? -1 : 1;
	step->x = strct->tile_Y / tan(strct->ray_angle);
	step->x *= (strct->rays.is_facing_left && step->x > 0) ? -1 : 1;
	step->x *= (strct->rays.is_facing_right && step->x < 0) ? -1 : 1;
	next_touch->x = intercept->x;
	next_touch->y = intercept->y;
}

int			ft_horz_while(t_dbxy *check, t_dbxy *next_touch, t_vars *strct,
				t_dbxy *step)
{
	check->x = next_touch->x;
	check->y = next_touch->y + (strct->rays.is_facing_up ? -1 : 0);
	if (ft_has_wall_at(strct, check->x, check->y))
	{
		strct->rays.horz_wall_hit_x = next_touch->x;
		strct->rays.horz_wall_hit_y = next_touch->y;
		return (1);
	}
	else
	{
		next_touch->x += step->x;
		next_touch->y += step->y;
	}
	return (0);
}

void		ft_horizontal_check(t_vars *strct, double ray_angle)
{
	t_dbxy	intercept;
	t_dbxy	step;
	t_dbxy	next_touch;
	t_dbxy	check;
	int		found_horizontal_wall_hit;

	found_horizontal_wall_hit = 0;
	strct->ray_angle = ray_angle;
	init_horz(&intercept, &step, &next_touch, strct);
	while (next_touch.x >= 0 && next_touch.x <= strct->win_w
			&& next_touch.y >= 0 && next_touch.y <= strct->win_h)
	{
		found_horizontal_wall_hit =
			ft_horz_while(&check, &next_touch, strct, &step);
		if (found_horizontal_wall_hit == 1)
			break ;
	}
	strct->rays.horz_hit_distance = (found_horizontal_wall_hit)
		? ft_distance_between_points(strct->player.x, strct->player.y,
		strct->rays.horz_wall_hit_x, strct->rays.horz_wall_hit_y) : 2147483646;
}

void		init_vert(t_dbxy *intercept, t_dbxy *step, t_dbxy *next_touch,
				t_vars *strct)
{
	intercept->x = (floor(strct->player.x / strct->tile_X)) * strct->tile_X;
	intercept->x += strct->rays.is_facing_right ? strct->tile_X : 0;
	intercept->y = strct->player.y + ((intercept->x - strct->player.x)
		* tan(strct->ray_angle));
	step->x = strct->tile_X;
	step->x *= strct->rays.is_facing_left ? -1 : 1;
	step->y = strct->tile_X * tan(strct->ray_angle);
	step->y *= (strct->rays.is_facing_up && step->y > 0) ? -1 : 1;
	step->y *= (strct->rays.is_facing_down && step->y < 0) ? -1 : 1;
	next_touch->x = intercept->x;
	next_touch->y = intercept->y;
}

int			ft_vert_while(t_dbxy *check, t_dbxy *next_touch, t_vars *strct,
				t_dbxy *step)
{
	check->x = next_touch->x + (strct->rays.is_facing_left ? -1 : 0);
	check->y = next_touch->y;
	if (ft_has_wall_at(strct, check->x, check->y))
	{
		strct->rays.vert_wall_hit_x = next_touch->x;
		strct->rays.vert_wall_hit_y = next_touch->y;
		return (1);
	}
	else
	{
		next_touch->x += step->x;
		next_touch->y += step->y;
	}
	return (0);
}
