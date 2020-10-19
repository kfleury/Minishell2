##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile lib
##

#flags#

CFLAGS = -Wall -Wextra -Werror -Wshadow

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

LDFLAGS =

#sources#

SRC = convert_in_bit.c	\
		my_split.c	\
		my_strcat_int.c	\
		revstrint.c	\
		my_memcpy.c	\
		func_tab.c	\
		my_join.c	\
		restr.c	\
		my_clean_str.c	\
		my_strstr.c	\
		my_itoa.c	\
		my_puterror.c	\
		my_str_isnum.c	\
		my_strncmp.c	\
		my_realloc_td.c	\
		printf/my_puterror.c	\
		printf/ascii.c	\
		printf/base_hex_maj.c	\
		printf/base01.c	\
		printf/basehex.c	\
		printf/baseoct.c	\
		printf/flag_p.c	\
		printf/my_flag.c	\
		printf/my_printf.c	\
		printf/my_putnbr_unsigned.c	\
		printf/percent_percent.c	\
		func_lib/function.c	\
		func_lib/get_next_line.c	\
		func_lib/my_getnbr.c	\
		func_lib/my_putnbr.c	\
		func_lib/my_realloc.c	\
		func_lib/my_str_isnum.c	\
		func_lib/my_strcat.c	\
		func_lib/my_strcmp.c	\
		func_lib/my_strcpy.c	\
		func_lib/my_strdup.c	\
		func_lib/my_strlen.c	\
		func_lib/my_itoa.c	\
		func_lib/my_realloc.c	\

OBJ = $(SRC:.c=.o)

NAME = libmy.a

LIB = libmy.a

IDIR = .

CC = gcc

#rules#

all:    $(NAME)

$(NAME):    $(OBJ)
	ar rc $(LIB) $(OBJ)
	mv $(LIB) ../
	cp my.h ../../include/

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(LIB)

re: fclean all

.PHONY: fclean clean re all debug
