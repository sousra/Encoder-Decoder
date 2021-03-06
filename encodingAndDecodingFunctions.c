#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stringFunctions.h"

void mutableEncodeCaesar(char* str, int k) {
	while (k < 0) {
		k += 'z' - 'a' + 1;
	}
	for (int i = 0; str[i] != 0; ++ i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] = (str[i] - 'a' + k) % 26 + 'a';
		}
	}
}

char* immutableEncodeCaesar(const char* str, int k) {
	char* str_cpy = stringCopy(str);
	mutableEncodeCaesar(str_cpy, k);
	return str_cpy;
}

void mutableDecodeCaesar(char* str, int k) {
	mutableEncodeCaesar(str, -k);
}

char* immutableDecodeCaesar(const char* str, int k) {
	char* str_cpy = stringCopy(str);
	mutableDecodeCaesar(str_cpy, k);
	return str_cpy;
}

void mutableEncodeXor(char* str, const char* password) {
	const unsigned len = strlen(password);
	for (int i = 0; str[i] != '\0'; ++i) {
		str[i] ^= password[i % len];
	}
}

char* immutableEncodeXor(const char* str, const char* password) {
	char* str_cpy = stringCopy(str);
	mutableEncodeXor(str_cpy, password);
	return str_cpy;
}

void mutableDecodeXor(char* str, const char* password) {
	immutableEncodeXor(str, password);
}

char* immutableDecodeXor(const char* str, const char* password){
	char* str_cpy = stringCopy(str);
	mutableDecodeXor(str_cpy, password);
	return str_cpy;
}