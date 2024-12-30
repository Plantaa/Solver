#!/bin/bash
gcc -c suit.c -o suit.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c rank.c -o rank.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c card.c -o card.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c deck.c -o deck.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c main.c -o main.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc main.o deck.o card.o rank.o suit.o -o solver -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
