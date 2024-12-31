#include <stdlib.h>
#include <stdio.h>

#include "suit.h"

char* suitString(Suit suit)
{
    switch (suit)
    {
    case CLUBS: return "CLUBS";
    case HEARTS: return "HEARTS";
    case SPADES: return "SPADES";
    case DIAMONDS: return "DIAMONDS";
    default: return "";
    }
}

bool suitIsLesser(Suit expected, Suit actual)
{
    return expected < actual;
}

bool suitIsGreater(Suit expected, Suit actual)
{
    return expected > actual;
}
