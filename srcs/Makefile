# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gavizet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 14:24:08 by gavizet           #+#    #+#              #
#    Updated: 2016/12/21 21:27:36 by gavizet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# FILLIT

NAME =			fillit
CC = 			gcc
FLAGS =			-Wall -Wextra -Werror
MAKE = 			make -C
LIBFT =			libft/
INCLUDESPATH =	includes/
SRCSPATH =		srcs/

SRCS = 	main.c		\
		parsing.c	\
		check.c		\
		solver.c

OBJS = $(SRCS:%.c=%.o)

%.o: $(SRCSPATH)%.c
	$(CC) $(FLAGS) -c -o $@ $<

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) $(LIBFT) fclean && $(MAKE) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -I $(LIBFT)$(INCLUDESPATH) -L $(LIBFT) -lft

.PHONY : clean

clean:
	$(MAKE) $(LIBFT) clean
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) $(LIBFT) fclean
	/bin/rm -f $(NAME)

re: fclean all
