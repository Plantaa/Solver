#ifndef DECK_H_
#define DECK_H_

#include "card.h"

#define MAX_CARDS 52
#define MAX_SUIT 4
#define MAX_RANK 13

typedef struct deck
{
    Card cards[MAX_CARDS];
    void (*shuffleStrategy)(struct deck *const deck, int shuffleAmount);
} Deck;

/*Initialization*/
void deckInit(Deck *const deck);
void deckInitWithStrategy(Deck *const deck, void (*shuffleStrategy)(Deck *, int));

/*Shuffling functions*/
void deckShuffle(Deck *const deck, int shuffleAmount);
void deckFisherYatesShuffle(Deck *const deck);
void deckRiffleShuffle(Deck *const deck);
void deckOverhandShuffle(Deck *const deck);
void deckFisherYatesShuffleMany(Deck *const deck, int shuffleAmount);
void deckRiffleShuffleMany(Deck *const deck, int shuffleAmount);
void deckOverheadShuffleMany(Deck *const deck, int shuffleAmount);

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
