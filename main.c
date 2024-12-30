#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deck.h"

int main() {
    srand((unsigned int)time(0));

    Deck originalDeck, shuffledDeck;
    deckInit(&originalDeck);
    deckInit(&shuffledDeck);

    printf("\nBefore shuffle: \n");
    deckPrint(&originalDeck);

    deckOverhandShuffle(&shuffledDeck);
    printf("\nAfter overhand shuffle: \n");
    deckPrint(&shuffledDeck);

    deckOverheadShuffleMany(&shuffledDeck, 12);
    printf("\nAfter 12 overhand shuffles: \n");
    deckPrint(&shuffledDeck);

    deckRiffleShuffle(&shuffledDeck);
    printf("\nAfter riffle shuffle: \n");
    deckPrint(&shuffledDeck);

    deckRiffleShuffleMany(&shuffledDeck, 7);
    printf("\nAfter 7 riffle shuffles: \n");
    deckPrint(&shuffledDeck);

    deckFisherYatesShuffle(&shuffledDeck);
    printf("\nAfter Fisher-Yates shuffle: \n");
    deckPrint(&shuffledDeck);

    deckFisherYatesShuffleMany(&shuffledDeck, 5);
    printf("\nAfter 5 Fisher-Yates shuffles: \n");
    deckPrint(&shuffledDeck);
    
    return 0;
}
