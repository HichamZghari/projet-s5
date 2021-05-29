#include "initialisation.h"
#include "transac.h"
#include "stockex.h"
#include "queue.h"


#define MAX_TEDDY 20


//initialiser un wallet
static struct wallet wallet1 = { {500, 30, 10} };


//initialiser un teddy
static struct teddy teddy1;


static struct teddy tab_teddy[MAX_TEDDY];


static struct queue queue;


struct teddy starting_teddy() {
  teddy1.good_total_value = 1000;
  teddy1.w = wallet1;
  teddy1.time = 0;
  teddy1.name = 0;
  return teddy1;
}


struct queue starting_queue(int n) {
  queue = queue__create();
  for (int i = 0; i < n; i ++) {
    queue.size ++;
    tab_teddy[i] = starting_teddy();
    tab_teddy[i].name = i;
    queue.tab[i] = &(tab_teddy[i]);
  }
  return queue;
}
    
