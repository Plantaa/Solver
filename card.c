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