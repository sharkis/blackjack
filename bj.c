#include <stdio.h>
#include "utf8_encode.h"

/*TODO
 * finish game set-up
 * betting
 * insurance 
 */

int cardvalue(int card){
  int tvalue = card & 0xf;
  return tvalue > 10 ? 10 : tvalue;
}

int main() {
  printf("blackjack Copyright (C) 2024  Albert Sharkis\n"
      "This program comes with ABSOLUTELY NO WARRANTY\n"
      "This is free software, and you are welcome to redistribute it\n"
      "under certain conditions.\n\n");
  int hand[21] = { 0 }; // biggest possible hand, 21 straight aces
  int start = 0x1f0a1; // ace o' spades
  char out[5]; // four bytes for unicode output
  for(int k=0; k<4;k++){
    for (int i = 0; i < 14; i++) {
      if(i==11) continue;
      utf8_encode(out, start + i);
      printf("%s %d\t", out, cardvalue(start + i));
    }
    printf("\n");
    start = start + 0x10;
  }

// create deck (6-8) decks of 52 cards
// deal cards
// prompt user
  return 0;
}
