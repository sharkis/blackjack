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

