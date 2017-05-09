/*
** depth.h for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 16:36:21 2017 Tamsi Besson
** Last update Mon May  8 21:34:26 2017 Tamsi Besson
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

typedef struct s_pos
{
	int x;
	int y;
} t_pos;

typedef struct s_node
{
  int id;
  int visited;
  t_pos pos;
  struct s_node *next;
} t_node;

typedef struct s_list
{
	int members;
	t_node *node;
} t_list;

typedef struct s_graph
{
	int vertices;
	t_list *adjList;
} t_graph;

void fill_graph(char **, t_graph *);
int my_strlen(char *);
int count_vertices(char **);
char *my_strcat(char *, char *);
char *get_next_line(const int);
