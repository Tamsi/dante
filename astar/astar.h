/*
** depth.h for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 16:36:21 2017 Tamsi Besson
** Last update Fri Apr 28 18:53:36 2017 Yoann Kersulec
*/

#ifndef ASTAR_H
# define ASTAR_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>

int my_strlen(char *);
char *my_strcat(char *, char *);
char *get_next_line(const int);

typedef struct	s_node
{
  sfVector2i	pos;
  char		carac;
  struct t_node	*child[3];
  
}		t_node;

#endif
