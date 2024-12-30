#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deck.h"

int main() {
    srand((unsigned int)time(0));

    Deck originalDeck, shuffledDeck;
    deckInit(&originalDeck);
    deckInit(&shuffledDeck);

    printf("Before shuffle: \n");
    deckPrint(&originalDeck);

    deckOverhandShuffle(&shuffledDeck);
    printf("After overhand shuffle: \n");
    deckPrint(&shuffledDeck);

    deckOverheadShuffleMany(&shuffledDeck, 12);
    printf("After 12 overhand shuffles: \n");
    deckPrint(&shuffledDeck);

    deckRiffleShuffle(&shuffledDeck);
    printf("After riffle shuffle: \n");
    deckPrint(&shuffledDeck);

    deckRiffleShuffleMany(&shuffledDeck, 7);
    printf("After 7 riffle shuffles: \n");
    deckPrint(&shuffledDeck);

    deckShuffle(&shuffledDeck);
    printf("After shuffle: \n");
    deckPrint(&shuffledDeck);

    deckShuffleMany(&shuffledDeck, 5);
    printf("After 5 passes: \n");
    deckPrint(&shuffledDeck);
    
    return 0;
}
