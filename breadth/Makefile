##
## Makefile for dante in home/tbesson/projet_cpe/dante/gen
## 
## Made by Besson Tamsi
## Login   <tamsi.besson@epitech.eu>
## 
## Started on  Mon Apr 24 09:49:40 2015 Tamsi Besson
## Last update Sun May  7 16:44:59 2017 Tamsi Besson
##

CC	=	gcc

RM      =	rm -f

NAME   =	breadth

SRC  	=	main.c \
		graph.c \
		src/my_strcat.c \
		src/get_next_line.c

CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-I./include

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all
