/*
** my.h for  in /home/tbesson/CPE_2016_getnextline
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Sun Jan 15 12:27:22 2017 Tamsi Besson
** Last update Thu Apr 27 16:02:36 2017 Tamsi Besson
*/
#ifndef DANTE_H_
#define DANTE_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int my_strlen(char *);
int my_strcmp(char *, char *);
int size_tab(char **);
char *my_strcat(char *, char *);
char *get_next_line(const int);
char **my_str_to_wordtab(char *, char);
char **malloc_map2d(int, int, char **);
char **draw_perfect(char **, int, int);
char **draw_imperfect(char **, int, int);
char **set_maze(int, int);
void my_put_nbr(int);
void my_putchar(char);
void my_putstr(char *);
void fd_putchar(char, int);
void fd_putstr(char *, int);
void fd_tab(char **, int);

#endif //DANTE_H_
