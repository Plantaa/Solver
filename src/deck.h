#ifndef DECK_H_
#define DECK_H_

#include "card.h"

#define MAX_CARDS 52
#define MAX_SUIT 4
#define MAX_RANK 13

typedef struct deck
{
    Card cards[MAX_CARDS];
    void (*shuffleStrategy)(struct deck *deck, int shuffleAmount);
} Deck;

void deckInit(Deck *deck);
void deckInitWithStrategy(Deck *deck, void (*shuffleStrategy) (Deck *, int));
void deckPrint(Deck *deck);
void deckFisherYatesShuffle(Deck *deck);
void deckFisherYatesShuffleMany(Deck *deck, int shuffleAmount);
void deckRiffleShuffle(Deck *deck);
void deckRiffleShuffleMany(Deck *deck, int shuffleAmount);
void deckOverhandShuffle(Deck *deck);
void deckOverheadShuffleMany(Deck *deck, int shuffleAmount);
double deckCalculateDisplacement(Deck *original, Deck *shuffled);
int deckLongestOrderedRun(Deck *original, Deck *shuffled);
int deckCountAdjacentSuits(Deck *shuffled);
int deckCountPreservedPairs(Deck *original, Deck *shuffled);
void deckShufflingSumary(Deck *original, Deck *shuffled);
int deckFindIndex(Deck *deck, Card card);
void deckShuffle(Deck *deck, int shuffleAmount);

#endif
