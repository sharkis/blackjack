#include "deck.h"
#include <stdio.h>
#include <time.h>
#define DECK_SIZE 312

/*TODO
 * finish game set-up
 * betting
 * insurance
 */

int main() {
	srand(time(NULL));
  printf("blackjack Copyright (C) 2024  Albert Sharkis\n"
         "This program comes with ABSOLUTELY NO WARRANTY\n"
         "This is free software, and you are welcome to redistribute it\n"
         "under certain conditions.\n\n");
  int hand[21] = {0}; // biggest possible hand, 21 straight aces
  int dealerhand[21] = {0};
  int handsize = 0;
  int deck[DECK_SIZE] = {0};
  // create deck 6 decks of 52 cards
  gendeck(deck, DECK_SIZE);
  // shuffle deck
  shufdeck(deck, DECK_SIZE);
  // TODO deal cards
  hand[0]=deck[0];
  dealerhand[0]=deck[1];
  hand[1]=deck[2];
  dealerhand[1]=deck[3];
  printhand(hand);
  printf("Current hand value: %d\n",handvalue(hand));

  // TODO prompt user
  return 0;
}
