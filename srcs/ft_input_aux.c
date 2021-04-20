/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:38:26 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/20 01:37:17 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_1(t_vars *strct, char *line, int i)
{
	if ((line[i] == 'R') && line[i + 1] == ' ')
	{
		strct->check = 1;
		if (ft_resolution(line, strct) == -1)
			return (-1);
	}
	return (1);
}

int		ft_2(t_vars *strct, char *line, int i)
{
	if ((line[i] == 'F' || line[i] == 'C') && line[i + 1] == ' ')
	{
		strct->check = 1;
		if (ft_colors(line, strct) == -1)
			return (-1);
	}
	return (1);
}

int		ft_3(t_vars *strct, char *line, int i)
{
	if (((line[i] == 'N' || line[i] == 'S') && line[i + 1] == 'O'
		&& line[i + 2] == ' ') || (line[i] == 'W' && line[i + 1] == 'E' &&
		line[i + 2] == ' ') || (line[i] == 'E' && line[i + 1] == 'A' &&
		line[i + 2] == ' ') || (line[i] == 'S' && line[i + 1] == ' '))
	{
		strct->check = 1;
		if (ft_textures(line, strct) == -1)
			return (-1);
	}
	return (1);
}

int		ft_4(t_vars *strct, char *line, int i)
{
	if ((line[i] >= 8 && line[i] <= 13) || ft_strncmp(line, "\000", 5) == 0)
	{
		strct->check = 1;
		return (1);
	}
	return (1);
}

int		ft_5(t_vars *strct, char *line, int i)
{
	if (line[i] == ' ' || line[i] == '1')
	{
		strct->check = 1;
		if (ft_strchr(line, '1') != 0)
		{
			ft_eval_aux1(strct, line);
			return (0);
		}
	}
	return (1);
}
