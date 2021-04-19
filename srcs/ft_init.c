/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:03:34 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:31:05 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_zero(t_vars *strct)
{
	strct->player.walk_speed = 10;
	strct->map_height = 0;
	strct->map_width = 0;
	strct->save = 0;
	strct->left = 0;
	strct->right = 0;
	strct->up = 0;
	strct->down = 0;
	strct->tile_x = 0;
	strct->tile_y = 0;
	strct->num_of_sprites = 0;
	strct->sprite_id = 0;
}

void	ft_init_struct(t_vars *strct)
{
	int	i;

	i = -1;
	strct->rays = (t_rays){0};
	strct->player = (t_player){0};
	strct->xy = (t_xy){0};
	strct->slope = (t_slope){0};
	strct->window_title = "Hello world!";
	strct->player.width = 5;
	strct->player.height = 5;
	ft_init_zero(strct);
	strct->minimap_scale = 0.3;
	strct->player.turn_speed = 4 * (PI / 180);
	strct->player.fov_angle = 60 * (PI / 180);
	strct->tex = (t_textures *)ft_calloc(5 * sizeof(t_textures));
	while (++i < 5)
		strct->tex_path[i] = NULL;
}

int		ft_init_image(t_vars *strct)
{
	strct->img = mlx_new_image(strct->mlx, strct->win_w,
			strct->win_h);
	strct->addr = mlx_get_data_addr(strct->img, &strct->bits_per_pixel,
			&strct->line_length, &strct->endian);
	return (0);
}

int		ft_init_window(t_vars *strct)
{
	strct->mlx_win = mlx_new_window(strct->mlx, strct->win_w,
		strct->win_h, strct->window_title);
	if (!strct->mlx_win)
	{
		ft_putendl_fd("Error initializing strct.", 1);
		return (-1);
	}
	return (0);
}

void	ft_init_sprites(t_vars *strct)
{
	int	i;

	i = -1;
	strct->sprite =
		(t_sprites *)ft_calloc(strct->num_of_sprites * sizeof(t_sprites));
	while (++i < strct->num_of_sprites)
		strct->sprite[i] = (t_sprites){0};
}
