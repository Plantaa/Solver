#ifndef DECK_H_
#define DECK_H_

#include "card.h"
#include "shuffle.h"

#define MAX_CARDS 52
#define MAX_SUIT 4
#define MAX_RANK 13

typedef struct deck
{
    Card cards[MAX_CARDS];
    ShuffleStrategy shuffleStrategy;
} Deck;

/*Initialization*/
void deckInit(Deck *const deck);
void deckInitWithStrategy(Deck *const deck, ShuffleStrategy shuffleStrategy);

/*Shuffle*/
void deckShuffle(Deck *const deck);
void deckShuffleMany(Deck *const deck, int iterations);

/*Shuffling metrics*/
double deckCalculateDisplacement(const Deck *const original, const Deck *const shuffled);
int deckLongestOrderedRun(const Deck *const original, const Deck *const shuffled);
int deckCountAdjacentSuits(const Deck *const shuffled);
int deckCountPreservedPairs(const Deck *const original, const Deck *const shuffled);
void deckShufflingSumary(const Deck *const original, const Deck *const shuffled);

/*Utils*/
void deckPrint(const Deck *const deck);
int deckFindIndex(const Deck *const deck, Card card);

#endif
