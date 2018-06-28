/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redraw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 11:49:13 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:26:42 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_redraw_mov(t_grail *holy, t_winenv *mlxenv)
{
	mlx_destroy_image(mlxenv->mlxptr, mlxenv->img.ptr);
	mlx_clear_window(mlxenv->mlxptr, mlxenv->win);
	ft_create_image(mlxenv);
	ft_extract_2_points(*mlxenv, holy);
	mlx_put_image_to_window(mlxenv->mlxptr, mlxenv->win, mlxenv->img.ptr, 0, 0);
}

void	ft_redraw(t_grail *holy, t_winenv *mlxenv)
{
	mlx_destroy_image(mlxenv->mlxptr, mlxenv->img.ptr);
	mlx_clear_window(mlxenv->mlxptr, mlxenv->win);
	holy->start = ft_matrice_magic(holy->start, holy);
	ft_create_image(mlxenv);
	ft_extract_2_points(*mlxenv, holy);
	mlx_put_image_to_window(mlxenv->mlxptr, mlxenv->win, mlxenv->img.ptr, 0, 0);
}
