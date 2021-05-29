#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <math.h>
#include <time.h>
#include "good.h"
#include "stockex.h"
#include "queue.h"
#include "initialisation.h"

// Global seed for the random number generator
static int seed = 0;
static int players = 2;
static int turns = 1000;
static int max_transactions_number = 100;
static int max_party_time = 1000;
////////////////////////////////////////////////////////////////
// Function for parsing the options of the program
// Currently available options are :
// -s <seed> : sets the seed
void parse_opts(int argc, char* argv[]) {
  int opt;
  while ((opt = getopt(argc, argv, "s:n:m:")) != -1) {
    switch (opt) {
    case 's':
      seed = atoi(optarg);
      break;
    case 'n':
      players = atoi(optarg);
      break;
    case 'm':
      turns = atoi(optarg);
      break;
    default: /* '?' */
      fprintf(stderr,
	      "Usage: %s  \n",
              argv[0]);
      exit(EXIT_FAILURE);
    }
  }
}


int max_transactions_possible (const struct transac *transaction, struct teddy* teddy) {
  int i = 0;
  int profit = 0;
  long long array_good[MAX_GOOD];
  for (int k = 0; k < MAX_GOOD; k++) {
    array_good[k] = teddy->w.data[k];
  }
  while (i < max_transactions_number) {
    for (int j = 0; j < MAX_GOOD; j ++) {
      profit = (transac__in_wallet(transaction)).data[j] - (transac__out_wallet(transaction)).data[j];
      array_good[j] = array_good[j] + profit;
      if (array_good[j] < 0){
	return i;
      }
    }
    i ++;
  }
  return i;
}


void do_transactions(const struct transac* transaction, struct teddy* teddy, int n) {
  int profit = 0;
  for (int j = 0; j < MAX_GOOD; j ++) {
    profit = (transac__in_wallet(transaction)).data[j] - (transac__out_wallet(transaction)).data[j];
    teddy->w.data[j] = teddy->w.data[j] + n * profit;
  }
}


int active_teddy_play(struct teddy* teddy, const struct stockex* s) {
  int transaction_index = rand() % stockex__num_transactions(s);
  if(max_transactions_possible(stockex__transaction(s,transaction_index), teddy) == 0)
    return 1;
  int transactions_number = 1 + rand() % (max_transactions_possible(stockex__transaction(s, transaction_index),
								    teddy));
  do_transactions(stockex__transaction(s, transaction_index),
		  teddy,
		  transactions_number);
  return floor(1 + log(transactions_number) / log(2));
}


void display__results(struct queue* q) {
  int l = q->size;
  int index = 0;
  unsigned int max_honey = 0;
  unsigned int number_honey;
  for (int i = 0; i < l; i ++) {
    number_honey = 0;
    for (int j = 0; j < MAX_GOOD; j ++) {
      number_honey += good__value(j) * q->tab[i]->w.data[j];
    }
    if (number_honey>max_honey) {
      max_honey = number_honey;
      index = i;
    }
  }
  printf("Le teddy gagnant est %d, avec %d honey.\n",
	 q->tab[index]->name,
	 max_honey);
}

//////////////////////////////////////////
int main(int argc, char* argv[]) {
  parse_opts(argc, argv);
  printf("Seed : %d\n", seed);
  printf("players : %d\n", players);
  printf("turns : %d\n", turns);
  if (seed == 0)
    srand(time(NULL));
  else
    srand(seed);
  const struct stockex *s = starting_stockex();
  //initialiser une queue
  if (players > 20) {
    printf("le nombre de joueur doit etre inférieur ou égale 20\n");
    return 0;
  }
  struct queue queue = starting_queue(players);
  int global_time = 0;
  int time_spent = 0;
  int count = -1;
  while (global_time < max_party_time && count < turns) {
    struct teddy *active_teddy = queue__pop(&queue);
    global_time = active_teddy->time;
    time_spent = active_teddy_play(active_teddy, s);
    queue__push(&queue, global_time + time_spent, active_teddy);
    count++;
  };
  display__results(&queue);
  return 0;
}
