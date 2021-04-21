/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gadoglio <gadoglio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:28:56 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 19:44:53 by gadoglio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_split_numbers(char *str, int i, char **width, char **height)
{
	int		len_height;
	int		len_width;
	int		j;

	len_height = 0;
	len_width = 0;
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	j = i;
	while (str[i++] != ' ' && str[i] != '\0')
		len_width++;
	*width = ft_substr(str, j, len_width);
	while (str[i] == ' ' && str[i] != '\0')
		i++;
	j = i;
	while (str[i++] != ' ' && str[i] != '\0')
		len_height++;
	*height = ft_substr(str, j, len_height + 1);
	return (0);
}

int		ft_validate_numbers(char *width, char *height)
{
	int		i;

	i = 0;
	while (width[i] != '\0')
	{
		if (ft_isdigit(width[i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (height[i] != '\0')
	{
		if (ft_isdigit(height[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
}

void	ft_free(char *width, char *height)
{
	free(height);
	free(width);
}

int		ft_resolution(char *str, t_vars *strct)
{
	int		screen_height;
	int		screen_width;
	char	*width;
	char	*height;
	int		i;

	i = 1;
	mlx_get_screen_size(strct->mlx, &screen_width, &screen_height);
	ft_split_numbers(str, i, &width, &height);
	if (ft_validate_numbers(width, height) == -1)
	{
		ft_free(width, height);
		return (-1);
	}
	strct->win_w = ft_atoi(width);
	strct->win_h = ft_atoi(height);
	if ((strct->win_w > screen_width)
		|| (strct->win_h > screen_height))
	{
		strct->win_w = screen_width;
		strct->win_h = screen_height;
	}
	ft_free(width, height);
	return (0);
}
