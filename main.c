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
    double displacement = deckCalculateDisplacement(&originalDeck, &shuffledDeck);
    printf("Dispacement after single Fisher-Yates shuffle: %f\n", displacement);

    deckInit(&shuffledDeck);
    deckFisherYatesShuffleMany(&shuffledDeck, 5);
    displacement = deckCalculateDisplacement(&originalDeck, &shuffledDeck);
    printf("Dispacement after 5 Fisher-Yates shuffles: %f\n", displacement);

    deckInit(&shuffledDeck);
    deckOverhandShuffle(&shuffledDeck);
    displacement = deckCalculateDisplacement(&originalDeck, &shuffledDeck);
    printf("Dispacement after single overhand shuffle: %f\n", displacement);

    deckInit(&shuffledDeck);
    deckOverheadShuffleMany(&shuffledDeck, 12);
    displacement = deckCalculateDisplacement(&originalDeck, &shuffledDeck);
    printf("Dispacement after 12 overhand shuffles: %f\n", displacement);

    deckInit(&shuffledDeck);
    deckRiffleShuffle(&shuffledDeck);
    displacement = deckCalculateDisplacement(&originalDeck, &shuffledDeck);
    printf("Dispacement for single riffle shuffle: %f\n", displacement);

    deckInit(&shuffledDeck);
    deckRiffleShuffleMany(&shuffledDeck, 7);
    displacement = deckCalculateDisplacement(&originalDeck, &shuffledDeck);
    printf("Dispacement for 7 riffle shuffles: %f\n", displacement);

    return 0;
}
