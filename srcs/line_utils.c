/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:10:10 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 16:11:52 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int		dx_0(t_vars *strct, t_xy *xy, t_xy *xy2, t_xy *dxy)
{
	if (dxy->y < 0)
	{
		xy->x = xy2->x;
		xy->y = xy2->y;
		xy2->x = strct->xy.x;
		xy2->y = strct->xy.y;
	}
	else
	{
		xy->x = strct->xy.x;
		xy->y = strct->xy.y;
	}
	while (xy->y < xy2->y)
	{
		ft_mlx_pixel_put(strct, xy->x, xy->y, strct->color);
		xy->y++;
	}
	return (0);
}

int		dy_0(t_vars *strct, t_xy *xy, t_xy *xy2, t_xy *dxy)
{
	if (dxy->x < 0)
	{
		xy->x = xy2->x;
		xy->y = xy2->y;
		xy2->x = strct->xy.x;
		xy2->y = strct->xy.y;
	}
	else
	{
		xy->x = strct->xy.x;
		xy->y = strct->xy.y;
	}
	while (xy->x < xy2->x)
	{
		ft_mlx_pixel_put(strct, xy->x, xy->y, strct->color);
		xy->x++;
	}
	return (0);
}

void	set_strct(t_vars *strct, t_xy *xy, t_xy *xy2)
{
	xy->x = xy2->x;
	xy->y = xy2->y;
	xy2->x = strct->xy.x;
	xy2->y = strct->xy.y;
}

void	calc_slope(t_vars *strct, t_xy *dxy, t_xy *xy)
{
	if (dxy->y > 0)
		strct->slope.slope_sign = 1;
	else
		strct->slope.slope_sign = -1;
	xy->x = strct->xy.x;
	xy->y = strct->xy.y;
}

void	draw(t_vars *strct, t_xy *xy, t_xy *xy2)
{
	if (strct->slope.slope == 1)
		ft_large_slope(strct, strct->slope.slope_sign, xy, xy2);
	else
		ft_small_slope(strct, strct->slope.slope_sign, xy, xy2);
}
