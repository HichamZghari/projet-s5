#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stockex.h"

#define MAX_STOCKEX 100


static const struct stockex tab_stockex[MAX_STOCKEX] = {
  { "Catane", 2, {
{.achat = { .data = {10, 1, 3}} , .vente = {.data = {0, 1, 1}} }, 
{.achat = {.data = {10, 0, 1}}, .vente = {.data = {2, 0, 7}} } } }
};


const struct stockex* starting_stockex()
{
  return &(tab_stockex[0]);
}


const char* stockex_name(const struct stockex* s)
{
  return s->place;
}


size_t stockex__num_transactions(const struct stockex* t)
{
  return t->nombre_transactions;
}


const struct transac* stockex__transaction(const struct stockex* t, size_t num)
{
  return &(t->transactions[num]);
}


struct wallet transac__in_wallet(const struct transac* s)
{
  return s->achat;
}


struct wallet transac__out_wallet(const struct transac* s)
{
  return s->vente;
}
