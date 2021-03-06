/*
** depth.h for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Thu Apr 27 16:36:21 2017 Tamsi Besson
** Last update Sun May 14 22:00:08 2017 Tamsi Besson
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

typedef struct s_elemQueue
{
  t_node *value;
  int prev;
  struct s_elemQueue *next;
} t_elemQueue;

typedef struct s_queue
{
  t_elemQueue *head;
  t_elemQueue *tail;
} t_queue;

void fill_graph(char **, t_graph *);
void initQueue(t_queue *);
void enqueue(t_queue *, t_node *, int);
void dequeue(t_queue *);
void destroyGraph(t_graph *);
void addEdge(t_graph *, int, int, t_pos);
void fill_graph(char **, t_graph *);
int my_strlen(char *);
int count_vertices(char **);
int ifEmpty(t_queue *);
int previous(t_queue *);
char *my_strcat(char *, char *);
char *get_next_line(const int);
t_node *front(t_queue *);
t_node *createNode(int);
t_graph *createGraph(int);
