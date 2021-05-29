#ifndef __GOOD_H
#define __GOOD_H

// An enumeration of the existing goods
enum good {
           HONEY,           // Always first
           MONKEY_WRENCH,
           OUTBOARD_MOTOR,
           MAX_GOOD = 3,        // Always last
           ERROR_GOOD = -1, // Always -1
};


// A description of a good
const char* good__string(enum good g);


// The base value of a good (in equivalent-Honey)
unsigned int good__value(enum good g);


// A wallet containing different amounts of goods
struct wallet {
  unsigned int data[MAX_GOOD];
};


#endif
