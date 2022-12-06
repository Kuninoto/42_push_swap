# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 12:55:16 by nnuno-ca          #+#    #+#              #
#    Updated: 2022/12/06 17:54:52 by nnuno-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
RM = rm -rf
NAME = push_swap

SRCS = srcs/handle_error.c\
	   srcs/stack_utils.c\
	   srcs/instructions/instructions.c\
	   srcs/instructions/instructions_2.c\
	   srcs/initializers.c\
	   srcs/parse_input.c\
	   srcs/special_case.c\
	   srcs/finds/find_midpoint.c\
	   srcs/finds/find_maxpoint.c\
	   srcs/moves/moves.c\
	   srcs/insertion_sort.c\
	   srcs/free_stacks.c\
	   main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap
clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)
fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
re: fclean all

.SILENT: