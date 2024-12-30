#ifndef SUIT_H_
#define SUIT_H_

typedef enum suit {
    CLUBS,
    HEARTS,
    SPADES,
    DIAMONDS
}Suit;

void suitPrint(Suit suit);
char* suitString(Suit suit);

#endif
