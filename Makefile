# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgerguri <dgerguri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 19:39:45 by dgerguri          #+#    #+#              #
#    Updated: 2023/09/25 15:49:38 by dgerguri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3D
NAME_B		=	cub3D_bonus
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g
LIBFT_DIR	=	libft/
LIBFT		=	libft.a
MLX_DIR		=	MLX42/
MLX 		=	MLX42/build/libmlx42.a
FRAMEWORK	=	-framework Cocoa -framework OpenGL -framework IOKit

SRC_PATH	=	src/
OBJ_PATH	=	obj/
SRC			=	main.c error.c \
				init/init.c init/read_map.c init/split_line.c \
				parsing/split_elements_map.c parsing/validate_elements.c

SRC_B_PATH	=	src_bonus/
OBJ_B_PATH	=	obj_bonus/
SRC_B		=	main_bonus.c

SRCS		=	$(addprefix $(SRC_PATH), $(SRC))
OBJ			=	$(SRC:.c=.o)
OBJS		=	$(addprefix $(OBJ_PATH), $(OBJ))
SRCS_B		=	$(addprefix $(SRC_B_PATH), $(SRC_B))
OBJ_B		=	$(SRC_B:.c=.o)
OBJS_B		=	$(addprefix $(OBJ_B_PATH), $(OBJ_B))
INCS		=	-I includes/

# pretty colors for the messages
GREEN			=	\033[0;32m
RED				=	\033[0;31m
BLUE			=	\033[0;34m
RESET			=	\033[0m

all: $(NAME) $(MLX)

$(MLX):
	cd $(MLX_DIR) && cmake -B build && cmake --build build -j4

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/init
	@mkdir -p $(OBJ_PATH)/parsing
	@cc $(CFLAGS) $(INCS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(BLUE)Compiling $(NAME)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@cc $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft
	@echo "$(GREEN)done$(RESET)"

bonus: $(NAME_B)

$(OBJ_B_PATH)%.o: $(SRC_B_PATH)%.c
	@mkdir -p $(OBJ_B_PATH)
	@cc $(CFLAGS) $(INCS) -c $< -o $@

$(NAME_B): $(OBJS_B)
	@echo "$(BLUE)Compiling $(NAME_B)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)
	@cc $(CFLAGS) $(OBJS_B) -o $(NAME_B) -L $(LIBFT_DIR) -lft
	@echo "$(GREEN)done$(RESET)"

clean:
	@echo "$(RED)removing object files$(RESET)"
	@/bin/rm -rf $(OBJ_PATH) $(OBJ_B_PATH)
	@$(MAKE) clean -C $(LIBFT_DIR)
	#@$(MAKE) clean -C $(MLX_DIR)/build //THESE STILL DOESNT WORK!

fclean: clean
	@echo "$(RED)cleaning all compiled stuff.. :)$(RESET)"
	@/bin/rm -rf $(NAME) $(NAME_B)
	@$(MAKE) fclean -C $(LIBFT_DIR)
	#@$(MAKE) fclean -C $(MLX_DIR)/build //THESE STILL DOESNT WORK!
	@echo "$(RED)done$(RESET)"

re: fclean all

.PHONY: all bonus clean fclean re
