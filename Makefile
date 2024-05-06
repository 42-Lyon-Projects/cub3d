# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunagda <lunagda@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 20:52:05 by luynagda          #+#    #+#              #
#    Updated: 2024/05/06 14:25:19 by lunagda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MAKE_MLX = make -C ./dependencies/minilibx-linux
MLX = ./dependencies/minilibx-linux/libmlx_Linux.a
MLX_FLAGS = -L./dependencies/minilibx-linux -l:libmlx.a -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

MAKE_LIBFT = make -C ./dependencies/libft
LIBFT = ./dependencies/libft/build/libft.a

NORM = @norminette includes sources maps textures

FILES = main.c						\
		errors_handler.c			\
		parsing/parser_utils.c		\
		parsing/color_utils.c		\
		parsing/map_validator.c		\
		graphics_utils.c			\
		parsing/texture_utils.c		\
		parsing/map_parser.c		\
		utils/ft_add_to_2d_array.c	\
		utils/direction_utils.c		\
		utils/ft_copy_2d_array.c	\
		exec/ft_init.c				\
		exec/dda.c					\
		exec/raycasting.c			\
		exec/hook_functions.c		\
		exec/move.c					\
		exec/cam_rotate.c			\
		exec/texture_functions.c

BUILD_DIRECTORY = ./build/

CC = gcc

FLAGS = -c -g3 -MD -O2
OBJS = $(addprefix $(BUILD_DIRECTORY), $(FILES:.c=.o))

$(NAME): $(BUILD_DIRECTORY) $(OBJS) | $(LIBFT) $(MLX)
	@NEED_LINK=0; \
	for file in $(OBJS) $(LIBFT); do \
		if [ $$file -nt $(NAME) ]; then \
			NEED_LINK=1; \
			break; \
		fi; \
	done; \
	if [ ! -f $(NAME) ] || [ $$NEED_LINK -eq 1 ]; then \
		$(CC) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME); \
	else \
		echo "Nothing to be done for '$@'"; \
	fi

$(MLX):
	$(MAKE_MLX)

$(LIBFT):
	$(MAKE_LIBFT)

$(BUILD_DIRECTORY)%.o: ./sources/%.c Makefile
	$(CC) $(FLAGS) -I ./includes/ -I ./dependencies/libft/.includes/ $< -o $@

$(BUILD_DIRECTORY):
	mkdir -p $(BUILD_DIRECTORY)/parsing $(BUILD_DIRECTORY)/utils $(BUILD_DIRECTORY)/exec

all : $(NAME)

clean :
	$(MAKE_LIBFT) clean
	$(MAKE_MLX) clean
	rm -rf $(BUILD_DIRECTORY)

fclean : clean
	$(MAKE_LIBFT) fclean
	$(MAKE_MLX) clean
	$(RM) $(NAME)

re : fclean all

norminette:
	$(NORM)

.PHONY: all clean fclean re $(LIBFT)

-include $(OBJS:.o=.d)