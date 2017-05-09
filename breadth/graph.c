/*
** graph.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri May  5 17:59:21 2017 Tamsi Besson
** Last update Sun May  7 19:59:14 2017 Tamsi Besson
*/

#include "breadth.h"

t_node *createNode(int v)
{
  t_node *newNode;

  newNode = malloc(sizeof(t_node *));
  newNode->id = v;
  return (newNode);
}

t_graph *createGraph(int n)
{
  int i;

  i = 0;
  t_graph *graph = malloc(sizeof(t_graph *));
  graph->vertices = n;

  graph->adjList = malloc(n * sizeof(t_list));

  while (i < n)
    {
      graph->adjList[i].node = NULL;
      graph->adjList[i].members = 0;
      i++;
    }

  return (graph);
}

void destroyGraph(t_graph * graph)
{
  int v;
  t_node *adjListPtr;
  t_node *tmp;

  if(graph)
    {
      if(graph->adjList)
      {
        v = 0;
        while (v < graph->vertices)
        {
          adjListPtr = graph->adjList[v].node;
          while (adjListPtr)
          {
            tmp = adjListPtr;
            adjListPtr = adjListPtr->next;
            free(tmp);
          }
          v++;
        }
        free(graph->adjList);
      }
      free(graph);
    }
}

void addEdge(t_graph *graph, int src, int dest)
{
  t_node *newNode;

  newNode = createNode(dest);
  newNode->next = graph->adjList[src].node;
  graph->adjList[src].node = newNode;
  graph->adjList[src].members++;
  // newNode = createNode(src);
  // newNode->next = graph->adjList[dest].node;
  // graph->adjList[dest].node = newNode;
  // graph->adjList[dest].members++;
}

void displayGraph(t_graph *graph)
{
  int i;
  t_node *adjListPtr;

  i = 0;
  while (i < graph->vertices)
  {
    adjListPtr = graph->adjList[i].node;
    printf("\n%d: ", i);
    while (adjListPtr)
    {
      printf("%d->", adjListPtr->id);
      adjListPtr = adjListPtr->next;
    }
    printf("NULL\n");
    i++;
  }
}

int count_vertices(char **maze)
{
  int i;
  int size;

  i = 0;
  size = 0;
  while (maze[i])
    {
      size += my_strlen(maze[i]);
      i++;
    }
  return (size);
}

void fill_graph(char **maze, t_graph *graph)
{
  t_pos pos;

  pos.y = 0;
  while (maze[pos.y])
  {
    pos.x = 0;
    while (maze[pos.y][pos.x])
    {
      if (maze[pos.y][pos.x] == '*')
        {
          if (maze[pos.y][pos.x + 1] != '\0')
            if (maze[pos.y][pos.x + 1] == '*')
              addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                pos.y * my_strlen(maze[pos.y]) + pos.x + 1
              );
          if (maze[pos.y + 1] != NULL)
            if (maze[pos.y + 1][pos.x] == '*')
              addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                (pos.y + 1)* my_strlen(maze[pos.y]) + pos.x
              );
          if (pos.x > 0)
            if (maze[pos.y][pos.x - 1] == '*')
              addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                pos.y * my_strlen(maze[pos.y]) + pos.x - 1
              );
          if (pos.y > 0)
            if (maze[pos.y - 1][pos.x] == '*')
              addEdge(
                graph,
                pos.y * my_strlen(maze[pos.y]) + pos.x,
                (pos.y - 1)* my_strlen(maze[pos.y]) + pos.x
              );
        }
      pos.x++;
    }
    pos.y++;
  }
}
