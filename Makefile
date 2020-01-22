#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerloc- <akerloc-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/12 17:40:07 by akerloc-          #+#    #+#              #
#    Updated: 2020/01/18 16:30:26 by akerloc-         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = main.c \
	check_parsing.c \
	hook.c \
	update.c \
	raycasting.c \
	raycasting_init.c \
	get_next_line_utils.c \
	get_next_line.c \
	parsing.c \
	convert.c \
	create_tab.c \
	ft_atoi.c \
	ft_atoi_base.c \
	ft_strdup.c \
	rendu.c \
	export.c \
	collision.c \
	ft_strcmp.c
OBJS = ${SRCS:.c=.o}
NAME = cub3D
HEADER = .
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = mlx/. -lmlx -framework OpenGL -framework AppKit
MLX = libmlx.dylib

all : ${NAME}

$(MLX):
		@$(MAKE) -C mlx
		@mv mlx/$(MLX) .

clean : 
		rm -f ${OBJS}

fclean : clean
		rm -f ${NAME}
		$(RM) $(NAME) $(MLX)

$(NAME) : $(MLX) ${OBJS}
		  gcc ${CFLAGS} -L ${LIBS} -o ${NAME} ${OBJS}

re : fclean all

.PHONY : all clean re fclean
