# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/16 17:29:05 by canoduran         #+#    #+#              #
#    Updated: 2026/03/17 15:01:04 by canoduran        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- COLORS ---
RED      = \033[0;31m
BLUE     = \033[0;34m
GREEN    = \033[0;32m
RESET    = \033[0m

# --- VARIABLES ---
CC       = gcc
NAME     = puissance_4
CFLAGS   = -Wall -Wextra -Werror
HEADER   = puissance_4.h

# --- DIRECTORIES ---

DIR_SRC     = src


# --- SOURCES ---
SRC = $(DIR_SRC)/main.c \

#       $(DIR_SRC)/$()/.c \

# --- OBJECTS ---
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)


# --- RULES ---

all : $(NAME)

$(NAME) : $(OBJ) $(LIBFT)
	@echo -e "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(OBJ) $(CFLAGS) $(LFLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo -e "$(GREEN)Build successfully complete!$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR) --no-print-directory
	@echo -e "$(BLUE)adding libft$<...$(RESET)"

$(OBJ_DIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@echo -e "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo -e "$(RED)Cleaning object files...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR) --no-print-directory

fclean: clean
	@echo -e "$(RED)Removing executable $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --no-print-directory

re : fclean all

.PHONY : all clean fclean re