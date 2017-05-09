##
## Makefile for dante in home/tbesson/projet_cpe/dante/gen
## 
## Made by Besson Tamsi
## Login   <tamsi.besson@epitech.eu>
## 
## Started on  Mon Apr 24 09:49:40 2015 Tamsi Besson
## Last update Thu Apr 27 16:07:21 2017 Tamsi Besson
##

CC	=	gcc

RM      =	rm -f

NAME   =	generator

SRC  	=	main.c \
		perfect.c \
		src/my_strcat.c \
		src/str.c \
		src/tab.c \
		src/x_fonction.c

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
