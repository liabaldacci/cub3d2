/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:06:52 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 20:10:08 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_close_free_gnl(char **line, int fd)
{
	close(fd);
	free(line[0]);
}

int		check_fd(t_vars *strct)
{
	int	fd;

	if ((fd = open(strct->map_path, O_RDONLY)) < 0)
		ft_putendl_fd("Error\nInvalid path to map.", 1);
	return (fd);
}

int		ft_check_input(t_vars *strct)
{
	int		fd;
	char	*line;
	int		i;

	line = NULL;
	if ((fd = check_fd(strct)) < 0)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_eval_line(line, strct) == -1)
		{
			ft_close_free_gnl(&line, fd);
			return (-1);
		}
		free(line);
	}
	if (ft_eval_line(line, strct) == -1)
	{
		ft_close_free_gnl(&line, fd);
		return (-1);
	}
	ft_close_free_gnl(&line, fd);
	ft_init_tiles(strct);
	rgb_maker(strct);
	return (0);
}

void	ft_count_sprites(t_vars *strct, char *line)
{
	int		i;
	int		len;

	i = 0;
	len = (ft_strlen(line));
	while (i < len)
	{
		if (line[i] == '2')
			strct->num_of_sprites++;
		i++;
	}
}
