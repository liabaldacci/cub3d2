/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 21:43:31 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:30:44 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_all(t_vars *strct)
{
	int	i;

	i = 0;
	while (i++ < 5)
	{
		if (strct->tex_path[i] != NULL)
			free(strct->tex_path[i]);
	}
	free(strct->mlx);
}

int		close_program(t_vars *strct)
{
	ft_free_all(strct);
	exit(0);
	mlx_destroy_image(strct->mlx, strct->img);
	mlx_destroy_window(strct->mlx, strct->mlx_win);
	mlx_destroy_display(strct->mlx);
	return (1);
}
