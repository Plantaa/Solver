#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 52

#include "shuffle.h"

void shuffle(Card *const cards, ShuffleStrategy strategy)
{
    for (int i = 0; i < strategy.iterations; i++)
        strategy.shuffle(cards);
}

void shuffleMany(Card *const cards, ShuffleStrategy strategy, int iterations)
{
    for (int i = 0; i < iterations; i++)
        shuffle(cards, strategy);
}

void fisherYatesShuffle(Card *const cards)
{
    for (int i = MAX_CARDS - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void riffleShuffle(Card *const cards)
{
    Card half1[MAX_CARDS], half2[MAX_CARDS];
    int halfSize = MAX_CARDS / 2;

    for (int i = 0; i < halfSize; i++)
    {
        half1[i] = cards[i];
        half2[i] = cards[halfSize + i];
    }
    int i = 0, j = 0, k = 0;
    while (i < halfSize && j < halfSize)
    {
        if (rand() % 2 == 0 && i < halfSize)
            cards[k++] = half1[i++];
        else
            cards[k++] = half2[j++];
    }
    while (i < halfSize)
        cards[k++] = half1[i++];
    while (j < halfSize)
        cards[k++] = half2[j++];
}

void overhandShuffle(Card *const cards)
{
    Card newDeck[MAX_CARDS];
    int newDeckIndex = 0;

    while (newDeckIndex < MAX_CARDS)
    {
        int chunkSize = (rand() % 5) + 1;
        if (newDeckIndex + chunkSize > MAX_CARDS)
            chunkSize = MAX_CARDS - newDeckIndex;
        for (int i = 0; i < chunkSize; i++)
            newDeck[newDeckIndex + i] = cards[MAX_CARDS - newDeckIndex - chunkSize + i];
        newDeckIndex += chunkSize;
    }
    for (int i = 0; i < MAX_CARDS; i++)
        cards[i] = newDeck[i];
}

void fisherYatesShuffleMany(Card *const cards, int iterations)
{
    for (int i = 0; i < iterations; i++)
        fisherYatesShuffle(cards);
}

void riffleShuffleMany(Card *const cards, int iterations)
{
    for (int i = 0; i < iterations; i++)
        riffleShuffle(cards);
}

void overhandShuffleMany(Card *const cards, int iterations)
{
    for (int i = 0; i < iterations; i++)
        overhandShuffle(cards);
}
