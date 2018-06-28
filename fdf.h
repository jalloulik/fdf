/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:25:05 by kjalloul          #+#    #+#             */
/*   Updated: 2017/12/18 17:27:12 by kjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define ESC_KEY 53
# define PLUS_KEY 69
# define PAGE_UP 116
# define MINUS_KEY 78
# define PAGE_DOWN 121
# define UP_KEY 126
# define RIGHT_KEY 124
# define DOWN_KEY 125
# define LEFT_KEY 123

# define RED 0xff0000
# define SILVER 0xc0c0c0
# define GOLD 0xFFDF00
# define CONVERT_DEGREE_TO_RAD(x) (x * 0.01745329252)
# define ANGLE CONVERT_DEGREE_TO_RAD(30)
# define ISO 2.0944
# define LEFT_PAD 0
# define TOP_PAD 0
# define SCALEL 10
# define SCALET 10
# define ZSCALE 10
# define APPLYL(value) ((value * SCALEL))
# define APPLYT(value) ((value * SCALET))
# define ERROR "Error"
# define SIZE_ERROR "Found wrong line length. Exiting."
# define MAX_WIN_HEIGHT 1300
# define MAX_WIN_LENGTH 2000

typedef struct	s_point
{
	double			x;
	double			y;
	double			z;
	double			u;
	double			v;
	struct s_point	*next;
}				t_point;

typedef struct	s_pt
{
	double	xinput;
	double	yinput;
	double	xoutput;
	double	youtput;
	int		octant;
}				t_pt;

typedef struct	s_2dp
{
	double x;
	double y;
}				t_2dp;

typedef struct	s_mlximg
{
	void	*ptr;
	int		bpp;
	int		s_l;
	int		endian;
	char	*str;
}				t_mlximg;

typedef struct	s_winenv
{
	void		*win;
	void		*mlxptr;
	t_mlximg	img;
	int			length;
	int			height;
	int			lpad;
	int			tpad;
}				t_winenv;

typedef struct	s_file
{
	char			*line;
	char			**tab;
	struct s_file	*next;
}				t_file;

typedef struct	s_grail
{
	t_point		*start;
	t_winenv	*mlxenv;
	int			length;
	int			height;
	int			scale;
}				t_grail;

void			ft_draw_line_bres(t_2dp a, t_2dp b, t_winenv mlxenv, int color);
t_pt			*ft_input_conver(t_pt *i, double x, double y);
t_pt			*ft_output_conver(t_pt *i, double x, double y);
void			ft_assign_values_2d(t_2dp *point, double x, double y);
t_point			*ft_add_list(t_point *list, double x, double y, double z);
void			ft_extract_2_points(t_winenv mlxenv,
														t_grail *holy);
t_point			*ft_matrice_magic(t_point *list, t_grail *holy);
t_grail			*ft_parsing_start(char *file_name);
void			ft_error(char *str);
void			fill_itab(t_file *list, t_grail *holy);
void			ft_free_filelst(t_file *list);
int				ft_tab_len(char **tab);
int				ft_keyhook(int keycode, t_grail *holy);
void			ft_determine_best_dimension(t_point *projection,
													t_winenv *mlxenv);
void			ft_fill_img(t_winenv mlxenv, int x, int y, int color);
void			ft_create_image(t_winenv *mlxenv);
void			ft_redraw(t_grail *holy, t_winenv *mlxenv);
int				ft_absolu(int nb);
void			ft_redraw_mov(t_grail *holy, t_winenv *mlxenv);

#endif
