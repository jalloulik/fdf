/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:50:18 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:30:54 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_key_hook_zoom(int keycode, t_grail *holy)
{
	if (keycode == PLUS_KEY && holy->scale < 100)
	{
		holy->scale++;
		ft_redraw(holy, holy->mlxenv);
	}
	else if (keycode == MINUS_KEY && holy->scale > 1)
	{
		holy->scale--;
		ft_redraw(holy, holy->mlxenv);
	}
	return (keycode);
}

static int		ft_key_hook_move(int keycode, t_grail *holy)
{
	if (keycode == UP_KEY &&
		ft_absolu(holy->mlxenv->tpad) < holy->mlxenv->height)
	{
		holy->mlxenv->tpad = holy->mlxenv->tpad - 10;
		ft_redraw_mov(holy, holy->mlxenv);
	}
	else if (keycode == DOWN_KEY
		&& ft_absolu(holy->mlxenv->tpad) < holy->mlxenv->height)
	{
		holy->mlxenv->tpad = holy->mlxenv->tpad + 10;
		ft_redraw_mov(holy, holy->mlxenv);
	}
	else if (keycode == LEFT_KEY
		&& ft_absolu(holy->mlxenv->lpad) < holy->mlxenv->length)
	{
		holy->mlxenv->lpad = holy->mlxenv->lpad - 10;
		ft_redraw_mov(holy, holy->mlxenv);
	}
	else if (keycode == RIGHT_KEY
		&& ft_absolu(holy->mlxenv->lpad) < holy->mlxenv->length)
	{
		holy->mlxenv->lpad = holy->mlxenv->lpad + 10;
		ft_redraw_mov(holy, holy->mlxenv);
	}
	return (keycode);
}

static int		ft_key_hook_exit(int keycode, t_grail *holy)
{
	holy = NULL;
	if (keycode == ESC_KEY)
		exit(0);
	return (keycode);
}

int				ft_keyhook(int keycode, t_grail *holy)
{
	if (keycode == PLUS_KEY || keycode == MINUS_KEY)
		ft_key_hook_zoom(keycode, holy);
	else if (keycode == RIGHT_KEY || keycode == LEFT_KEY || keycode == UP_KEY
									|| keycode == DOWN_KEY)
		ft_key_hook_move(keycode, holy);
	else if (keycode == ESC_KEY)
		ft_key_hook_exit(keycode, holy);
	return (keycode);
}
