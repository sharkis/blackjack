#include "deck.h"
#include <stdio.h>
#include <time.h>
#define DECK_SIZE 312

/*TODO
 * betting
 * insurance
 * split
 */

char cupper(char c) {
  char o = c;
  if ((int)c > 90) {
    o = c - 32;
  }
  return o;
}

int dealeractions(int *dh, int cardi, int *deck) {
  int dv = handvalue(dh);
  int di = 2;
  while (dv < 17) {
    dh[di++] = deck[cardi++];
    dv = handvalue(dh);
  }
  return dv;
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
  while (a != 'S') {
    if ('H' == a) {
      hand[handsize++] = deck[cardi++];
      int v = handvalue(hand);
      if (v > 21) {
        a = 'S';
        printf("Bust!\n");
      } else {
        printhand(hand);
        printf("Current hand value: %d\n", handvalue(hand));
        printf("(H)it or (S)tay? ");
        fgets(action, sizeof(action), stdin);
        a = cupper(action[0]);
      }
    } else {
      printf("(H)it or (S)tay? ");
      fgets(action, sizeof(action), stdin);
      a = cupper(action[0]);
    }
  }
  if ('S' == a) {
    int dv = dealeractions(dealerhand, cardi, deck);
    int v = handvalue(hand);

    printhand(hand);
    printf("Your hand value: %d\n", v);
    printhand(dealerhand);
    printf("Dealer hand value: %d\n", dv);
    if ((v > dv && v < 21) || dv > 21) {
      printf("You win!\n");
    } else {
      printf("You lose!\n");
    }
  }

  return 0;
}
