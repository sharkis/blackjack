#include <stdio.h>
#include "utf8_encode.h"

int main() {
  int start = 0x1f0a1;
  char out[5];
  for(int k=0; k<4;k++){
    for (int i = 0; i < 14; i++) {
      if(i==11) continue;
      utf8_encode(out, start + i);
      printf("%s ", out);
    }
    printf("\n");
    start = start + 0x10;
  }
  return 0;
}
