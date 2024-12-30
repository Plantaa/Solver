#include <stdlib.h>
#include <stdio.h>

#include "suit.h"

void suitPrint(Suit suit)
{
    switch (suit)
    {
    case CLUBS:
        printf("CLUBS");
        break;
    case HEARTS:
        printf("HEARTS");
        break;
    case SPADES:
        printf("SPADES");
        break;
    case DIAMONDS:
        printf("DIAMONDS");
        break;
    default:
        break;
    }
}

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
