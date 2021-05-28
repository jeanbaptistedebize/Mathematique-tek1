##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC = 		src/main.c				\
			src/fonc_cipher.c			\
			src/decrype_fonc.c			\
			src/my_str_to_word_array.c 	\
			src/free_fonc.c				\
			src/print_fonc.c

OBJ = 		$(SRC:.c=.o)

NAME =		103cipher

CFLAGS = 	-I include/

LIB = 		-L lib/ -lm

all:		$(NAME)

$(NAME): $(OBJ)
	gcc	-o $(NAME) $(SRC) $(CFLAGS) $(LIB)

clean :
	rm -f $(OBJ) *~
	rm -f *.g*
	rm -f vgcore.*

fclean :	clean
	rm -f $(NAME)
	rm -f *.gcno

re : fclean $(OBJ)
	gcc	-o $(NAME) $(SRC) $(CFLAGS) $(LIB)
