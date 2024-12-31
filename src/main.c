#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "deck.h"
#include "shuffle.h"

int main()
{
    srand((unsigned int)time(0));

    Deck originalDeck, shuffledDeck;
    deckInit(&originalDeck);
    deckInit(&shuffledDeck);

    deckInitWithStrategy(&shuffledDeck, fisherYatesShuffleMany);
    shuffle(shuffledDeck.cards, shuffledDeck.shuffleStrategy, 1);
    printf("After shuffle with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInitWithStrategy(&shuffledDeck, riffleShuffleMany);
    shuffle(shuffledDeck.cards, shuffledDeck.shuffleStrategy, 1);
    printf("After shuffle with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    deckInitWithStrategy(&shuffledDeck, overheadShuffleMany);
    shuffle(shuffledDeck.cards, shuffledDeck.shuffleStrategy, 1);
    printf("After shuffle with strategy:\n");
    deckShufflingSumary(&originalDeck, &shuffledDeck);

    return 0;
}
