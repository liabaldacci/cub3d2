/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 18:08:43 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:33:01 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_render(t_vars *strct)
{
	ft_black_screen(strct);
	cast_3d_rays(strct);
	ft_render_sprites(strct);
	ft_render_map(strct);
	ft_render_player(strct);
	cast_all_rays(strct);
	mlx_put_image_to_window(strct->mlx, strct->mlx_win, strct->img, 0, 0);
}

void	ft_render_save(t_vars *strct)
{
	ft_black_screen(strct);
	cast_3d_rays(strct);
	ft_render_sprites(strct);
	ft_render_map(strct);
	ft_render_player(strct);
	cast_all_rays(strct);
	save_bmp_file(strct);
	exit(0);
}

int		ft_update(t_vars *strct)
{
	ft_move(strct);
	return (0);
}

int		ft_game(t_vars *strct)
{
	ft_update(strct);
	ft_render(strct);
	return (0);
}
