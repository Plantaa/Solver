#ifndef DECK_H_
#define DECK_H_

#include "card.h"

#define MAX_CARDS 52
#define MAX_SUIT 4
#define MAX_RANK 13

typedef struct deck
{
    Card cards[MAX_CARDS];
} Deck;

void deckInit(Deck *deck);
void deckPrint(Deck *deck);
void deckFisherYatesShuffle(Deck *deck);
void deckFisherYatesShuffleMany(Deck *deck, int shuffleAmount);
void deckRiffleShuffle(Deck *deck);
void deckRiffleShuffleMany(Deck *deck, int shuffleAmount);
void deckOverhandShuffle(Deck *deck);
void deckOverheadShuffleMany(Deck *deck, int shuffleAmount);

#endif
