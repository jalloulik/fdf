/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 08:48:03 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:31:38 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			ft_assign_values_2d(t_2dp *point, double x, double y)
{
	point->x = x;
	point->y = y;
}

static void		ft_find_octant_west(t_pt *i, t_2dp a, t_2dp b)
{
	if (!(b.x > a.x))
	{
		if (b.y > a.y)
		{
			if ((b.y - a.y) < (a.x - b.x))
				i->octant = 3;
			else
				i->octant = 2;
		}
		else
		{
			if ((a.y - b.y) < (a.x - b.x))
				i->octant = 4;
			else
				i->octant = 5;
		}
	}
}

static void		ft_find_octant_east(t_pt *i, t_2dp a, t_2dp b)
{
	if (b.x > a.x)
	{
		if (b.y > a.y)
		{
			if ((b.y - a.y) < (b.x - a.x))
				i->octant = 0;
			else
				i->octant = 1;
		}
		else
		{
			if ((a.y - b.y) < (b.x - a.x))
				i->octant = 7;
			else
				i->octant = 6;
		}
	}
}

static t_pt		*ft_find_octant(double ax, double ay, double bx, double by)
{
	t_pt	*i;
	t_2dp	a;
	t_2dp	b;

	i = (t_pt*)malloc(sizeof(*i));
	if (i == NULL)
		exit(0);
	a.x = ax;
	a.y = ay;
	b.x = bx;
	b.y = by;
	ft_find_octant_east(i, a, b);
	ft_find_octant_west(i, a, b);
	return (i);
}

void			ft_draw_line_bres(t_2dp a, t_2dp b, t_winenv mlxenv, int color)
{
	t_2dp	d;
	double	diff;
	t_pt	*convert;

	convert = ft_find_octant(a.x, a.y, b.x, b.y);
	convert = ft_input_conver(convert, a.x, a.y);
	ft_assign_values_2d(&a, convert->xinput, convert->yinput);
	convert = ft_input_conver(convert, b.x, b.y);
	ft_assign_values_2d(&b, convert->xinput, convert->yinput);
	ft_assign_values_2d(&d, (b.x - a.x), (b.y - a.y));
	diff = 2 * d.y - d.x;
	while (a.x < b.x)
	{
		if (diff > 0)
		{
			a.y++;
			diff = diff - 2 * d.x;
		}
		convert = ft_output_conver(convert, a.x, a.y);
		ft_fill_img(mlxenv, mlxenv.lpad + (int)convert->xoutput,
							mlxenv.tpad + (int)convert->youtput, color);
		a.x++;
		diff = diff + 2 * d.y;
	}
	free(convert);
}
