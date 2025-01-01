#include <stdio.h>

#include "table.h"

void tablePlayerCardsDeal(Table *const table)
{
    for (int i = 0; i < HAND_SIZE; i++)
    {
        for (int j = 0; j < MAX_PLAYERS; j++)
        {
            Card drawnCard = deckDrawFromTop(&table->deck);
            if (cardIsEqual(INVALID_CARD, drawnCard))
            {
                printf("Deal incomplete!\n");
                return;
            }
            table->players[j].hand[i] = drawnCard;
        }
    }
}

void tableFlopDeal(Table *const table)
{
    for (int i = 0; i < FLOP_SIZE; i++)
    {
        Card drawnCard = deckDrawFromTop(&table->deck);
        if (cardIsEqual(INVALID_CARD, drawnCard))
        {
            printf("Flop incomplete!\n");
            return;
        }
        table->communals[i] = drawnCard;
    }
    table->cardsOnTable = FLOP_SIZE;
}

void tableTurnDeal(Table *const table)
{
    Card drawnCard = deckDrawFromTop(&table->deck);
    if (cardIsEqual(INVALID_CARD, drawnCard))
    {
        printf("Turn incomplete!\n");
        return;
    }
    table->communals[TURN] = drawnCard;
    table->cardsOnTable = TURN;
}

void tableRiverDeal(Table *const table)
{
    Card drawnCard = deckDrawFromTop(&table->deck);
    if (cardIsEqual(INVALID_CARD, drawnCard))
    {
        printf("River incomplete!\n");
        return;
    }
    table->communals[RIVER] = drawnCard;
    table->cardsOnTable = RIVER;
}

void tablePlayerCardsPrint(const Table *const table)
{
    for (int i = 0; i < MAX_PLAYERS; i++)
    {
        printf("\nCards from player %d:\n", i);
        playerPrintHand(table->players+i);
    }
}

void tableCommunalsPrint(const Table *const table)
{
    printf("\nCommunal cards on table:\n");
    tableFlopPrint(table);
    tableTurnPrint(table);
    tableRiverPrint(table);
}

void tableFlopPrint(const Table *const table)
{
    printf("Flop:\n");
    if (table->cardsOnTable < FLOP_SIZE) return;
    for (int i = 0; i < FLOP_SIZE; i++)
    {
        cardPrint(table->communals[i]);
    }
}

void tableTurnPrint(const Table *const table)
{
    printf("Turn:\n");
    if (table->cardsOnTable < TURN) return;
    cardPrint(table->communals[TURN]);
}

void tableRiverPrint(const Table *const table)
{
    printf("River:\n");
    if (table->cardsOnTable < RIVER) return;
    cardPrint(table->communals[RIVER]);
}

void tableReset(Table *const table)
{
    table->deck.top = 0;
    table->cardsOnTable = 0;
}
