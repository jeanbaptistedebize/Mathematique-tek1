##
## EPITECH PROJECT, 2020
## makefile
## File description:
## make my lib
##

SRC =		src/101_pong.c		\
			src/main.c			\
			src/gestion_error.c \
			src/vector_cacl.c

OBJ = 		$(SRC:.c=.o)

NAME =		101pong

CFLAGS += 	-I include/

LIB = 		-L lib -lmy -lm

all:		$(NAME)

$(NAME):	$(OBJ) 
	cd lib/my && make && make clean
	gcc -o $(NAME) $(OBJ) $(LIB) -Wall -Wextra -g3 

clean :
	rm -f $(OBJ) *~
	cd src/ && rm -f $(OBJ) *~

fclean :	clean
	rm -f lib/libmy.a
	rm -f $(NAME)

re : $(OBJ)
	cd lib/my && make && make clean
	gcc -o $(NAME) $(OBJ) $(LIB)
