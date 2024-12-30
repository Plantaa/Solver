#ifndef CARD_H_
#define CARD_H_

#include "rank.h"
#include "suit.h"

typedef struct card {
    Rank rank;
    Suit suit;
}Card;

void cardPrint(Card card);

#endif
