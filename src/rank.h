#ifndef RANK_H_
#define RANK_H_

#include <stdbool.h>

typedef enum rank {
    ACE,
    KING,
    QUEEN,
    JACK,
    TEN,
    NINE,
    EIGHT,
    SEVEN,
    SIX,
    FIVE,
    FOUR,
    TRHEE,
    TWO,
    ONE
}Rank;

char* rankString(Rank rank);
bool rankIsLesser(Rank expected, Rank actual);
bool rankIsGreater(Rank expected, Rank actual);

#endif
