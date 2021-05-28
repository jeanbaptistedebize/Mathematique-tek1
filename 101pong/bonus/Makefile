##
## EPITECH PROJECT, 2020
##  incude
## File description:
## makefile
##

SRC =	src/display_window.c	\
		src/101_pongt.c			\
		src/vector_caclt.c		\
		src/main.c				\
		src/list/f_list.c		\
		src/list/my_rev_list.c


OBJ =		$(SRC:.c=.o)

NAME =	  	pong

CFLAGS +=	-I include/

LIB =		-L lib -lmy_csfml -lm

all:		$(NAME)

$(NAME):	$(OBJ)
	cd lib/sfml_fonc && make && make clean
	gcc -o $(NAME) $(OBJ) $(LIB) -lcsfml-graphics

clean :
	rm -f $(OBJ) *~
	cd src/ && rm -f $(OBJ) *~

fclean :	clean
	rm -f lib/libmy*
	rm -f $(NAME)

re :  $(OBJ)
	cd lib/sfml_fonc && make && make clean
	gcc -o $(NAME) $(OBJ) $(LIB) -lcsfml-graphics
