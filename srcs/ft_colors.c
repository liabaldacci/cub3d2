/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfranco- <nfranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:46:53 by gadoglio          #+#    #+#             */
/*   Updated: 2021/04/21 21:45:08 by nfranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int			ft_split_number(char *str, int i, char **number)
{
	int		len_number;
	int		j;

	len_number = 0;
	while ((str[i] == ' ' || str[i] == ',') && str[i] != '\0')
		i++;
	j = i;
	while ((str[i++] != ' ' && str[i] != ',') && str[i] != '\0')
		len_number++;
	*number = ft_substr(str, j, len_number + 1);
	return (i);
}

int			ft_validate_number(char *number)
{
	int		i;

	i = 0;
	while (number[i] != '\0')
	{
		if (ft_isdigit(number[i]) == 0)
		{
			ft_putendl_fd("One of the colors is not in a valid number format."
				, 1);
			return (-1);
		}
		i++;
	}
	return (0);
}

int			ft_color_check(int c)
{
	if (c < 0 || c > 255)
	{
		ft_putendl_fd("Error in map configurations, color does not exist.", 1);
		return (-1);
	}
	return (0);
}

void		set_colors(t_vars *strct, int nbr, int rgb, char *str)
{
	if (str[0] == 'C')
	{
		if (rgb == 0)
			strct->r_ceiling = nbr;
		else if (rgb == 1)
			strct->g_ceiling = nbr;
		else if (rgb == 2)
			strct->b_ceiling = nbr;
	}
	else
	{
		if (rgb == 0)
			strct->r_floor = nbr;
		else if (rgb == 1)
			strct->g_floor = nbr;
		else if (rgb == 2)
			strct->b_floor = nbr;
	}
	strct->color_id = 1;
}

int			ft_colors(char *str, t_vars *strct)
{
	char	*number;
	int		nbr;
	int		i;
	int		rgb;

	i = 1;
	rgb = 0;
	while (rgb < 3)
	{
		i = ft_split_number(str, i, &number);
		if (ft_validate_number(number) < 0)
			return (nbr_free(&number));
		nbr = ft_atoi(number);
		if (ft_color_check(nbr) < 0)
			return (nbr_free(&number));
		set_colors(strct, nbr, rgb, str);
		rgb++;
		free(number);
	}
	return (0);
}
