/*
** graph.c for  in /home/tbesson/projet_cpe/dante/depth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Fri May  5 17:59:21 2017 Tamsi Besson
** Last update Sun May 14 22:09:28 2017 Tamsi Besson
*/

#include "depth.h"

t_node *createNode(int v)
{
  t_node *newNode;

  newNode = malloc(sizeof(t_node *));
  newNode->id = v;
  newNode->visited = 1;
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

  if (graph)
    {
      if (graph->adjList)
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

void addEdge(t_graph *graph, int src, int dest, t_pos pos)
{
  t_node *newNode;

  newNode = createNode(dest);
  newNode->next = graph->adjList[src].node;
  graph->adjList[src].node = newNode;
  graph->adjList[src].node->pos = pos;
  graph->adjList[src].members++;
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
