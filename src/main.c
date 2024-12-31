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

    deckFisherYatesShuffle(&shuffledDeck);
    printf("After single Fisher-Yates shuffle: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckFisherYatesShuffleMany(&shuffledDeck, 5);
    printf("After 5 Fisher-Yates shuffles: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckOverhandShuffle(&shuffledDeck);
    printf("After single overhand shuffle: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckOverheadShuffleMany(&shuffledDeck, 13);
    printf("After 13 overhand shuffles: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckOverheadShuffleMany(&shuffledDeck, 14);
    printf("After 14 overhand shuffles: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckRiffleShuffle(&shuffledDeck);
    printf("After single riffle shuffle: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckRiffleShuffleMany(&shuffledDeck, 7);
    printf("After 7 riffle shuffles: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInitWithStrategy(&shuffledDeck, deckFisherYatesShuffleMany);
    deckShuffle(&shuffledDeck, 1);
    printf("After shuffle with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    return 0;
}
