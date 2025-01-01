#!/bin/bash
mkdir build 2> /dev/null
gcc -c src/suit.c -o build/suit.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/rank.c -o build/rank.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/card.c -o build/card.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/shuffle.c -o build/shuffle.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/player.c -o build/player.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/deck.c -o build/deck.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/table.c -o build/table.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc -c src/main.c -o build/main.o -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
gcc build/main.o build/table.o build/deck.o build/player.o build/shuffle.o build/card.o build/rank.o build/suit.o -o solver -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
