#ifndef TABLE_H_
#define TABLE_H_

#include "deck.h"
#include "player.h"

#define MAX_PLAYERS 5
#define MAX_COMMUNAL_CARDS 5
#define FLOP_SIZE 3
#define TURN 4
#define RIVER 5

typedef struct table
{
    Deck deck;
    Player players[MAX_PLAYERS];
    Card communals[MAX_COMMUNAL_CARDS];
    int cardsOnTable;
} Table;

/*Dealing*/
void tablePlayerCardsDeal(Table *const table);
void tableFlopDeal(Table *const table);
void tableTurnDeal(Table *const table);
void tableRiverDeal(Table *const table);

/*Printing*/
void tablePlayerCardsPrint(const Table *const table);
void tableCommunalsPrint(const Table *const table);
void tableFlopPrint(const Table *const table);
void tableTurnPrint(const Table *const table);
void tableRiverPrint(const Table *const table);

/*Utils*/
void tableReset(Table *const table);

#endif