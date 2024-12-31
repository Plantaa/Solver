#include <stdlib.h>
#include <stdio.h>

#include "card.h"

void cardPrint(Card card)
{
    printf("%s of %s\n", rankString(card.rank), suitString(card.suit));
}

bool cardIsEqual(Card expected, Card actual)
{
    return expected.rank == actual.rank && expected.suit == actual.suit;
}

bool cardIsLesser(Card expected, Card actual)
{
    return suitIsLesser(expected.suit, actual.suit) && rankIsLesser(expected.rank, actual.rank);
}

bool cardIsGreater(Card expected, Card actual)
{
    return suitIsGreater(expected.suit, actual.suit) && rankIsGreater(expected.rank, actual.rank);
}