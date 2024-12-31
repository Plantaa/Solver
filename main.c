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

    deckFisherYatesShuffle(&shuffledDeck);
    printf("After second Fisher-Yates shuffle: \n");
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
    deckOverheadShuffleMany(&shuffledDeck, 12);
    printf("After 12 overhand shuffles: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckRiffleShuffle(&shuffledDeck);
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInit(&shuffledDeck);
    deckRiffleShuffleMany(&shuffledDeck, 7);
    printf("After 7 riffle shuffles: \n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    return 0;
}
