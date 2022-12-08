# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:55:16 by nnuno-ca          #+#    #+#              #
#    Updated: 2022/12/08 00:48:06 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf

# PUSH_SWAP ---------------------------------------------
NAME = push_swap
SRCS = srcs/utils/handle_error.c\
	   srcs/utils/stack/stack_utils.c\
	   srcs/utils/stack/fill_a.c\
	   srcs/utils/stack/free_arrays.c\
	   srcs/utils/insertion_sort.c\
	   srcs/instructions/instructions.c\
	   srcs/instructions/instructions_2.c\
	   srcs/parse_input.c\
	   srcs/special_case.c\
	   srcs/finds/find_midpoint.c\
	   srcs/finds/find_maxpoint.c\
	   srcs/moves/moves.c\
	   main.c
OBJS = $(SRCS:.c=.o)

# CHECKER ------------------------------------------------
BONUS_NAME = checker
BONUS_SRCS = bonus/srcs/utils/handle_error.c\
			 bonus/srcs/utils/stack/stack_utils.c\
			 bonus/srcs/utils/stack/fill_a.c\
			 bonus/srcs/utils/stack/free_arrays.c\
			 bonus/srcs/utils/vector/vector_utils.c\
			 bonus/srcs/instructions/instructions.c\
			 bonus/srcs/instructions/instructions_2.c\
			 bonus/srcs/parse_input.c\
			 bonus/main.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o checker

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS) $(BONUS_OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME)
re: fclean all

.SILENT: