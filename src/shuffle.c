#include <stdio.h>
#include <stdlib.h>

#include "shuffle.h"

void shuffle(Card *const cards, ShuffleStrategy strategy, int iterations)
{
    if (strategy != NULL)
        strategy(cards, iterations);
    else
        printf("No shuffle strategy provided!\n");
}

void fisherYatesShuffle(Card *const cards)
{
    for (int i = 52 - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void riffleShuffle(Card *const cards)
{
    Card half1[52], half2[52];
    int halfSize = 52 / 2;

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
    Card newDeck[52];
    int newDeckIndex = 0;

    while (newDeckIndex < 52)
    {
        int chunkSize = (rand() % 5) + 1;
        if (newDeckIndex + chunkSize > 52)
            chunkSize = 52 - newDeckIndex;
        for (int i = 0; i < chunkSize; i++)
            newDeck[newDeckIndex + i] = cards[52 - newDeckIndex - chunkSize + i];
        newDeckIndex += chunkSize;
    }
    for (int i = 0; i < 52; i++)
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

void overheadShuffleMany(Card *const cards, int iterations)
{
    for (int i = 0; i < iterations; i++)
        overhandShuffle(cards);
}
