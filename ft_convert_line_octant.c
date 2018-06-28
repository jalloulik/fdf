/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_line_octant.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:46:22 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:31:10 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_assign_values_input(t_pt *i, double x, double y)
{
	i->xinput = x;
	i->yinput = y;
}

static void	ft_assign_values_output(t_pt *i, double x, double y)
{
	i->xoutput = x;
	i->youtput = y;
}

t_pt		*ft_input_conver(t_pt *i, double x, double y)
{
	if (i->octant == 0)
		ft_assign_values_input(i, x, y);
	else if (i->octant == 1)
		ft_assign_values_input(i, y, x);
	else if (i->octant == 2)
		ft_assign_values_input(i, y, -x);
	else if (i->octant == 3)
		ft_assign_values_input(i, -x, y);
	else if (i->octant == 4)
		ft_assign_values_input(i, -x, -y);
	else if (i->octant == 5)
		ft_assign_values_input(i, -y, -x);
	else if (i->octant == 6)
		ft_assign_values_input(i, -y, x);
	else if (i->octant == 7)
		ft_assign_values_input(i, x, -y);
	return (i);
}

t_pt		*ft_output_conver(t_pt *i, double x, double y)
{
	if (i->octant == 0)
		ft_assign_values_output(i, x, y);
	else if (i->octant == 1)
		ft_assign_values_output(i, y, x);
	else if (i->octant == 2)
		ft_assign_values_output(i, -y, x);
	else if (i->octant == 3)
		ft_assign_values_output(i, -x, y);
	else if (i->octant == 4)
		ft_assign_values_output(i, -x, -y);
	else if (i->octant == 5)
		ft_assign_values_output(i, -y, -x);
	else if (i->octant == 6)
		ft_assign_values_output(i, y, -x);
	else if (i->octant == 7)
		ft_assign_values_output(i, x, -y);
	return (i);
}
