/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:28:20 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:32:09 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			ft_fill_holy(t_file *list, t_grail *holy)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	holy->start = NULL;
	while (list != NULL)
	{
		i = -1;
		while (list->tab[++i] != 0)
			holy->start = ft_add_list(holy->start, (double)i, (double)j,
											(double)(ft_atoi(list->tab[i])));
		j++;
		list = list->next;
	}
}

static t_file		*ft_add_lst_file(t_file *list, char *line)
{
	t_file *start;

	if (list == NULL)
	{
		if ((list = (t_file*)malloc(sizeof(*list))) == NULL)
			exit(0);
		start = list;
	}
	else
	{
		start = list;
		while (list->next != NULL)
			list = list->next;
		if (((list->next) = (t_file*)malloc(sizeof(*(list->next)))) == NULL)
			exit(0);
		list = list->next;
	}
	list->line = ft_strdup(line);
	list->tab = ft_strsplit(list->line, ' ');
	list->next = NULL;
	return (start);
}

static int			ft_check_homogen(t_file *list, int length)
{
	while (list != NULL)
	{
		if (length != ft_tab_len(list->tab))
			ft_error(SIZE_ERROR);
		list = list->next;
	}
	return (1);
}

static t_grail		*ft_create_holy(int fd, t_file **start, t_grail *holy)
{
	char *str;

	while (get_next_line(fd, &str) > 0)
	{
		if (str == NULL)
			ft_error(ERROR);
		*start = ft_add_lst_file(*start, str);
		if (holy->length == -1)
		{
			if ((*start)->tab == NULL || (*start)->tab[0] == 0)
				ft_error(ERROR);
			holy->length = ft_tab_len((*start)->tab);
		}
		free(str);
		holy->height++;
	}
	if (holy->length == -1)
		ft_error(ERROR);
	ft_check_homogen(*start, holy->length);
	ft_fill_holy(*start, holy);
	return (holy);
}

t_grail				*ft_parsing_start(char *filename)
{
	int		fd;
	t_file	*start;
	t_grail	*holy;

	start = NULL;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(ERROR);
	if ((holy = (t_grail*)malloc(sizeof(*holy))) == NULL)
		ft_error(ERROR);
	holy->height = 0;
	holy->length = -1;
	holy = ft_create_holy(fd, &start, holy);
	ft_free_filelst(start);
	return (holy);
}
