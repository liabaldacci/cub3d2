/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 19:47:10 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:31:33 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_first_if(t_vars *strct, char *line, int line_nbr, int fd)
{
	if (ft_strchr(line, '1') != 0)
	{
		if (ft_map(line, strct, line_nbr) < 0)
		{
			ft_putendl_fd("Map is not valid.", 1);
			free(line);
			close(fd);
			return (-1);
		}
		line_nbr++;
	}
	return (line_nbr);
}

int		ft_map_and_dir(t_vars *strct)
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

void	ft_close_free_gnl(int fd, char *line)
{
	close(fd);
	free(line);
}

int		ft_last_line(t_vars *strct, char *line, int fd, int line_nbr)
{
	if (ft_strchr(line, '1') != 0 && (ft_map(line, strct, line_nbr) < 0))
	{
		ft_putendl_fd("Map is not valid.", 1);
		ft_close_free_gnl(fd, line);
		return (-1);
	}
	ft_close_free_gnl(fd, line);
	return (ft_map_and_dir(strct));
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
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strchr("NSWE\t\n\v\f\r", line[0]))
		{
			free(line);
			continue;
		}
		else if (line[0] == ' ' || line[0] == '1')
		{
			line_nbr = ft_first_if(strct, line, line_nbr, fd);
		}
		free(line);
	}
	return (ft_last_line(strct, line, fd, line_nbr));
}
