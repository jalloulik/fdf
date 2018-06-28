/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 09:49:27 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 15:56:03 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fill_img(t_winenv mlxenv, int x, int y, int color)
{
	int		opp;
	int		i;

	if ((x >= 0) && (y >= 0) && (x < (mlxenv.length + 100))
								&& (y < (mlxenv.height + 100)))
	{
		opp = mlxenv.img.bpp / 8;
		i = (x * opp) + (y * mlxenv.img.s_l);
		mlxenv.img.str[i] = color;
		mlxenv.img.str[i + 1] = color >> 8;
		mlxenv.img.str[i + 2] = color >> 16;
		mlxenv.img.str[i + 3] = color >> 24;
	}
}

void	ft_create_image(t_winenv *mlxenv)
{
	mlxenv->img.ptr = mlx_new_image(mlxenv->mlxptr, (mlxenv->length + 100),
							(mlxenv->height + 100));
	if (mlxenv->img.ptr == NULL)
		ft_error(ERROR);
	mlxenv->img.str = mlx_get_data_addr(mlxenv->img.ptr, &(mlxenv->img.bpp),
								&(mlxenv->img.s_l), &(mlxenv->img.endian));
	if (mlxenv->img.str == NULL)
		ft_error(ERROR);
}
