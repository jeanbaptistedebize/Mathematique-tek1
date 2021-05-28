##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC = fonc_sfml.c

OBJ =		$(SRC:.c=.o)

NAME =		libmy_csfml.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy_csfml.a $(NAME) $(OBJ)
	cp *.a ..

clean :
	rm -f *.o *.a *~
