#ifndef __STOCKEX_H
#define __STOCKEX_H
#include "transac.h"
#include <string.h>


// The type representing stock exchanges
struct stockex;


// The type representing transactions
struct transac;


// The starting stock exchange
const struct stockex* starting_stockex();


// The name of the stock exchange
const char*           stockex_name(const struct stockex* s);


// Iterator on transactions : the first function returns the number
// `n` of available transactions, and the second accesses them with
// indices ranging between 0 and n-1.
size_t                stockex__num_transactions(const struct stockex* t);


const struct transac* stockex__transaction(const struct stockex* t, size_t num);


// The goods bought by the stock exchange
struct wallet         transac__in_wallet(const struct transac* s);


// The goods sold by the stock exchange
struct wallet         transac__out_wallet(const struct transac* s);


#endif
