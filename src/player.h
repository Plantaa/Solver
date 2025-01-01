#ifndef PLAYER_H_
#define PLAYER_H_

#include "card.h"

#define HAND_SIZE 2

typedef struct player
{
    Card hand[HAND_SIZE];
} Player;

void playerPrintHand(const Player *const player);

#endif