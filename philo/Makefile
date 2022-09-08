# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 16:42:13 by wrosendo          #+#    #+#              #
#    Updated: 2022/09/08 16:42:16 by wrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./bin/philo
DIRNAME = ./bin
CC = clang
CFLAGS = -Wall -Wextra -Werror -O3
APP = ./app
OBJDIR = ./objects
SRCDIR = ./sources
INCLUDE = ./include
REMOVE = rm -rf

SRC_FILE +=
OBJFILE = $(SRC_FILE:.c=.o)
OBJECTS = $(addprefix $(OBJDIR)/, $(OBJFILE))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(APP)/ft_main.c -o $(NAME) $(OBJECTS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	$(REMOVE) $(OBJDIR)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re
