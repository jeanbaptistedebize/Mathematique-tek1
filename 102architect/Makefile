##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC = 		src/main.c			\
			src/fonc_archi.c	\
			src/gestion_error.c	\
			src/fonc_print.c

SRC_T = 	src/fonc_archi.c

OBJ = 		$(SRC:.c=.o)

NAME =		102architect

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
	rm -f unit_tests

tests_run :
	gcc -o unit_tests $(SRC_T) tests/tests_102archi.c $(CFLAGS) $(LIB) -lcriterion --coverage
	./unit_tests

tests_cover :
	gcovr --exclude tests/tests_102archi.c
	gcovr --exclude tests/tests_102archi.c --branches

re : $(OBJ)
	gcc	-o $(NAME) $(SRC) $(CFLAGS) $(LIB)
