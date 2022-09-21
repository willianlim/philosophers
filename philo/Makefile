# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 16:42:13 by wrosendo          #+#    #+#              #
#    Updated: 2022/09/21 12:29:52 by wrosendo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
# ============================== Color Variables ============================= #
# ============================================================================ #

RED = "\e[31;1m"
GREEN = "\e[32;1m"
YELLOW = "\e[33;1m"
RESET = "\e[0m"

# ============================================================================ #
# ============================ Command Variables ============================= #
# ============================================================================ #

CC = cc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

# ============================================================================ #
# ============================== File variables ============================== #
# ============================================================================ #

NAME = ./bin/philo
DIRNAME = ./bin
APP = ./app
OBJDIR = ./objects
SRCDIR = ./sources
INCLUDE = ./include
SRCDIR_PARSE = ./sources/parse
SRCDIR_AUXLIB = ./sources/aux_library
SRCDIR_EXECUTOR = ./sources/executor

# ============================================================================ #
# ============================= Target Generating ============================ #
# ============================================================================ #

SRC_EXECUTOR += ft_start_dinner.c ft_end_dinner.c
OBJEXECUTOR = $(SRC_EXECUTOR:.c=.o)
OBJECTS_EXECUTOR = $(addprefix $(OBJDIR)/, $(OBJEXECUTOR))

SRC_AUXLIB += ft_atoi.c ft_stopwatch.c ft_routine.c
SRC_AUXLIB += ft_monitoring.c ft_action_print.c ft_strcmp.c
OBJAUXLIB = $(SRC_AUXLIB:.c=.o)
OBJECTS_AUXLIB = $(addprefix $(OBJDIR)/, $(OBJAUXLIB))

SRC_PARSE += ft_handling_input.c ft_prepare_dinner.c
OBJPARSE = $(SRC_PARSE:.c=.o)
OBJECTS_PARSE = $(addprefix $(OBJDIR)/, $(OBJPARSE))

# ============================================================================ #
# ================================== Rules =================================== #
# ============================================================================ #

all: $(NAME)

$(NAME): $(OBJECTS_PARSE) $(OBJECTS_AUXLIB) $(OBJECTS_EXECUTOR)
	@echo $(GREEN) "Source files are compiled!\n" $(RESET)
	@echo $(WHITE) "Building $(NAME) for" $(YELLOW) "Mandatory ..." $(RESET)
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
	@echo $(YELLOW) "Cleaning object files..." $(RESET)
	$(REMOVE) $(OBJDIR)
	@echo $(RED) "Object files are cleaned!\n" $(RESET)

fclean: clean
	@echo $(YELLOW) "Removing $(NAME)..." $(RESET)
	$(REMOVE) $(DIRNAME)
	@echo $(RED) "$(NAME) is removed!\n" $(RESET)

re: fclean all

.PHONY: bonus clean fclean re
