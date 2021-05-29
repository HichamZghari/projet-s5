#include "good.h"


const char* good__string(enum good g)
{
  char* desc = "";
  switch (g) {
  case HONEY :
    desc = "Honey";
    break;
  case MONKEY_WRENCH :
    desc = "Monkey Wrench";
    break;
  case OUTBOARD_MOTOR :
    desc = "Outboard Motor";
    break;
  default :
    desc = "Error good";
    break;
  }
  return desc;
}


unsigned int good__value(enum good g)
{
  int value = 0;
  switch (g) {
  case HONEY :
    value = 1;
    break;
  case MONKEY_WRENCH :
    value = 10;
    break;
  case OUTBOARD_MOTOR :
    value = 20;
    break;
  default :
    return 0;
    break;
  }
  return value;
}
