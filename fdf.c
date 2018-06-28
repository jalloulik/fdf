/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:24:25 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:32:30 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			ft_create_window(t_grail *holy)
{
	t_winenv	mlxenv;

	ft_determine_best_dimension(holy->start, &mlxenv);
	while ((mlxenv.length > MAX_WIN_LENGTH || mlxenv.height > MAX_WIN_HEIGHT)
															&& holy->scale > 1)
	{
		holy->scale--;
		holy->start = ft_matrice_magic(holy->start, holy);
		ft_determine_best_dimension(holy->start, &mlxenv);
	}
	if (mlxenv.length < 0 || mlxenv.height < 0)
		ft_error(ERROR);
	mlxenv.mlxptr = mlx_init();
	mlxenv.win = mlx_new_window(mlxenv.mlxptr, mlxenv.length + 100,
											mlxenv.height + 100, "fdf");
	if (mlxenv.win == NULL)
		ft_error(ERROR);
	ft_create_image(&mlxenv);
	ft_extract_2_points(mlxenv, holy);
	mlx_put_image_to_window(mlxenv.mlxptr, mlxenv.win, mlxenv.img.ptr, 0, 0);
	holy->mlxenv = &mlxenv;
	mlx_key_hook(mlxenv.win, &ft_keyhook, holy);
	mlx_loop(mlxenv.mlxptr);
	return (0);
}

static void			receive_grail(t_grail *holy)
{
	holy->scale = 10;
	holy->start = ft_matrice_magic(holy->start, holy);
	ft_create_window(holy);
}

int					main(int ac, char **av)
{
	t_grail *holy;

	if (ac != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	holy = ft_parsing_start(av[1]);
	receive_grail(holy);
	return (0);
}
