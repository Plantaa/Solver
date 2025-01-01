#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "table.h"

int main()
{
    srand((unsigned int)time(0));

    Deck originalDeck;
    deckInit(&originalDeck);

    Table table;
    deckInitWithStrategy(&table.deck, fisherYatesShuffle);
    deckShuffle(&table.deck);
    deckShufflingSumary(&originalDeck, &table.deck);
    tablePlayerCardsDeal(&table);
    tablePlayerCardsPrint(&table);
    tableFlopDeal(&table);
    tableCommunalsPrint(&table);
    tableTurnDeal(&table);
    tableCommunalsPrint(&table);
    tableRiverDeal(&table);
    tableCommunalsPrint(&table);
    tableReset(&table);
    tableCommunalsPrint(&table);

    return 0;
}
