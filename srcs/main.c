/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 19:28:38 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 18:57:19 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_init_main(t_vars *strct)
{
	int	i;

	i = -1;
	while (++i < 5)
		ft_load_textures(strct, i);
	ft_init_rays(strct);
	ft_init_image(strct);
	if (strct->save == 1)
		ft_render_save(strct);
	return (0);
}

int		main(int argc, char **argv)
{
	t_vars	strct;

	strct.mlx = mlx_init();
	ft_init_struct(&strct);
	if ((ft_check_args(&strct, argc, argv) < 0)
		|| (ft_check_input(&strct) < 0)
		|| ft_check_map(&strct) < 0)
	{
		close_program(&strct);
		return (-1);
	}
	ft_init_main(&strct);
	if (ft_init_window(&strct) == -1)
	{
		ft_putendl_fd("Error initializing window.", 1);
		close_program(&strct);
	}
	mlx_hook(strct.mlx_win, 2, 1L << 0, key_press, &strct);
	mlx_hook(strct.mlx_win, 3, 1L << 1, key_release, &strct);
	mlx_hook(strct.mlx_win, 33, 1L << 17, close_program, &strct);
	mlx_loop_hook(strct.mlx, ft_game, &strct);
	mlx_loop(strct.mlx);
	return (0);
}
