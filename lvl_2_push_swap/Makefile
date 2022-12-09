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
LIBFT = ./libft/libft.a
RM = rm -rf

# PUSH_SWAP ---------------------------------------------
NAME = push_swap
SRCS = srcs/utils/handle_error.c\
	   srcs/utils/stack/stack_utils.c\
	   srcs/utils/stack/fill_a.c\
	   srcs/utils/stack/free_arrays.c\
	   srcs/utils/insertion_sort.c\
	   srcs/utils/radix_sort.c\
	   srcs/utils/is_ordered.c\
	   srcs/utils/ft_long_atoi.c\
	   srcs/instructions/single_instructions.c\
	   srcs/instructions/single_instructions_2.c\
	   srcs/instructions/double_instructions.c\
	   srcs/instructions/ok_instructions/ok_instructions.c\
	   srcs/instructions/ok_instructions/ok_instructions_2.c\
	   srcs/special_case.c\
	   srcs/utils/midpoint_sort.c\
	   srcs/moves/moves.c\
	   main.c
OBJS = $(SRCS:.c=.o)

# CHECKER ------------------------------------------------
BONUS_NAME = checker
BONUS_SRCS = bonus/srcs/utils/handle_error.c\
			 bonus/srcs/utils/stack/stack_utils.c\
			 bonus/srcs/utils/stack/fill_a.c\
			 bonus/srcs/utils/stack/free_arrays.c\
			 bonus/srcs/instructions/single_instructions.c\
	   		 bonus/srcs/instructions/single_instructions_2.c\
			 bonus/srcs/instructions/double_instructions.c\
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
