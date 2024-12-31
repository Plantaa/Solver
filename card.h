#ifndef CARD_H_
#define CARD_H_

#include <stdbool.h>

#include "rank.h"
#include "suit.h"

typedef struct card
{
    Rank rank;
    Suit suit;
} Card;

void cardPrint(Card card);
bool cardIsEqual(Card expected, Card actual);

#endif
