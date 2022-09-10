# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 16:42:13 by wrosendo          #+#    #+#              #
#    Updated: 2022/09/10 17:25:13 by wrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ./bin/philo
DIRNAME = ./bin
CC = cc
CFLAGS = -Wall -Wextra -Werror -O3
APP = ./app
OBJDIR = ./objects
SRCDIR = ./sources
INCLUDE = ./include
SRCDIR_PARSE = ./sources/parse
REMOVE = rm -rf

SRC_PARSE += ft_handling_input.c
OBJPARSE = $(SRC_PARSE:.c=.o)
OBJECTS_PARSE = $(addprefix $(OBJDIR)/, $(OBJPARSE))

all: $(NAME)

$(NAME): $(OBJECTS_PARSE)
	@mkdir -p ./bin/
	$(CC) $(APP)/ft_philo.c -o $(NAME) $(OBJECTS_PARSE) -pthread

$(OBJDIR)/%.o: $(SRCDIR_PARSE)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	$(REMOVE) $(OBJDIR)

fclean: clean
	$(REMOVE) $(DIRNAME)

re: fclean all

.PHONY: bonus clean fclean re
