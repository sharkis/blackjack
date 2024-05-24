#include <stdio.h>
#include "utf8_encode.h"

int main() {
  int start = 0x1f0a1;
  int end = start + 13;
  char out[5];
  for (int i = start; i <= end; i++) {
    utf8_encode(out, i);
    printf("%s\n", out);
  }

  return 0;
}
