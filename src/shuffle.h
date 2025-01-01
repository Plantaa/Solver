#ifndef SHUFFLE_H_
#define SHUFFLE_H_

#include "card.h"

typedef struct shuffleStrategy
{
    void (*shuffle)(Card *const cards);
    int iterations;
} ShuffleStrategy;

void shuffle(Card *const cards, ShuffleStrategy strategy);
void shuffleMany(Card *const cards, ShuffleStrategy strategy, int iterations);
void fisherYatesShuffle(Card *const cards);
void riffleShuffle(Card *const cards);
void overhandShuffle(Card *const cards);
void fisherYatesShuffleMany(Card *const cards, int iterations);
void riffleShuffleMany(Card *const cards, int iterations);
void overhandShuffleMany(Card *const cards, int iterations);

#endif
