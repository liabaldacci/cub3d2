/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:02:01 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/19 18:30:35 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <sys/stat.h>

static void			little_endian_int(unsigned char *adr, unsigned int vl)
{
	adr[0] = (unsigned char)(vl);
	adr[1] = (unsigned char)(vl >> 8);
	adr[2] = (unsigned char)(vl >> 16);
	adr[3] = (unsigned char)(vl >> 24);
}

static int			store_color(t_vars *strct, int x, int y)
{
	unsigned int	color;
	unsigned char	addr_color[4];

	color = *(unsigned int *)(strct->addr + strct->win_w *
			(strct->win_h - y - 1) * 4 + x * 4);
	little_endian_int(&addr_color[0], color);
	return (*(unsigned int*)(addr_color));
}

static void			bmp_header(t_vars *strct, int fd)
{
	unsigned char	file[54];
	int				filesize;

	ft_bzero(&file, 54);
	filesize = 54 + strct->win_h * strct->win_w
				* strct->bits_per_pixel / 8;
	file[0] = (unsigned char)('B');
	file[1] = (unsigned char)('M');
	little_endian_int(&file[2], filesize);
	file[10] = (unsigned char)(54);
	file[14] = (unsigned char)(40);
	little_endian_int(&file[18], strct->win_w);
	little_endian_int(&file[22], strct->win_h);
	file[26] = (unsigned char)(1);
	file[28] = (unsigned char)(32);
	write(fd, &file, 54);
}

int					save_bmp_file(t_vars *strct)
{
	int				fd;
	int				bmp[strct->win_h][strct->win_w];
	int				x;
	int				y;

	if ((fd = open("photo.bmp", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR |
					S_IRGRP | S_IROTH, 777)) < 0)
		return (-1);
	bmp_header(strct, fd);
	y = 0;
	while (y < strct->win_h)
	{
		x = 0;
		while (x < strct->win_w)
		{
			bmp[y][x] = store_color(strct, x, y);
			write(fd, &bmp[y][x], 4);
			x++;
		}
		y++;
	}
	close(fd);
	return (0);
}
