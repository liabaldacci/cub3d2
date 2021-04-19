/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:13:39 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:33:30 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double			ft_calc_angle(t_vars *strct, int i)
{
	double	angle;
	double	j;

	angle = atan2(strct->sprite[i].y - strct->player.y,
		strct->sprite[i].x - strct->player.x) - strct->player.rotation_angle;
	if (angle > PI)
		angle -= TWO_PI;
	if (angle < -PI)
		angle += TWO_PI;
	angle = fabs(angle);
	return (angle);
}

void			ft_calc_distance(t_vars *strct, double angl_sprt_plyr, int i)
{
	double		epsilon;

	epsilon = 0.2;
	strct->sprite[i].dis =
			ft_distance_between_points(strct->sprite[i].x, strct->sprite[i].y,
			strct->player.x, strct->player.y);
	if (angl_sprt_plyr < ((strct->player.fov_angle / 2) + epsilon))
	{
		strct->sprite[i].is_visible = 1;
		strct->sprite[i].angle = angl_sprt_plyr;
		strct->sprite[i].dis =
			ft_distance_between_points(strct->sprite[i].x, strct->sprite[i].y,
			strct->player.x, strct->player.y);
	}
	else
		strct->sprite[i].is_visible = 0;
}

void			ft_sort_sprites(t_vars *strct)
{
	int			i;
	int			j;
	t_sprites	temp;

	i = 0;
	while (i < strct->num_of_sprites)
	{
		j = i + 1;
		while (j < strct->num_of_sprites)
		{
			if (strct->sprite[i].dis < strct->sprite[j].dis)
			{
				temp = strct->sprite[i];
				strct->sprite[i] = strct->sprite[j];
				strct->sprite[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void			ft_render_single_sprite(t_vars *strct, int i)
{
	double	d_proj;
	double	screen_pos_x;
	int		x;
	double	angle;
	double	perp_distance;

	d_proj = (strct->win_w / 2)
		/ tan(strct->player.fov_angle / 2);
	perp_distance = strct->sprite[i].dis * cos(strct->sprite[i].angle);
	calc_sprite(strct, i, perp_distance, d_proj);
	angle = atan2(strct->sprite[i].y - strct->player.y,
		strct->sprite[i].x - strct->player.x);
	angle = atan2(strct->sprite[i].y - strct->player.y,
		strct->sprite[i].x - strct->player.x) - strct->player.rotation_angle;
	screen_pos_x = tan(angle) * d_proj;
	strct->sprite[i].left_x = (strct->win_w / 2) + screen_pos_x;
	strct->sprite[i].right_x = strct->sprite[i].left_x + strct->sprite[i].w;
	x = strct->sprite[i].left_x;
	while (x < strct->sprite[i].right_x)
	{
		x++;
		ft_draw_sprite(strct, x - 1, i);
	}
}

void			ft_render_sprites(t_vars *strct)
{
	int			i;
	double		angle_sprite_player;

	i = 0;
	while (i < strct->num_of_sprites)
	{
		angle_sprite_player = ft_calc_angle(strct, i);
		ft_calc_distance(strct, angle_sprite_player, i);
		i++;
	}
	i = 0;
	ft_sort_sprites(strct);
	while (i < strct->num_of_sprites)
	{
		if (strct->sprite[i].is_visible == 1)
		{
			ft_render_single_sprite(strct, i);
		}
		i++;
	}
}
