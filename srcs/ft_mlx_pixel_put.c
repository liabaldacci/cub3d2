/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:50:18 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:31:48 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mlx_pixel_put(t_vars *strct, int x, int y, int color)
{
	char	*dst;

	dst = strct->addr + (y * strct->line_length + x *
		((strct->bits_per_pixel) / 8));
	*(unsigned int*)dst = color;
}
