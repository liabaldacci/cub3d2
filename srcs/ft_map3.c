/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:55:19 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:31:43 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_map_aux2(t_vars *strct, int line_nbr, int i)
{
	strct->sprite[strct->sprite_id].x = i * strct->tile_x;
	strct->sprite[strct->sprite_id].y = line_nbr * strct->tile_y;
	strct->sprite_id++;
}

void	ft_map_aux3(t_vars *strct, char *str, int line_nbr, int i)
{
	strct->player.x = ((i * strct->tile_x) + (strct->tile_x / 2));
	strct->player.y = ((line_nbr * strct->tile_y) + (strct->tile_y / 2));
	strct->player.direction = str[i];
}

char	*ft_map_aux4(t_vars *strct, char *temp, char *str, int i)
{
	if (strct->map_width > ft_strlen(str))
	{
		while (i++ < strct->map_width)
			temp[i - 1] = 'X';
	}
	return (temp);
}

int		ft_map_aux5(t_vars *strct, char *temp, char *str, int line_nbr)
{
	if (ft_strchr(" \t\n\v\f\r", str[strct->counter]))
		temp[strct->counter] = 'X';
	else if (ft_strchr("2", str[strct->counter]))
	{
		temp[strct->counter] = str[strct->counter];
		ft_map_aux2(strct, line_nbr, strct->counter);
	}
	else if (ft_strchr("NSWE", str[strct->counter]))
	{
		if (strct->player.x != 0 || strct->player.y != 0)
		{
			ft_putendl_fd("Player position is invalid.", 1);
			free(temp);
			return (-1);
		}
		ft_map_aux3(strct, str, line_nbr, strct->counter);
		temp[strct->counter] = '0';
	}
	else if (ft_strchr("012", str[strct->counter]))
		temp[strct->counter] = str[strct->counter];
	else
		return (-1);
	return (1);
}

int		ft_map(char *str, t_vars *strct, int line_nbr)
{
	int		i;
	char	*temp;
	int		res;

	i = 1;
	res = ft_map_aux1(str, i);
	i = -1;
	temp = ft_calloc((strct->map_width + 1) * sizeof(char));
	while (str[++i] != '\0' && ft_strchr("012NSWE \t\n\v\f\r", str[i]))
	{
		strct->counter = i;
		res = ft_map_aux5(strct, temp, str, line_nbr);
	}
	strct->map[line_nbr] = ft_map_aux4(strct, temp, str, i);
	if (res == -1)
		return (-1);
	return (1);
}
