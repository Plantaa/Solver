#include <stdio.h>
#include <stdlib.h>

#include "deck.h"

void deckInit(Deck* deck)
{
    int card = 0;
    for (Suit suit = 0; suit < MAX_SUIT; suit++)
    {
        for (Rank rank = 0; rank < MAX_RANK; rank++)
        {
            deck->cards[card++] = (Card){
                .rank = rank,
                .suit = suit
            };
        }
    }
}

void deckPrint(Deck *deck)
{
    for (int i = 0; i < MAX_CARDS; i++)
        cardPrint(deck->cards[i]);
}

void deckFisherYatesShuffle(Deck *deck)
{
    for (int i = MAX_CARDS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void deckFisherYatesShuffleMany(Deck *deck, int shuffleAmount)
{
    for (int i = 0; i < shuffleAmount; i++)
        deckFisherYatesShuffle(deck);
}

void deckRiffleShuffle(Deck *deck)
{
    Deck half1, half2;
    int halfSize = MAX_CARDS / 2;

    for (int i = 0; i < halfSize; i++) {
        half1.cards[i] = deck->cards[i];
        half2.cards[i] = deck->cards[halfSize + i];
    }

    int i = 0, j = 0, k = 0;
    while (i < halfSize && j < halfSize) {
        if (rand() % 2 == 0 && i < halfSize)
            deck->cards[k++] = half1.cards[i++];
        else
            deck->cards[k++] = half2.cards[j++];
    }

    while (i < halfSize) {
        deck->cards[k++] = half1.cards[i++];
    }
    while (j < halfSize) {
        deck->cards[k++] = half2.cards[j++];
    }
}

void deckRiffleShuffleMany(Deck *deck, int shuffleAmount)
{
    for (int i = 0; i < shuffleAmount; i++)
        deckRiffleShuffle(deck);
}

void deckOverhandShuffle(Deck *deck)
{
    Deck newDeck;
    int newDeckIndex = 0;

    while (newDeckIndex < MAX_CARDS) {
        int chunkSize = (rand() % 5) + 1;
        if (newDeckIndex + chunkSize > MAX_CARDS)
            chunkSize = MAX_CARDS - newDeckIndex;
        for (int i = 0; i < chunkSize; i++)
            newDeck.cards[newDeckIndex + i] = deck->cards[MAX_CARDS - newDeckIndex - chunkSize + i];
        newDeckIndex += chunkSize;
    }
    for (int i = 0; i < MAX_CARDS; i++)
        deck->cards[i] = newDeck.cards[i];
}

void deckOverheadShuffleMany(Deck *deck, int shuffleAmount)
{
    for (int i = 0; i < shuffleAmount; i++)
        deckOverhandShuffle(deck);
}
