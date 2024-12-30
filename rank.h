#ifndef RANK_H_
#define RANK_H_

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

void rankPrint(Rank rank);
char* rankString(Rank rank);

#endif
