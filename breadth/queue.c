/*
** queue.c for  in /home/tbesson/projet_cpe/dante/breadth
** 
** Made by Tamsi Besson
** Login   <tbesson@epitech.net>
** 
** Started on  Tue May  9 18:01:05 2017 Tamsi Besson
** Last update Thu May 11 19:18:22 2017 Tamsi Besson
*/

#include "breadth.h"

void initQueue(t_queue *q)
{
   q->head = NULL;
   q->tail = NULL;
}

void enqueue(t_queue *q, t_graph *graph, int v)
{
   t_elemQueue *newElement;
   newElement = (t_elemQueue *) malloc(sizeof(t_elemQueue));
   newElement->value = graph->adjList[v].node;
   newElement->next = NULL;
   if (q->head == NULL)
   {
		q->head = newElement;
		q->tail = newElement;
   }
   else
   {
      q->tail->next = newElement;
      q->tail = newElement;
   }
}

void dequeue(t_queue *q)
{
   t_elemQueue *element;

   if (q->head == NULL)
      return;
   else
   {
      element = q->head;
      q->head = q->head->next;
      free(element);
   }
}

t_node *front(t_queue *q)
{
	return (q->head->value);
}

int ifEmpty(t_queue *q)
{
  return (q->head == NULL ? 1:0);
}