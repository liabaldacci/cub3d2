/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 12:10:40 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 16:55:21 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int			nbr_free(char **nbr)
{
	free(*nbr);
	return (-1);
}

void		set_xy_colors(t_vars *strct, int i, int wall_bottom_pixel)
{
	if (i == 1)
	{
		strct->color = strct->RGB_ceiling;
		strct->xy.x = strct->rays.column_id;
		strct->xy.y = 0;
	}
	else
	{
		strct->color = strct->RGB_floor;
		strct->xy.x = strct->rays.column_id;
		strct->xy.y = wall_bottom_pixel;
	}
}
