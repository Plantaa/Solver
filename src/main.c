#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deck.h"

int main()
{
    srand((unsigned int)time(0));

    Deck originalDeck, shuffledDeck;
    deckInit(&originalDeck);

    deckInit(&shuffledDeck);
    fisherYatesShuffle(shuffledDeck.cards);
    printf("After single Fisher-Yates shuffle:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    fisherYatesShuffleMany(shuffledDeck.cards, 7);
    printf("After 7 Fisher-Yates shuffles:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInitWithStrategy(&shuffledDeck, overhandShuffle);
    deckShuffle(&shuffledDeck);
    printf("After single overhand shuffle with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInitWithStrategy(&shuffledDeck, overhandShuffle);
    deckShuffleMany(&shuffledDeck, 7);
    printf("After 7 overhand shuffles with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    shuffle(shuffledDeck.cards, riffleShuffle);
    printf("After single riffle shuffle with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    shuffleMany(shuffledDeck.cards, riffleShuffle, 7);
    printf("After 7 riffle shuffles with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    return 0;
}
