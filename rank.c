#include <stdlib.h>
#include <stdio.h>

#include "rank.h"

void rankPrint(Rank rank)
{
    switch (rank)
    {
    case ACE:
        printf("ACE");
        break;
    case KING:
        printf("KING");
        break;
    case QUEEN:
        printf("QUEEN");
        break;
    case JACK:
        printf("JACK");
        break;
    case TEN:
        printf("TEN");
        break;
    case NINE:
        printf("NINE");
        break;
    case EIGHT:
        printf("EIGHT");
        break;
    case SEVEN:
        printf("SEVEN");
        break;
    case SIX:
        printf("SIX");
        break;
    case FIVE:
        printf("FIVE");
        break;
    case FOUR:
        printf("FOUR");
        break;
    case TRHEE:
        printf("TRHEE");
        break;
    case TWO:
        printf("TWO");
        break;
    default:
        break;
    }
}

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
