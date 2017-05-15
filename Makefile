##
## Makefile for dante in home/tbesson/projet_cpe/dante/depth
## 
## Made by Besson Tamsi
## Login   <tamsi.besson@epitech.eu>
## 
## Started on  Mon Apr 24 09:49:40 2015 Tamsi Besson
## Last update Sun May 14 22:23:56 2017 Tamsi Besson
##

RM      =	rm -f

all	:
		make -s -C breadth/
		make -s -C depth/
		make -s -C generator/
		make -s -C tournament/

clean	:
		make clean -s -C breadth/
		make clean -s -C depth/
		make clean -s -C generator/
		make clean -s -C tournament/

fclean	:	clean
		make fclean -s -C breadth/
		make fclean -s -C depth/
		make fclean -s -C generator/
		make fclean -s -C tournament/

re	:	fclean all

.PHONY	:	all clean fclean re
