#include "deck.h"
#include "utf8_encode.h"
#include <stdio.h>
#define DECK_SIZE 312

/*TODO
 * finish game set-up
 * betting
 * insurance
 */

int main() {
  printf("blackjack Copyright (C) 2024  Albert Sharkis\n"
         "This program comes with ABSOLUTELY NO WARRANTY\n"
         "This is free software, and you are welcome to redistribute it\n"
         "under certain conditions.\n\n");
  int hand[21] = {0}; // biggest possible hand, 21 straight aces
  int deck[312] = {0};
  // create deck 6 decks of 52 cards
  gendeck(deck, DECK_SIZE);
  // shuffle deck
  shufdeck(deck, DECK_SIZE);
  // TODO deal cards

  char out[5]; // four bytes for unicode output + null byte
  for (int i = 0; i < 312; i++) {
    utf8_encode(out, deck[i]);
    if (i % 52 == 0)
      printf("\n");
    printf("%s  ", out);
  }
  printf("\n");
  // TODO prompt user
  return 0;
}
