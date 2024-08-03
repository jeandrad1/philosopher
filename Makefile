# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeandrad <jeandrad@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/27 13:23:39 by jeandrad          #+#    #+#              #
#    Updated: 2024/08/03 15:14:07 by jeandrad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name: pipex
NAME = philo

# Compiler
CC = clang

# Compiler flags
FLAGS = -Wall -Werror -Wextra -Iinclude -g -pthread #-fsanitize

# Source files for mandatory
FILES =	philo\
		parser_init_table\
		init_philo\
		threads\
		actions\
		dinner_ends\
		time_and_control\
		best_sleep\

# Source directory
SRCS_DIR = ./src/

# Object directory
OBJ_DIR = ./src/

# Source files prepended with directory and appended with .c
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

# Object files prepended with directory and appended with .o
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# Compile rule
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

# Build rule for mandatory
$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "PHILO created"

# Build rule for mandatory
all: $(NAME)

# Clean rule
clean: 
	@rm -f $(OBJS)
	@echo "ALL clean"

# Fclean rule
fclean: clean
	@rm -f $(NAME)
	@echo "ALL fclean"

# Re rule
re: fclean all

.PHONY = all clean fclean re libft