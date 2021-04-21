/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:10:45 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 20:13:06 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_tex_pixel(t_vars *strct, int x, int y, int index)
{
	char		*color;

	color = (strct->tex[index].img) + (strct->tex[index].h * y *
			(strct->tex[index].bpp / 8)) + (x * (strct->tex[index].bpp / 8));
	if (color == 0)
		return (0);
	else
		return (*(int *)color);
}

int		ft_load_textures(t_vars *strct, int i)
{
	void	*mlx;
	char	*str;

	mlx = mlx_xpm_file_to_image(strct->mlx, strct->tex_path[i],
		&strct->tex[i].w, &strct->tex[i].h);
	if (!mlx)
	{
		ft_putendl_fd("Error!\nNo texture was loaded.", 1);
		return (-1);
	}
	str = mlx_get_data_addr(mlx, &strct->tex[i].bpp,
		&strct->tex[i].line_length, &strct->tex[i].endian);
	if (!str)
	{
		ft_putendl_fd("Error!\nInvalid textures.", 1);
		return (-1);
	}
	strct->tex[i].mlx = mlx;
	strct->tex[i].img = str;
	return (0);
}

void	ft_drtex(t_vars *strct, int top_p, int bot_p, int i)
{
	int		y;
	double	x_tex;
	double	y_tex;
	int		color;
	double	dis_from_top;

	y = top_p;
	if (strct->rays.was_hit_vertical == 1)
		x_tex = fmod(strct->rays.wall_hit_y, strct->tile_y) *
				(strct->tex[i].w / (double)strct->tile_y);
	else
		x_tex = fmod(strct->rays.wall_hit_x, strct->tile_x) *
				(strct->tex[i].w / (double)strct->tile_x);
	while (y <= bot_p)
	{
		dis_from_top = y + (strct->wallprojh / 2) - (strct->win_h / 2);
		y_tex = (dis_from_top * (strct->tex[i].h / strct->wallprojh));
		color = get_tex_pixel(strct, (int)x_tex, (int)y_tex, i);
		ft_mlx_pixel_put(strct, strct->rays.column_id, y, color);
		y++;
	}
}

void	ft_draw_sprite(t_vars *strct, int x, int i)
{
	int		y;
	int		c;
	int		x_tex;
	int		y_tex;
	double	texel_w;

	y = strct->sprite[i].top_y;
	texel_w = (strct->tex[4].w / strct->sprite[i].w);
	x_tex = (x - strct->sprite[i].left_x) * texel_w;
	while (y < strct->sprite[i].bottom_y)
	{
		if (x > 0 && x < strct->win_w)
		{
			texel_w = y + (strct->sprite[i].h / 2) - (strct->win_h / 2);
			y_tex = texel_w * (strct->tex[4].h / strct->sprite[i].h);
			c = get_tex_pixel(strct, (int)x_tex, (int)y_tex, 4);
			if ((strct->sprite[i].dis <
				(strct->wall_distances[x])) && c != 0x000000)
				ft_mlx_pixel_put(strct, x, y, c);
		}
		y++;
	}
}
