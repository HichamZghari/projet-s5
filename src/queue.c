#include "queue.h"
#define MAX 20
#include<stdio.h>


static struct queue qq;


struct queue queue__create()
{
    struct queue *q = &qq;
    q->size = 0;
    return qq;
}


int index_of_teddy(struct queue* q,struct teddy* teddy)
{
  int i = 0;
  while(i < q->size && ((q->tab[i]->time) <= (teddy->time))) {
    i ++;
  }
  return i;
}


void queue__push(struct queue* q, int priority, struct teddy* teddy)
{
  teddy->time = priority;
  int tour = index_of_teddy(q, teddy);
    if (q->size < MAX) {
        int i = q->size - 1;
        while (i >= tour) {
            q->tab[i + 1] = q->tab[i];
            i = i - 1;
        }
	q-> size ++;
        q->tab[tour] = teddy;
    } else {
        printf("La queue est pleine\n");
    }
}


struct teddy* queue__top(struct queue* q)
{
    if (q->size != 0) {
        return q->tab[0];
    } else {
      return NULL;
    }
}

struct teddy* queue__pop(struct queue* q)
{
    struct teddy* top = queue__top(q);
    if (q->size != 0) {
        int i = 0;
        while (i < q->size) {
            q->tab[i] = q->tab[i + 1];
            i = i + 1;
        }
	q->tab[i] = NULL;
	q->size = q->size - 1;
    } else {
        printf("La queue est vide\n");
    }
    return top;
}
