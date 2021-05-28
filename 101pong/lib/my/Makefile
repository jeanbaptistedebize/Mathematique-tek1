##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		my_putstr.c 	\
			my_str_isnum.c 	\
			my_putchar.c 	\

OBJ = 		$(SRC:.c=.o)

NAME =		libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
	ar rc libmy.a $(NAME) $(OBJ)
	cp *.a ..

clean :
	rm *.o *.a 

