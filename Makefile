# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afournie <afournie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/02 11:21:47 by afournie          #+#    #+#              #
#    Updated: 2026/01/12 16:51:02 by afournie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Werror -Wextra

LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
INC         = -I includes -I $(LIBFT_DIR)

SRCS        =	srcs/main.c \
				srcs/free.c \
				srcs/parse.c \
				srcs/utils.c \
				srcs/sort_small.c \
				srcs/errors/error.c \
				srcs/operations/push.c \
				srcs/operations/reverse_rotate.c \
				srcs/operations/rotate.c \
				srcs/operations/swap.c

OBJS        = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
