/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:55:00 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 20:57:16 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_while_aux(t_vars *strct, int line_nbr)
{
	strct->sprite[strct->sprite_id].x = strct->ctr * strct->tile_x;
	strct->sprite[strct->sprite_id].y = line_nbr * strct->tile_y;
	strct->sprite_id++;
}

int		ft_map_while(t_vars *strct, char **temp, char *str, int line_nbr)
{
	if (ft_strchr(" \t\n\v\f\r", str[strct->ctr]))
		temp[0][strct->ctr] = 'X';
	else if (ft_strchr("2", str[strct->ctr]))
	{
		temp[0][strct->ctr] = str[strct->ctr];
		ft_while_aux(strct, line_nbr);
	}
	else if (ft_strchr("NSWE", str[strct->ctr]))
	{
		if (strct->player.x != 0 || strct->player.y != 0)
		{
			ft_putendl_fd("Player position is invalid.", 1);
			free(temp[0]);
			return (-1);
		}
		strct->player.x = ((strct->ctr * strct->tile_x) + (strct->tile_x / 2));
		strct->player.y = ((line_nbr * strct->tile_y) + (strct->tile_y / 2));
		strct->player.direction = str[strct->ctr];
		temp[0][strct->ctr] = '0';
	}
	else if (ft_strchr("012", str[strct->ctr]))
		temp[0][strct->ctr] = str[strct->ctr];
	else
		return (-1);
	return (0);
}

void	ft_map_final(t_vars *strct, char **temp, char *str, int i)
{
	if (strct->map_width > ft_strlen(str))
	{
		while (i < strct->map_width)
		{
			temp[0][i] = 'X';
			i++;
		}
	}
}

int		ft_map(char *str, t_vars *strct, int line_nbr)
{
	int		i;
	char	*temp;

	i = 1;
	strct->ctr = 0;
	while (str[ft_strlen(str) - i] == ' ')
		i++;
	if (str[ft_strlen(str) - i] != '1')
		return (-1);
	i = 0;
	temp = ft_calloc((strct->map_width + 1) * sizeof(char));
	while (str[i] != '\0' && ft_strchr("012NSWE \t\n\v\f\r", str[i]))
	{
		strct->ctr = i;
		if (ft_map_while(strct, &temp, str, line_nbr) < 0)
			return (-1);
		i++;
	}
	ft_map_final(strct, &temp, str, i);
	strct->map[line_nbr] = temp;
	return (1);
}
