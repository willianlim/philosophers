# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 16:42:13 by wrosendo          #+#    #+#              #
#    Updated: 2022/09/13 14:42:00 by wrosendo         ###   ########.fr        #
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
SRCDIR_AUXLIB = ./sources/aux_library
SRCDIR_EXECUTOR = ./sources/executor
REMOVE = rm -rf

SRC_EXECUTOR += ft_prepare_diner.c ft_start_diner.c
OBJEXECUTOR = $(SRC_EXECUTOR:.c=.o)
OBJECTS_EXECUTOR = $(addprefix $(OBJDIR)/, $(OBJEXECUTOR))

SRC_AUXLIB += ft_atoi.c ft_calloc.c ft_bzero.c ft_memset.c ft_stopwatch.c
SRC_AUXLIB += ft_routine.c ft_monitoring.c
OBJAUXLIB = $(SRC_AUXLIB:.c=.o)
OBJECTS_AUXLIB = $(addprefix $(OBJDIR)/, $(OBJAUXLIB))

SRC_PARSE += ft_handling_input.c
OBJPARSE = $(SRC_PARSE:.c=.o)
OBJECTS_PARSE = $(addprefix $(OBJDIR)/, $(OBJPARSE))

all: $(NAME)

$(NAME): $(OBJECTS_PARSE) $(OBJECTS_AUXLIB) $(OBJECTS_EXECUTOR)
	@mkdir -p $(DIRNAME)
	$(CC) $(APP)/ft_philo.c -o $(NAME) $(OBJECTS_PARSE) $(OBJECTS_AUXLIB) \
	$(OBJECTS_EXECUTOR) -pthread

$(OBJDIR)/%.o: $(SRCDIR_EXECUTOR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_AUXLIB)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR_PARSE)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

clean:
	$(REMOVE) $(OBJDIR)

fclean: clean
	$(REMOVE) $(DIRNAME)

re: fclean all

.PHONY: bonus clean fclean re
