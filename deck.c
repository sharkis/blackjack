#include "utf8_encode.h"
#include <stdio.h>
#include <stdlib.h>

int cardvalue(int card) {
  int tvalue = card & 0xf;
  return tvalue > 10 ? 10 : tvalue;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void gendeck(int *deck, int decksize) {
  int start = 0x1F0A1; // ace o' spades
  for (int i = 0; i < (decksize / 52); i++) {
    for (int k = 0; k < 4; k++) {
      for (int j = 0; j < 13; j++) {
        int cardno = start + (k * 16) + j;
        if (j >= 11)
          cardno++;
        deck[(i * 52) + (k * 13) + j] = cardno;
      }
    }
  }
}

void shufdeck(int *deck, int n) {
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    swap(&deck[i], &deck[j]);
  }
}

void printhand(int *hand) {
  char out[5]; // four bytes for unicode output + null byte
  int pos = 0;
  int curcard = hand[pos];
  while (curcard != 0) {
    utf8_encode(out, curcard);
    printf("%s  ", out);
    curcard = hand[++pos];
  }
  printf("\n");
}

int handvalue(int *hand) {
  int pos = 0;
  int curcard = hand[pos];
  int curValue = 0;
  while (curcard != 0) {
    curValue += cardvalue(curcard);
    curcard = hand[++pos];
  }
  return curValue;
}

// void printdeck() {
//   char out[5]; // four bytes for unicode output + null byte
//   for (int i = 0; i < DECK_SIZE; i++) {
//     utf8_encode(out, deck[i]);
//     if (i % 52 == 0)
//       printf("\n");
//     printf("%s  ", out);
//   }
//   printf("\n");
// }
