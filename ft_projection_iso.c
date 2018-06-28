/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_iso.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:54:16 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:30:28 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point				*ft_add_list(t_point *list, double x, double y, double z)
{
	t_point *start;

	if (list == NULL)
	{
		if ((list = (t_point*)malloc(sizeof(*list))) == NULL)
			ft_error(ERROR);
		start = list;
	}
	else
	{
		start = list;
		while (list != NULL && list->next != NULL)
			list = list->next;
		if (((list->next) = (t_point*)malloc(sizeof(*(list->next)))) == NULL)
			ft_error(ERROR);
		list = list->next;
	}
	list->x = x;
	list->y = y;
	list->z = z;
	list->u = 0;
	list->v = 0;
	list->next = NULL;
	return (start);
}

static t_2dp		**ft_lst_to_tab(t_point *list, int length, int height)
{
	int		i;
	int		x;
	int		y;
	t_2dp	**tab;

	y = -1;
	if ((tab = (t_2dp**)malloc(sizeof(*tab) * height)) == NULL)
		exit(0);
	while (++y < height)
		if ((tab[y] = (t_2dp*)malloc(sizeof(t_2dp) * length)) == NULL)
			exit(0);
	y = 0;
	while (list != NULL && y < height)
	{
		x = 0;
		i = -1;
		while (list != NULL && ++i < length)
		{
			ft_assign_values_2d(&(tab[y][x]), list->u, list->v);
			list = list->next;
			x++;
		}
		y++;
	}
	return (tab);
}

void				ft_extract_2_points(t_winenv mlxenv, t_grail *holy)
{
	t_2dp	**tab;
	int		y;
	int		x;

	tab = ft_lst_to_tab(holy->start, holy->length, holy->height);
	y = -1;
	while (++y < holy->height)
	{
		x = -1;
		while (++x < ((holy->length) - 1))
			ft_draw_line_bres(tab[y][x], tab[y][x + 1], mlxenv, SILVER);
	}
	y = -1;
	while (++y < (holy->height) - 1)
	{
		x = -1;
		while (++x < holy->length)
			ft_draw_line_bres(tab[y][x], tab[y + 1][x], mlxenv, SILVER);
	}
	y = -1;
	while (++y < holy->height)
		free(tab[y]);
	free(tab);
}

t_point				*ft_matrice_magic(t_point *list, t_grail *holy)
{
	t_point *start;

	start = list;
	while (list != NULL)
	{
		list->u = (holy->scale * list->x) * cos(ANGLE) + (holy->scale * list->y)
				* cos(ANGLE + ISO) + (holy->scale * list->z) * cos(ANGLE - ISO);
		list->v = (holy->scale * list->x) * sin(ANGLE) + (holy->scale * list->y)
				* sin(ANGLE + ISO) + (holy->scale * list->z) * sin(ANGLE - ISO);
		list = list->next;
	}
	return (start);
}
