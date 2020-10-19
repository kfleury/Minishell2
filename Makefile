##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

#flag#

CFLAGS = -Wall -Wextra -Wshadow ##-Werror

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS =

LIBFLAGS = -L lib/ -lmy

#source#

MAIN = src/main.c

SRC = src/core/core.c	\
		src/core/handle_line.c	\
		src/core/exec.c	\
		src/core/minishell.c	\
		src/function/cd.c	\
		src/function/exit.c	\
		src/function/setenv.c	\
		src/function/unsetenv.c	\
		src/function/func_env.c	\
		src/function/pipe.c	\
		src/function/l2redirection.c	\
		src/function/lredirection.c	\
		src/function/r2redirection.c	\
		src/function/rredirection.c	\
		src/usage/free.c	\
		src/usage/list_l.c	\
		src/usage/error.c	\
		src/setup/color.c	\
		src/setup/init.c	\

MAIN_OBJ = $(MAIN:.c=.o)
OBJ = $(SRC:.c=.o)

NAME = mysh

IDIR = ./include

CC = gcc

RM = rm -f

#rules#

all:	$(NAME)

$(NAME):	$(MAIN_OBJ) $(OBJ)
	make -C lib/my
	$(CC) -o $(NAME) $(MAIN_OBJ) $(OBJ) $(CPPFLAGS) $(LIBFLAGS)

debug: CFLAGS += $(DBGFLAGS)
debug: fclean
debug: $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(MAIN_OBJ)
	$(RM) include/*.gc*
	$(RM) vgcore*

fclean: clean
	$(RM) $(NAME)
	$(RM) a.out

re: fclean all

lib:
	make -C lib/my

.PHONY: fclean clean re all debug lib

tests_run:
	./tests/test2
# tests_run: LDFLAGS += -lcriterion --coverage

# tests_run:
# 		$(CC) -o unit_tests tests/project.c $(CPPFLAGS) $(LDFLAGS)
# 		./unit_tests
# 		gcovr -e tests/
