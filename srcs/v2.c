void		ft_check_stuff(t_vars *strct, t_xy *xy, t_xy *xy2, t_xy *dxy)
{
	if (dxy->x < 0)
	{
		if (dxy->y > 0)
			strct->slope.slope_sign = -1;
		else
			strct->slope.slope_sign = 1;
		set_strct(strct, &xy, &xy2);
	}
	else
	{
		if (dxy->y > 0)
			strct->slope.slope_sign = 1;
		else
			strct->slope.slope_sign = -1;
		xy->x = strct->xy.x;
		xy->y = strct->xy.y;
	}
}