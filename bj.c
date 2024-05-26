#include "utf8_encode.h"
#include <stdio.h>

/*TODO
 * finish game set-up
 * betting
 * insurance
 */

int cardvalue(int card) {
  int tvalue = card & 0xf;
  return tvalue > 10 ? 10 : tvalue;
}

void gendeck(int *deck) {
  int start = 0x1F0A1; // ace o' spades
  char out[5];         // four bytes for unicode output + null byte
  for (int i = 0; i < 6; i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 14; j++) {
        int cardno = start + (k * 16) + j;
        if (j >= 11)
          cardno++;
        deck[(i * 52) + (k * 13) + j] = cardno;
      }
    }
  }
}

int main() {
  printf("blackjack Copyright (C) 2024  Albert Sharkis\n"
         "This program comes with ABSOLUTELY NO WARRANTY\n"
         "This is free software, and you are welcome to redistribute it\n"
         "under certain conditions.\n\n");
  int hand[21] = {0}; // biggest possible hand, 21 straight aces
  int deck[312] = {0};
  // create deck 6 decks of 52 cards
  gendeck(deck);
  // TODO shuffle deck

  // TODO deal cards

  char out[5]; // four bytes for unicode output + null byte
  for (int i = 0; i < 312; i++) {
    utf8_encode(out, deck[i]);
    if (i % 52 == 0)
      printf("\n");
    printf("%s  ", out);
  }
  // TODO prompt user
  return 0;
}
