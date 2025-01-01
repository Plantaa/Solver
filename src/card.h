#ifndef CARD_H_
#define CARD_H_

#include <stdbool.h>

#include "rank.h"
#include "suit.h"

#define INVALID_CARD (Card){-1,-1}

typedef struct card
{
    Rank rank;
    Suit suit;
} Card;

void cardPrint(Card card);
bool cardIsEqual(Card expected, Card actual);
bool cardIsLesser(Card expected, Card actual);
bool cardIsGreater(Card expected, Card actual);

#endif
