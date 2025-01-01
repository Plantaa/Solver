#include "player.h"

void playerPrintHand(const Player *const player)
{
    for (int i = 0; i < HAND_SIZE; i++)
        cardPrint(player->hand[i]);
}