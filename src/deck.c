#include <stdio.h>
#include <stdlib.h>

#include "deck.h"

void deckInit(Deck *const deck)
{
    int card = 0;
    for (Suit suit = 0; suit < MAX_SUIT; suit++)
        for (Rank rank = 0; rank < MAX_RANK; rank++)
            deck->cards[card++] = (Card){
                .rank = rank,
                .suit = suit};
    deck->top = 0;
}

void deckInitWithStrategy(Deck *const deck, ShuffleStrategy shuffleStrategy)
{
        deck->shuffleStrategy = shuffleStrategy;
    deckInit(deck);
}

void deckPrint(const Deck *const deck)
{
    for (int i = 0; i < MAX_CARDS; i++)
        cardPrint(deck->cards[i]);
}

double deckCalculateDisplacement(const Deck *const original, const Deck *const shuffled)
{
    double totalDisplacement = 0;
    for (int i = 0; i < MAX_CARDS; i++)
        totalDisplacement += abs(i - deckFindIndex(shuffled, original->cards[i]));
    return totalDisplacement / MAX_CARDS;
}

int deckFindIndex(const Deck *const deck, Card card)
{
    for (int i = 0; i < MAX_CARDS; i++)
        if (cardIsEqual(deck->cards[i], card))
            return i;
    return -1;
}

int deckLongestOrderedRun(const Deck *const original, const Deck *const shuffled)
{
    int longestRun = 0;
    int currentRun = 0;

    for (int i = 0; i < MAX_CARDS; i++)
    {
        if (cardIsEqual(original->cards[i], shuffled->cards[i]))
        {
            currentRun++;
            if (currentRun > longestRun)
                longestRun = currentRun;
        }
        else
            currentRun = 0;
    }
    return longestRun;
}

int deckCountAdjacentSuits(const Deck *const shuffled)
{
    int adjacentCount = 0;
    for (int i = 0; i < MAX_CARDS - 1; i++)
        if (shuffled->cards[i].suit == shuffled->cards[i + 1].suit)
            adjacentCount++;
    return adjacentCount;
}

int deckCountPreservedPairs(const Deck *const original, const Deck *const shuffled)
{
    int preservedPairs = 0;
    for (int i = 0; i < MAX_CARDS - 1; i++)
        for (int j = i + 1; j < MAX_CARDS; j++)
            if (deckFindIndex(shuffled, original->cards[i]) < deckFindIndex(shuffled, original->cards[j]))
                preservedPairs++;
    return preservedPairs;
}

void deckShufflingSumary(const Deck *const original, const Deck *const shuffled)
{
    printf("Shuffling summary:\n");
    printf("\tDispacement: %f\n", deckCalculateDisplacement(original, shuffled));
    printf("\tLongest ordered run: %d\n", deckLongestOrderedRun(original, shuffled));
    printf("\tAdjacent cards from the same suit: %d\n", deckCountAdjacentSuits(shuffled));
    printf("\tPreserved relative pairs: %d\n", deckCountPreservedPairs(original, shuffled));
}

void deckShuffle(Deck *const deck)
{
    deck->shuffleStrategy(deck->cards);
}

void deckShuffleMany(Deck *const deck, int iterations)
{
    if (deck->shuffleStrategy != NULL)
        for (int i = 0; i < iterations; i++)
            deckShuffle(deck);
    else
        printf("No shuffle strategy provided! Deck remains in original state\n");
}

Card deckDrawFromTop(Deck *const deck)
{
    if (deck->top >= MAX_CARDS)
    {
        printf("Deck is empty!\n");
        return INVALID_CARD;
    } else {
        return deck->cards[deck->top++];
    }
}
