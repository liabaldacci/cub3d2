/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 20:43:11 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:33:16 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double		ft_normalize_angle(double angle)
{
	double	remainder;

	if (angle > TWO_PI || angle < 0)
	{
		remainder = fmod(angle, TWO_PI);
		angle = (angle < 0) ? (TWO_PI + remainder) : remainder;
	}
	return (angle);
}

double		ft_distance_between_points(double x1, double y1,
				double x2, double y2)
{
	double	distance;

	distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	return (distance);
}

int			create_rgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void		rgb_maker(t_vars *strct)
{
	strct->rgb_ceiling = create_rgb(0,
		strct->r_ceiling, strct->g_ceiling, strct->b_ceiling);
	strct->rgb_floor = create_rgb(0,
		strct->r_floor, strct->g_floor, strct->b_floor);
}

void		calc_sprite(t_vars *strct, int i, double perp, double dis)
{
	strct->sprite[i].h = (strct->tile_y / perp) * dis;
	strct->sprite[i].w = (strct->tile_x / strct->sprite[i].dis) * dis;
	strct->sprite[i].top_y = (strct->win_h / 2) - (strct->sprite[i].h / 2);
	strct->sprite[i].top_y = (strct->sprite[i].top_y < 0) ?
		0 : strct->sprite[i].top_y;
	strct->sprite[i].bottom_y = (strct->win_h / 2) + (strct->sprite[i].h / 2);
	strct->sprite[i].bottom_y = (strct->sprite[i].bottom_y > strct->win_h) ?
		strct->win_h : strct->sprite[i].bottom_y;
}
