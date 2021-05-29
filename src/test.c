#include <getopt.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include "good.c"
#include "stockex.h"
#include "queue.h"
static int max_transactions_number = 100;

int max_transactions_possible1 (struct transac* transaction, struct teddy* t) {
  int i = 0;
  int array_good[MAX_GOOD];
  for ( int k = 0; k < MAX_GOOD; k++) {
    array_good[k] = t->w.data[k];
  }
  while (i < max_transactions_number) {
    for (int j = 0; j< MAX_GOOD; j++){
      array_good[j] = array_good[j] + ((transaction)->achat.data[j]) - (transaction->vente.data[j]);
      if (array_good[j] < 0){
	return i  ;
      }
    }
    i ++;
  }
  return i;
}
int max_transactions_possible2 (struct transac* transaction, struct teddy* t) {
  int i = 0;
  int array_good[MAX_GOOD];
  for ( int k = 0; k < MAX_GOOD; k++) {
    array_good[k] = t->w.data[k];
  }
  while (i < max_transactions_number) {
    for (int j = 0; j< MAX_GOOD; j++){
      array_good[j] = array_good[j] + ((&transaction->achat)->data[j]) - ((&transaction->vente)->data[j]);
      if (array_good[j] < 0){
	return i  ;
      }
    }
    i ++;
  }
  return i;
}

int main(){
  struct wallet wallet1;
  wallet1.data[0]=100;
  wallet1.data[1]=17;
  wallet1.data[2]=0;
  struct wallet wallet2;
  wallet2.data[0]=80;
  wallet2.data[1]=6;
  wallet2.data[2]=78;
  struct wallet wallet3;
  wallet3.data[0]=99;
  wallet3.data[1]=0;
  wallet3.data[2]=7;
  struct teddy teddy1;
  teddy1.good_total_value=90;
  teddy1.name="Michel";
  teddy1.w=wallet1;
  teddy1.time=0;
  struct teddy teddy2;
  teddy2.good_total_value=120;
  teddy2.name="Léo";
  teddy2.w=wallet2;
  teddy2.time=0;
  struct teddy teddy3;
  teddy3.good_total_value=105;
  teddy3.name="Marie";
  teddy3.w=wallet3;
  teddy3.time=0;
  /* struct queue queue; */
  /* queue.size = 3; */
  /* queue.tab[0] = &teddy1; */
  /* queue.tab[1] = &teddy2; */
  /* queue.tab[2] = &teddy3; */
  struct transac tr;
  tr.achat.data[0]=10;
  tr.achat.data[1]=1;
  tr.achat.data[2]=0;
  tr.vente.data[0]=0;
  tr.vente.data[1]=0;
  tr.vente.data[2]=1;
  /* struct transac tr2; */
  /* tr2.achat.data[0]=0; */
  /* tr2.achat.data[1]=0; */
  /* tr2.achat.data[2]=1; */
  /* tr2.vente.data[0]=20; */
  /* tr2.vente.data[1]=0;  */
  /* tr2.vente.data[2]=0; */
  printf("max1:%d\n",max_transactions_possible1(&tr,&teddy1));
  printf("max1:%d\n",max_transactions_possible2(&tr,&teddy1));
  printf("max1:%d\n",max_transactions_possible1(&tr,&teddy2));
  printf("max1:%d\n",max_transactions_possible2(&tr,&teddy2));
  printf("max1:%d\n",max_transactions_possible1(&tr,&teddy3));
  printf("max1:%d\n",max_transactions_possible2(&tr,&teddy3));
  return 0;
}
