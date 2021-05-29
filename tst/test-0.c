#include "../src/good.h"
#include "../src/transac.h"
#include "../src/stockex.h"
#include "../src/queue.h"
#include "../src/initialisation.h"


int main(int argc, char* argv[])
{
  //1-test des fonctions de good.c
  printf("1-test des fonctions de good.c\n");
  printf("------------------------------------------------\n");
  printf("Le nom de la première ressource est %s\n",good__string(HONEY));
  printf("la valeur de MONKEY_WRENCH est %d\n",good__value(MONKEY_WRENCH));
  printf("\n");
  printf("\n");

  
  //2-test des fonctions de stockex.c
  printf("2-test des fonctions de stockex.c\n");
  printf("------------------------------------------------\n");
  const struct stockex* s = starting_stockex();
  printf("la nom du stockex est %s\n", stockex_name(s));
  printf("le nombre de transactions dans la place %s est: %d\n", stockex_name(s),(int)stockex__num_transactions(s));
  const struct transac* t = stockex__transaction(s, 0);
  struct wallet achat = transac__in_wallet(t);
  struct wallet vente = transac__out_wallet(t);
  printf("Le nombre de honey à donner est: %d\n", achat.data[0]);
  printf("Le nombre de honey à recevoir est: %d\n", vente.data[0]);
  printf("\n");
  printf("\n");

  
  //3-test des fonctions de queue.c et initialisation.c
  printf("3-test des fonctions de queue.c et initialisation.c\n");
  printf("------------------------------------------------\n");
  struct queue q = queue__create();
  struct teddy t0 = starting_teddy();
  queue__push(&q, 1, &t0);
  printf("Le premier teddy aprés le premier push est le teddy %d\n", q.tab[0]->name);
  struct teddy t1 = starting_teddy();
  t1.name = 1;
  queue__push(&q, 0, &t1);
  printf("Le premier teddy aprés le deuxième push est le teddy %d\n", q.tab[0]->name);
  printf("Donc, après deux push le nombre de teddy actuel est %d\n", q.size);
  struct teddy* t3 = queue__pop(&q);
  printf("Le teddy du premier pop est le teddy %d\n", t3->name);
  t3 = queue__pop(&q);
  printf("Le teddy du top est le teddy %d\n", t3->name);
  struct queue queue = starting_queue(4);
  printf("La queue de starting_queue(4) est une queue de taille %d\n",queue.size);
    
  printf("%d,%s\n",argc,argv[1]); //pour éviter unused parametres
  return 0;
  
}
