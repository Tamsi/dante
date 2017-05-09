##
## Makefile for dante in home/tbesson/projet_cpe/dante/gen
## 
## Made by Besson Tamsi
## Login   <tamsi.besson@epitech.eu>
## 
## Started on  Mon Apr 24 09:49:40 2015 Tamsi Besson
## Last update Sat May  6 18:29:10 2017 Tamsi Besson
##

CC	=	gcc

RM      =	rm -f

NAME   =	depth

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
