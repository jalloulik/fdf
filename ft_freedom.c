/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:46:26 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:31:20 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_free_ctab(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void			ft_free_filelst(t_file *list)
{
	t_file *tmp;
	t_file *lsttmp;

	tmp = list;
	lsttmp = list;
	while (lsttmp != NULL)
	{
		tmp = lsttmp;
		lsttmp = lsttmp->next;
		free(tmp->line);
		ft_free_ctab(tmp->tab);
		free(tmp);
	}
	free(lsttmp);
}
