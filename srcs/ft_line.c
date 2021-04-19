/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 19:24:30 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 15:21:04 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			do_the_thing(t_vars *strct, t_xy *xy1, t_xy *xy2, t_xy *dxy)
{
	int		p;

	p = 0;
	while (xy1->y <= xy2->y)
	{
		ft_mlx_pixel_put(strct, xy1->x, xy1->y, strct->color);
		xy1->y++;
		if (p < 0)
			p += 2 * dxy->x;
		else
		{
			p += (2 * dxy->x) - (2 * dxy->y);
			xy1->x++;
		}
	}
	return (p);
}

void		ft_large_slope(t_vars *strct, int slope_sign, t_xy *xy1, t_xy *xy2)
{
	int		p;
	t_xy	dxy;

	dxy.x = xy2->x - xy1->x;
	dxy.y = abs(xy2->y - xy1->y);
	p = (2 * dxy.x) - dxy.y;
	if (xy1->y < xy2->y)
	{
		p = do_the_thing(strct, xy1, xy2, &dxy);
	}
	else
	{
		while (xy2->y <= xy1->y)
		{
			ft_mlx_pixel_put(strct, xy1->x, xy1->y, strct->color);
			xy1->y--;
			if (p < 0)
				p += 2 * dxy.x;
			else
			{
				p += (2 * dxy.x) - (2 * dxy.y);
				xy1->x++;
			}
		}
	}
}

void		ft_small_slope(t_vars *strct, int slope_sign, t_xy *xy1, t_xy *xy2)
{
	int		p;
	int		dx;
	int		dy;

	dx = xy2->x - xy1->x;
	dy = abs(xy2->y - xy1->y);
	p = (2 * dy) - dx;
	while (xy1->x <= xy2->x)
	{
		ft_mlx_pixel_put(strct, xy1->x, xy1->y, strct->color);
		xy1->x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += (2 * dy) - (2 * dx);
			xy1->y = (slope_sign == -1) ? xy1->y - 1 : xy1->y + 1;
		}
	}
}

int			ft_draw_line(t_vars *strct, int x2, int y2)
{
	t_xy	xy;
	t_xy	xy2;
	t_xy	dxy;

	xy2.x = x2;
	xy2.y = y2;
	dxy.x = x2 - strct->xy.x;
	dxy.y = xy2.y - strct->xy.y;
	if (dxy.x == 0)
		return (dx_0(strct, &xy, &xy2, &dxy));
	if (dxy.y == 0)
		return (dy_0(strct, &xy, &xy2, &dxy));
	strct->slope.slope = (abs(dxy.y) > abs(dxy.x)) ? 1 : 0;
	if (dxy.x < 0)
	{
		if (dxy.y > 0)
			strct->slope.slope_sign = -1;
		else
			strct->slope.slope_sign = 1;
		set_strct(strct, &xy, &xy2);
	}
	else
		calc_slope(strct, &dxy, &xy);
	draw(strct, &xy, &xy2);
	return (0);
}
