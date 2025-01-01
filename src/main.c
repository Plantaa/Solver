#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "table.h"

int main()
{
    srand((unsigned int)time(0));

    Deck referenceDeck;
    deckInit(&referenceDeck);

    Table table;
    ShuffleStrategy tableDeckShuffleStrategy = {
        .shuffle = riffleShuffle,
        .iterations = 7
    };
    tableInitWithShuffleStrategy(&table, tableDeckShuffleStrategy);
    tableDeckShuffle(&table);
    deckShufflingSumary(&referenceDeck, &table.deck);

    tablePlayerCardsDeal(&table);
    tablePlayerCardsPrint(&table);

    tableFlopDeal(&table);
    tableCommunalsPrint(&table);

    tableTurnDeal(&table);
    tableCommunalsPrint(&table);

    tableRiverDeal(&table);
    tableCommunalsPrint(&table);
    
    referenceDeck = table.deck;
    tableReset(&table);
    tableCommunalsPrint(&table);
    tableDeckShuffle(&table);
    deckShufflingSumary(&referenceDeck, &table.deck);

    return 0;
}
