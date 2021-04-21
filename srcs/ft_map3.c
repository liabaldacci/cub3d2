/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:07:28 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 19:07:29 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_map_whileaux(t_vars *strct, char **line, int line_nbr, int fd)
{
	if (ft_strchr("NSWE\t\n\v\f\r", line[0][0]))
	{
		free(line[0]);
		return (2);
	}
	else if (line[0][0] == ' ' || line[0][0] == '1')
	{
		if (ft_strchr(line[0], '1') != 0)
		{
			if (ft_map(line[0], strct, line_nbr) < 0)
			{
				ft_putendl_fd("Map is not valid.", 1);
				free(line[0]);
				close(fd);
				return (-1);
			}
			return (3);
		}
	}
	free(line[0]);
	return (0);
}

int		ft_check_map_while(t_vars *strct, char **line, int line_nbr, int fd)
{
	int	res;

	while (get_next_line(fd, line) == 1)
	{
		res = ft_check_map_whileaux(strct, line, line_nbr, fd);
		if (res == 2)
			continue;
		else if (res == -1)
			return (-1);
		else if (res == 3)
		{
			line_nbr++;
			free(line[0]);
		}
	}
	return (line_nbr);
}

int		ft_check_map_final(t_vars *strct)
{
	if (ft_map_is_valid(strct) < 0)
	{
		ft_putendl_fd("Map is not valid.", 1);
		return (-1);
	}
	if (ft_get_direction(strct) == -1)
		return (-1);
	return (0);
}

int		ft_check_map(t_vars *strct)
{
	int		fd;
	char	*line;
	int		line_nbr;

	line_nbr = 0;
	line = NULL;
	fd = open(strct->map_path, O_RDONLY);
	strct->map = (char **)ft_calloc((strct->map_height + 1) * sizeof(char *));
	ft_init_sprites(strct);
	line_nbr = ft_check_map_while(strct, &line, line_nbr, fd);
	if (line_nbr < 0)
		return (-1);
	if (ft_strchr(line, '1') != 0)
	{
		ft_map(line, strct, line_nbr);
		line_nbr++;
	}
	close(fd);
	free(line);
	if (ft_check_map_final(strct) < 0)
		return (-1);
	return (0);
}
