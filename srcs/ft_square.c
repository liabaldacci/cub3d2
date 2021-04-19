/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:59:03 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:32:23 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_black_screen(t_vars *strct)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < strct->win_w)
	{
		while (j < strct->win_h)
		{
			ft_mlx_pixel_put(strct, i, j, 0x00000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_square(t_vars *strct, int h, int w)
{
	int x_temp;
	int y_temp;

	x_temp = strct->xy.x;
	y_temp = strct->xy.y;
	while (strct->xy.y < (h + y_temp))
	{
		while (strct->xy.x < (w + x_temp))
		{
			ft_mlx_pixel_put(strct, strct->xy.x, strct->xy.y,
				strct->color);
			strct->xy.x++;
		}
		strct->xy.x = x_temp;
		strct->xy.y++;
	}
}
