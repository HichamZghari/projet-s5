#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include "stockex.h"

#define MAX 20


struct teddy {
  int good_total_value;
  int name;
  struct wallet w;
  int time;
};


struct queue {
    int size;
    struct teddy* tab[MAX];
};


struct queue queue__create();


int index_of_teddy(struct queue* q,struct teddy* teddy);


void queue__push(struct queue* q, int priority, struct teddy* teddy);


struct teddy* queue__top(struct queue* q);


struct teddy* queue__pop(struct queue* q);


#endif
