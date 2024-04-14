# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 20:52:05 by luynagda          #+#    #+#              #
#    Updated: 2024/02/26 14:10:42 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAKE_MLX = make -C minilibx-linux
MLX = minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -L./minilibx-linux -l:libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MAKE_LIBFT = make -C ./dependencies/libft
LIBFT = ./dependencies/libft/build/libft.a

FILES = main.c	\
		texture_parser.c	\
		location_utils.c	\
		errors_handler.c	\
		parser_utils.c		\
		loader.c			\
		graphics_utils.c
BUILD_DIRECTORY = ./build/

CC = gcc

FLAGS = -c -Wall -Wextra -Werror -g3 -MD

OBJS = $(addprefix $(BUILD_DIRECTORY), $(FILES:.c=.o))

$(NAME): $(BUILD_DIRECTORY) $(OBJS) | $(LIBFT)
	@NEED_LINK=0; \
	for file in $(OBJS) $(LIBFT); do \
		if [ $$file -nt $(NAME) ]; then \
			NEED_LINK=1; \
			break; \
		fi; \
	done; \
	if [ ! -f $(NAME) ] || [ $$NEED_LINK -eq 1 ]; then \
		$(MAKE_MLX)
		$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME); \
	else \
		echo "Nothing to be done for '$@'"; \
	fi

$(LIBFT):
	$(MAKE_LIBFT)

$(BUILD_DIRECTORY)%.o: ./sources/%.c Makefile
	mkdir -p minilibx-linux
	$(CC) $(FLAGS) -I ./includes/ -I ./dependencies/libft/.includes/ $< -o $@

$(BUILD_DIRECTORY):
	mkdir -p $(BUILD_DIRECTORY)utils	\
	$(BUILD_DIRECTORY)parsing
all : $(NAME)

clean :
	$(MAKE_LIBFT) clean
	$(MAKE_MLX) clean
	rm -rf $(BUILD_DIRECTORY)

fclean : clean
	$(MAKE_LIBFT) fclean
	$(MAKE_MLX) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re $(LIBFT)

-include $(OBJS:.o=.d)