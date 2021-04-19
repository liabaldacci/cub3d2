/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 20:00:22 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 11:29:27 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	key_press(int keycode, t_vars *strct)
{
	if (keycode == 65362 || keycode == 119)
		strct->player.walk_direction = 1;
	if (keycode == 65364 || keycode == 115)
		strct->player.walk_direction = -1;
	if (keycode == 65361)
		strct->player.turn_direction = -1;
	if (keycode == 65363)
		strct->player.turn_direction = 1;
	if (keycode == 100)
		strct->player.is_mov_right = -1;
	if (keycode == 97)
		strct->player.is_mov_right = 1;
	if (keycode == 65307)
	{
		mlx_destroy_window(strct->mlx, strct->mlx_win);
		close_program(strct);
	}
	return (0);
}

int	key_release(int keycode, t_vars *strct)
{
	if (keycode == 65362 || keycode == 119)
		strct->player.walk_direction = 0;
	if (keycode == 65364 || keycode == 115)
		strct->player.walk_direction = 0;
	if (keycode == 65361)
		strct->player.turn_direction = 0;
	if (keycode == 65363)
		strct->player.turn_direction = 0;
	if (keycode == 97 || keycode == 100)
		strct->player.is_mov_right = 0;
	return (0);
}
