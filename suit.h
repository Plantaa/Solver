#ifndef SUIT_H_
#define SUIT_H_

typedef enum suit {
    CLUBS,
    HEARTS,
    SPADES,
    DIAMONDS
}Suit;

char* suitString(Suit suit);

#endif
