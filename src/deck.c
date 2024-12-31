#include <stdio.h>
#include <stdlib.h>

#include "deck.h"

void deckInit(Deck *deck)
{
    int card = 0;
    for (Suit suit = 0; suit < MAX_SUIT; suit++)
        for (Rank rank = 0; rank < MAX_RANK; rank++)
            deck->cards[card++] = (Card){
                .rank = rank,
                .suit = suit};
}

void deckInitWithStrategy(Deck *deck, void (*shuffleStrategy) (Deck *, int))
{
    if (NULL == shuffleStrategy)
        deck->shuffleStrategy = deckOverheadShuffleMany;
    else
        deck->shuffleStrategy = shuffleStrategy;
    deckInit(deck);
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

    for (int i = 0; i < halfSize; i++)
    {
        half1.cards[i] = deck->cards[i];
        half2.cards[i] = deck->cards[halfSize + i];
    }
    int i = 0, j = 0, k = 0;
    while (i < halfSize && j < halfSize)
    {
        if (rand() % 2 == 0 && i < halfSize)
            deck->cards[k++] = half1.cards[i++];
        else
            deck->cards[k++] = half2.cards[j++];
    }
    while (i < halfSize)
        deck->cards[k++] = half1.cards[i++];
    while (j < halfSize)
        deck->cards[k++] = half2.cards[j++];
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

    while (newDeckIndex < MAX_CARDS)
    {
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

double deckCalculateDisplacement(Deck *original, Deck *shuffled) {
    double totalDisplacement = 0;
    for (int i = 0; i < MAX_CARDS; i++)
        totalDisplacement += abs(i - deckFindIndex(shuffled, original->cards[i]));
    return totalDisplacement / MAX_CARDS;
}

int deckFindIndex(Deck *deck, Card card) {
    for (int i = 0; i < MAX_CARDS; i++)
        if (cardIsEqual(deck->cards[i], card))
            return i;
    return -1;
}

int deckLongestOrderedRun(Deck *original, Deck *shuffled) {
    int longestRun = 0;
    int currentRun = 0;

    for (int i = 0; i < MAX_CARDS; i++) {
        if (cardIsEqual(original->cards[i], shuffled->cards[i])) {
            currentRun++;
            if (currentRun > longestRun)
                longestRun = currentRun;
        } else
            currentRun = 0;
    }
    return longestRun;
}

int deckCountAdjacentSuits(Deck *shuffled) {
    int adjacentCount = 0;
    for (int i = 0; i < MAX_CARDS - 1; i++)
        if (shuffled->cards[i].suit == shuffled->cards[i+1].suit)
            adjacentCount++;
    return adjacentCount;
}

int deckCountPreservedPairs(Deck *original, Deck *shuffled) {
    int preservedPairs = 0;
    for (int i = 0; i < MAX_CARDS - 1; i++)
        for (int j = i + 1; j < MAX_CARDS; j++)
            if (deckFindIndex(shuffled, original->cards[i]) < deckFindIndex(shuffled, original->cards[j]))
                    preservedPairs++;
    return preservedPairs;
} 

void deckShufflingSumary(Deck *original, Deck *shuffled)
{
    printf("Shuffling summary:\n");
    printf("\tDispacement: %f\n", deckCalculateDisplacement(original, shuffled));
    printf("\tLongest ordered run: %d\n", deckLongestOrderedRun(original, shuffled));
    printf("\tAdjacent cards from the same suit: %d\n", deckCountAdjacentSuits(shuffled));
    printf("\tPreserved relative pairs: %d\n", deckCountPreservedPairs(original, shuffled));
}

void deckShuffle(Deck* deck, int shuffleAmount)
{
    if (deck->shuffleStrategy != NULL)
        deck->shuffleStrategy(deck, shuffleAmount);
    else
        printf("No shuffle strategy provided!\n");
}
