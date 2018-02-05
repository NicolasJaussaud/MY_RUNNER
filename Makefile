##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile to compile the c
##

SRC		=	runner.c \
			initstruct.c \
			createobject.c \
			jump.c \
			read.c \
			obstacle.c \
			event.c \
			score.c

OBJ 	= 	$(SRC:.c=.o)


CC	= 	gcc

CFLAGS	=	-W -Wall


NAME	=	my_runner


all: 	$(NAME)


$(NAME):		    $(OBJ)
	$(CC)  -o $(NAME) $(OBJ) -l csfml-graphics -l csfml-window -l csfml-system 


clean:
	rm -f $(OBJ)


fclean:	clean
	rm -f $(NAME)


re:	fclean all
