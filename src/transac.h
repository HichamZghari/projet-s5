#ifndef __TRANSAC_H
#define __TRANSAC_H
#include "good.h"

#define Max_transac 20


// The type representing transactions
struct transac{
  struct wallet achat;
  struct wallet vente;
};


// The type representing stock exchanges
struct stockex{
  char* place;
  int nombre_transactions;
  struct transac transactions[Max_transac];
};


#endif
