/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:10:40 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:33:38 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			nbr_free(char **nbr)
{
	free(*nbr);
	return (-1);
}

void		set_xy_colors(t_vars *strct, int i, int wall_bottom_pixel)
{
	if (i == 1)
	{
		strct->color = strct->rgb_ceiling;
		strct->xy.x = strct->rays.column_id;
		strct->xy.y = 0;
	}
	else
	{
		strct->color = strct->rgb_floor;
		strct->xy.x = strct->rays.column_id;
		strct->xy.y = wall_bottom_pixel;
	}
}

void		ft_init_rays(t_vars *strct)
{
	strct->rays.num_of = strct->win_w;
	strct->wall_distances =
		(double *)ft_calloc(strct->rays.num_of * sizeof(double));
	strct->rays.size_of = strct->win_w / strct->player.fov_angle;
}
