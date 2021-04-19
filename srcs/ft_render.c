/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 15:35:13 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:32:07 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_render_column(t_vars *strct, int i)
{
	int		j;
	int		tile_x_position;
	int		tile_y_position;

	j = 0;
	while (j < strct->map_width)
	{
		tile_x_position = j * strct->tile_x;
		tile_y_position = i * strct->tile_y;
		if (strct->map[i][j] == '1' || strct->map[i][j] == 'X')
			strct->color = 0x00000000;
		else if (strct->map[i][j] == '2')
			strct->color = 0xFF0000;
		else
			strct->color = 0xFFFFFF;
		strct->xy.x = tile_x_position * strct->minimap_scale;
		strct->xy.y = tile_y_position * strct->minimap_scale;
		ft_square(strct, (strct->tile_y * strct->minimap_scale),
			(strct->tile_x * strct->minimap_scale));
		j++;
	}
	j = 0;
}

int			ft_render_map(t_vars *strct)
{
	int		i;
	int		tile_color;

	i = 0;
	while (i < strct->map_height)
	{
		ft_render_column(strct, i);
		i++;
	}
	return (0);
}

int			ft_render_player(t_vars *strct)
{
	int		color;

	color = 0x0000FF;
	strct->xy.x = strct->player.x * strct->minimap_scale;
	strct->xy.y = strct->player.y * strct->minimap_scale;
	ft_square(strct, (strct->player.width * strct->minimap_scale),
			(strct->player.height * strct->minimap_scale));
	return (0);
}

void		ft_render_2d_rays(t_vars *strct)
{
	strct->xy.x = (strct->player.x + (strct->player.width / 2))
		* strct->minimap_scale;
	strct->xy.y = (strct->player.y + (strct->player.height / 2))
		* strct->minimap_scale;
	ft_draw_line(strct, (strct->rays.wall_hit_x * strct->minimap_scale),
		(strct->rays.wall_hit_y * strct->minimap_scale));
}

void		ft_render_3d_rays(t_vars *strct, double ray_angle)
{
	double	distance_proj_plane;
	int		wall_top_pixel;
	int		wall_bottom_pixel;
	int		i;

	distance_proj_plane = (strct->win_w / 2)
		/ tan(strct->player.fov_angle / 2);
	strct->wallprojh = (strct->tile_y / (strct->rays.distance
		* cos(ray_angle - strct->player.rotation_angle)))
		* distance_proj_plane;
	wall_top_pixel = (strct->win_h / 2) - (strct->wallprojh / 2);
	wall_top_pixel = (wall_top_pixel <= 0) ? 1 : wall_top_pixel;
	wall_bottom_pixel = (strct->win_h / 2) + (strct->wallprojh / 2);
	wall_bottom_pixel = (wall_bottom_pixel >= strct->win_h)
		? strct->win_h - 1 : wall_bottom_pixel;
	i = ft_which_texture(strct, ray_angle);
	set_xy_colors(strct, 1, wall_bottom_pixel);
	ft_draw_line(strct, strct->rays.column_id,
		wall_top_pixel);
	ft_drtex(strct, wall_top_pixel, wall_bottom_pixel, i);
	set_xy_colors(strct, 2, wall_bottom_pixel);
	ft_draw_line(strct, strct->rays.column_id,
		strct->win_h - 1);
}
