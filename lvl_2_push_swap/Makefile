# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:55:16 by nnuno-ca          #+#    #+#              #
#    Updated: 2022/12/09 19:01:45 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
INC = -I./includes
BONUS_INC =-I./bonus/includes
VPATH = srcs srcs/algos srcs/instructions srcs/instructions/ok_instructions\
		srcs/stack srcs/utils
LIBFT = ./libft/libft.a
RM = rm -rf

ALGOS = insertion_sort midpoint_sort radix_sort special_case
INSTRUCTIONS = double_instructions single_instructions single_instructions_2
OK_INSTRUCTIONS = ok_instructions ok_instructions_2
STACK = free_stacks is_sorted max stack_utils
UTILS = fill_a panic
GENERAL = moves parse_input

# PUSH_SWAP ---------------------------------------------
NAME = push_swap
SRCS = $(addsuffix .c, $(ALGOS))\
	   $(addsuffix .c, $(INSTRUCTIONS))\
	   $(addsuffix .c, $(OK_INSTRUCTIONS))\
	   $(addsuffix .c, $(STACK))\
	   $(addsuffix .c, $(UTILS))\
	   $(addsuffix .c, $(GENERAL))\
	   main.c
OBJ_DIR = obj
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# CHECKER ------------------------------------------------
BONUS_NAME = checker
BONUS_SRCS = bonus/srcs/instructions/single_instructions.c\
	   		 bonus/srcs/instructions/single_instructions_2.c\
			 bonus/srcs/instructions/double_instructions.c\
			 bonus/srcs/stack/fill_a.c\
			 bonus/srcs/stack/free_stacks.c\
			 bonus/srcs/stack/is_sorted.c\
			 bonus/srcs/stack/stack_utils.c\
			 bonus/srcs/panic.c\
			 bonus/srcs/parse_input.c\
			 bonus/main.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(OBJ_DIR):
	mkdir -p obj

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(BONUS_INC)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME) $(OBJ_DIR)

re: fclean all

.SILENT:
