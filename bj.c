#include "deck.h"
#include <stdio.h>
#include <time.h>
#define DECK_SIZE 312

/*TODO
 * finish game set-up
 * betting
 * insurance
 */

char cupper(char c) {
  char o = c;
  if ((int)c > 90) {
    o = c - 32;
  }
  return o;
}

int main() {
  srand(time(NULL));
  printf("blackjack Copyright (C) 2024  Albert Sharkis\n"
         "This program comes with ABSOLUTELY NO WARRANTY\n"
         "This is free software, and you are welcome to redistribute it\n"
         "under certain conditions.\n\n");
  int hand[21] = {0}; // biggest possible hand, 21 straight aces
  int dealerhand[21] = {0};
  int handsize = 2;
  int cardi = 4;
  int deck[DECK_SIZE] = {0};
  // create deck 6 decks of 52 cards
  gendeck(deck, DECK_SIZE);
  // shuffle deck
  shufdeck(deck, DECK_SIZE);

  // deal cards
  hand[0] = deck[0];
  dealerhand[0] = deck[1];
  hand[1] = deck[2];
  dealerhand[1] = deck[3];

  printhand(hand);
  printf("Current hand value: %d\n", handvalue(hand));

  printf("(H)it or (S)tay? ");
  char action[100];
  fgets(action, sizeof(action), stdin);
  char a = cupper(action[0]);
  while (a == 'H') {
      hand[handsize++] = deck[cardi++];
      int v = handvalue(hand);
      printf("Current hand value: %d\n", handvalue(hand));
      if (v > 21) {
	a = 'B';
        printf("Bust!\n");
      } else {
        printf("(H)it or (S)tay? ");
        fgets(action, 2, stdin);
        a = cupper(action[0]);
      }
  }
  if ('S' == a) {
    int v = handvalue(hand);
    int dv = handvalue(dealerhand);
    printhand(hand);
    printf("Your hand value: %d\n", v);
    printhand(dealerhand);
    printf("Dealer hand value: %d\n", dv);
    if (v > dv) {
      printf("You win!\n");
    } else {
      printf("You lose!\n");
    }
  }

  return 0;
}
