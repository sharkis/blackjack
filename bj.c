#include <stdio.h>
#include "utf8_encode.h"

int main() {
	printf("blackjack Copyright (C) 2024  Albert Sharkis\n\
This program comes with ABSOLUTELY NO WARRANTY\n\
This is free software, and you are welcome to redistribute it\n\
under certain conditions.\n\n");
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
