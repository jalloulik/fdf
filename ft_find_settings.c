/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_settings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:43:58 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 15:44:05 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_tab_len(char **tab)
{
	int len;

	len = 0;
	while (tab[len] != 0)
		len++;
	return (len);
}

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			ft_absolu(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

void		ft_determine_best_dimension(t_point *projection, t_winenv *mlxenv)
{
	double minlen;
	double minheight;
	double maxlen;
	double maxheight;

	minlen = 0;
	minheight = 0;
	maxlen = 0;
	maxheight = 0;
	while (projection != NULL)
	{
		if (projection->u > maxlen)
			maxlen = projection->u;
		if (projection->u < minlen)
			minlen = projection->u;
		if (projection->v > maxheight)
			maxheight = projection->v;
		if (projection->v < minheight)
			minheight = projection->v;
		projection = projection->next;
	}
	mlxenv->length = (int)(maxlen - minlen);
	mlxenv->height = (int)(maxheight - minheight);
	mlxenv->lpad = (int)(ft_absolu(minlen) + 50);
	mlxenv->tpad = (int)(ft_absolu(minheight) + 50);
}
