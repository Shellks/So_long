# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acarlott <acarlott@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:45:25 by acarlott          #+#    #+#              #
#    Updated: 2023/01/24 14:13:35 by acarlott         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Werror -Wextra
MLFAGS = -L mlx -lmlx -framework OpenGL -framework AppKit
CC = cc
HEADER = include/so_long.h

PRINTF_PATH = ./printf/
PRINTF_FILE = libftprintf.a
PRINTF_LIB = $(addprefix ${PRINTF_PATH}, ${PRINTF_FILE})
MLX_PATH = ./mlx/
MLX_FILE = libmlx.a
MLX_LIB = $(addprefix ${MLX_PATH}, ${MLX_FILE})

SRCS =	core/main.c \
		core/so_long.c \
		core/ft_move.c \
		core/map_check.c \
		core/map_solver.c \
		core/map_parsing.c \
		core/ft_putborder.c \
		core/ft_putcenter.c \
		core/so_long_utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

%.o:	%.c Makefile ${PRINTF_LIB} ${MLX_LIB} ${HEADER}
	@${CC}  ${CFLAGS} -g -c $< -o ${<:.c=.o} -I ${HEADER}

all: ${NAME}

${NAME} : ${OBJS}
	@${CC} ${CFLAGS} ${MLFAGS} ${OBJS} ${PRINTF_LIB} ${MLX_LIB} -o ${NAME}
	@echo "\n\033[1;32mSucces: \033[1;33mso_long created !\n"

$(PRINTF_LIB): force
	@echo "\033[1;33m\nCompiling: \033[1;36m./printf"
	@make -C ./printf
	@echo "\033[1;32mSucces !"

$(MLX_LIB): force
	@echo "\033[1;33m\nCompiling: \033[1;36m./mlx"
	@make -C ./mlx
	@echo "\033[1;32mSucces !\n"

clean :
	@echo "\033[1;31m\nClean: \033[1;36mOBJ files\n"
	@${RM} ${OBJS}
	@make clean -sC ${PRINTF_PATH}
	@make clean -sC ${MLX_PATH}

fclean: clean
	@echo "\033[1;31mClean: \033[1;36mSo_long executable\n"
	@${RM} ${NAME}
	@make fclean -sC ${PRINTF_PATH}

re : fclean all

.PHONY: all clean fclean re force
