/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 16:01:40 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 16:48:36 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			ft_which_texture(t_vars *strct, double ray_angle)
{
	int		i;

	if (strct->rays.is_facing_up)
	{
		if (strct->rays.was_hit_vertical == 1)
		{
			i = (strct->rays.is_facing_right) ? 2 : 3;
		}
		else
			i = 0;
	}
	else
	{
		if (strct->rays.was_hit_vertical == 1)
		{
			i = (strct->rays.is_facing_right) ? 2 : 3;
		}
		else
			i = 1;
	}
	return (i);
}

void		ft_distance_calc(t_vars *strct, double ray_angle)
{
	ft_horizontal_check(strct, ray_angle);
	ft_vertical_check(strct, ray_angle);
	strct->rays.wall_hit_x = (strct->rays.horz_hit_distance
		< strct->rays.vert_hit_distance)
		? strct->rays.horz_wall_hit_x : strct->rays.vert_wall_hit_x;
	strct->rays.wall_hit_y = (strct->rays.horz_hit_distance
		< strct->rays.vert_hit_distance)
		? strct->rays.horz_wall_hit_y : strct->rays.vert_wall_hit_y;
	strct->rays.distance = (strct->rays.horz_hit_distance
		< strct->rays.vert_hit_distance)
		? strct->rays.horz_hit_distance : strct->rays.vert_hit_distance;
	strct->rays.was_hit_vertical = (strct->rays.vert_hit_distance
		< strct->rays.horz_hit_distance);
	strct->wall_distances[strct->rays.column_id] = strct->rays.distance;
}

void		cast_all_rays(t_vars *strct)
{
	double	ray_angle;

	strct->rays.column_id = 0;
	strct->player.rotation_angle =
		ft_normalize_angle(strct->player.rotation_angle);
	ray_angle = strct->player.rotation_angle - (strct->player.fov_angle / 2);
	while (strct->rays.column_id < strct->rays.num_of)
	{
		ray_angle = ft_normalize_angle(ray_angle);
		strct->rays.is_facing_down = (ray_angle > 0) && (ray_angle < PI);
		strct->rays.is_facing_up = (strct->rays.is_facing_down == 0) ? 1 : 0;
		strct->rays.is_facing_right = (ray_angle < (PI / 2))
			|| (ray_angle > (1.5 * PI));
		strct->rays.is_facing_left = (strct->rays.is_facing_right == 0) ? 1 : 0;
		ft_distance_calc(strct, ray_angle);
		ray_angle += strct->player.fov_angle / strct->rays.num_of;
		strct->color = 0xCBC3E3;
		strct->xy.x = (strct->player.x + (strct->player.width / 2))
			* strct->minimap_scale;
		strct->xy.y = (strct->player.y + (strct->player.height / 2))
			* strct->minimap_scale;
		ft_draw_line(strct, (strct->rays.wall_hit_x * strct->minimap_scale),
			(strct->rays.wall_hit_y * strct->minimap_scale));
		strct->rays.column_id++;
	}
}

void		cast_3d_rays(t_vars *strct)
{
	double	ray_angle;

	strct->rays.column_id = 0;
	strct->player.rotation_angle =
		ft_normalize_angle(strct->player.rotation_angle);
	ray_angle = strct->player.rotation_angle - (strct->player.fov_angle / 2);
	while (strct->rays.column_id < strct->rays.num_of)
	{
		ray_angle = ft_normalize_angle(ray_angle);
		strct->rays.is_facing_down = (ray_angle > 0) && (ray_angle < PI);
		strct->rays.is_facing_up = (strct->rays.is_facing_down == 0) ? 1 : 0;
		strct->rays.is_facing_right = (ray_angle < (PI / 2))
			|| (ray_angle > (1.5 * PI));
		strct->rays.is_facing_left = (strct->rays.is_facing_right == 0) ? 1 : 0;
		ft_distance_calc(strct, ray_angle);
		ft_render_3d_rays(strct, ray_angle);
		ray_angle += strct->player.fov_angle / strct->rays.num_of;
		strct->rays.column_id++;
	}
}

void		ft_vertical_check(t_vars *strct, double ray_angle)
{
	t_dbxy	intercept;
	t_dbxy	step;
	t_dbxy	next_touch;
	t_dbxy	check;
	int		found_vertical_wall_hit;

	found_vertical_wall_hit = 0;
	strct->ray_angle = ray_angle;
	init_vert(&intercept, &step, &next_touch, strct);
	while (next_touch.x >= 0 && next_touch.x <= strct->win_w
			&& next_touch.y >= 0 && next_touch.y <= strct->win_h)
	{
		found_vertical_wall_hit =
			ft_vert_while(&check, &next_touch, strct, &step);
		if (found_vertical_wall_hit == 1)
			break ;
	}
	strct->rays.vert_hit_distance = (found_vertical_wall_hit)
		? ft_distance_between_points(strct->player.x, strct->player.y,
		strct->rays.vert_wall_hit_x, strct->rays.vert_wall_hit_y) : 2147483646;
}
