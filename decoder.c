#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "stringFunctions.h"
#include "encodingAndDecodingFunctions.h"

int main(int argc, char* argv[]) {
	if (argc != 4 || strcmp(argv[1], "--caesar") || !isInteger(argv[3])) {
		printf("Поданы некорректные данные\n");
		exit(1);
	}
	char* str = stringCopy(argv[2]);
	mutableDecodeCaesar(str, atoi(argv[3]));
	printf("Decoded string: %s\n", str);
	return 0;
}