#include <stdlib.h>
#include <stdio.h>

#include "rank.h"

char* rankString(Rank rank)
{
    switch (rank)
    {
    case ACE: return "ACE";
    case KING: return "KING";
    case QUEEN: return "QUEEN";
    case JACK: return "JACK";
    case TEN: return "TEN";
    case NINE: return "NINE";
    case EIGHT: return "EIGHT";
    case SEVEN: return "SEVEN";
    case SIX: return "SIX";
    case FIVE: return "FIVE";
    case FOUR: return "FOUR";
    case TRHEE: return "TRHEE";
    case TWO: return "TWO";
    default: return "";
    }
}
