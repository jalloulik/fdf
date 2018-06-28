# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kjalloul <kjalloul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 17:18:00 by kjalloul          #+#    #+#              #
#    Updated: 2017/12/18 17:34:38 by kjalloul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCPATH = ./

OBJPATH = ./

IPATHLIB = libft/includes

IPATH = ./

HEADER = fdf.h

SRC = fdf.c\
	ft_draw_line.c\
	ft_convert_line_octant.c\
	ft_projection_iso.c\
	ft_parsing.c\
	ft_freedom.c\
	ft_tools.c\
	ft_find_settings.c\
	ft_create_image.c\
	ft_redraw.c

OBJ = $(SRC:%.c=$(OBJPATH)%.o)

SRCF = $(SRCPATH)$(SRC)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

LIB:
	make -C libft/

LIBCLEAN:
	make clean -C libft/
	make clean -C minilibx_macos/

LIBFCLEAN:
	make fclean -C libft/
	make fclean -C minilibx_macos/

$(OBJ): $(OBJPATH)%.o: $(SRCPATH)%.c $(IPATH)$(HEADER)
	gcc $(FLAG) -o $@ -c $< -I$(IPATH) -I$(IPATHLIB) -I minilibx_macos/

$(NAME): $(OBJ)
	make -C libft
	make -C minilibx_macos
	gcc $(FLAG) -o $(NAME) $(OBJ) -Llibft/ -lft -Lminilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean: LIBCLEAN
	/bin/rm -f $(OBJ)

fclean: clean LIBFCLEAN
	/bin/rm -f $(NAME)

re: fclean all
