#ifndef SUIT_H_
#define SUIT_H_

#include <stdbool.h>

typedef enum suit {
    CLUBS,
    HEARTS,
    SPADES,
    DIAMONDS
}Suit;

char* suitString(Suit suit);
bool suitIsLesser(Suit expected, Suit actual);
bool suitIsGreater(Suit expected, Suit actual);

#endif
