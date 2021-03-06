#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

char* inputString() {
	char* str = NULL;
	unsigned size = 0;
	char c;
	scanf("%c", &c);
	while(c != '\0' && c != '\n') {
		++size;
		str = (char*) realloc(str, size * sizeof(char));
		str[size - 1] = c;
		scanf("%c", &c);
	}
	++size;
	str = (char*) realloc(str, size * sizeof(char));
	str[size - 1] = '\0';
	return str;
}

char* stringCopy(const char* str) {
	char* str_cpy = (char*) malloc(((int) strlen(str) + 1) * sizeof(char));
	strcpy(str_cpy, str);
	return str_cpy;
}

void mutableToUpper(char* str) {
	const char distance = 'a' - 'A';
	for (int i = 0; str[i] != 0; ++i) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= distance;
		}
	}
}

char* immutableToUpper(const char* str) {
	char* str_cpy = stringCopy(str);
	mutableToUpper(str_cpy);
	return str_cpy;
}

void mutableToLower(char* str) {
	const char distance = 'a' - 'A';
	for (int i = 0; str[i] != 0; ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
		str[i] += distance;
		}
	}
}

char* immutableToLower(const char* str) {
	char* str_cpy = stringCopy(str);
	mutableToLower(str_cpy);
	return str_cpy;
}

void mutableStrip(char* str) {
	unsigned strStart, strEnd;
	int i = 0;
	while (str[i] == ' ') {
		++i;
	}
	strStart = i;
	while (str[i] != 0) {
		++i;
	}
	--i;
	while (str[i] == ' ') {
		--i;
	}
	strEnd = i;
	int j;
	for (j = 0; j < strEnd - strStart + 1; ++j) {
		str[j] = str[j + strStart];
	}
	str[j] = 0;
}

char* immutableStrip(const char* str) {
	char* str_cpy = stringCopy(str);
	mutableStrip(str_cpy);
	return str_cpy;
}

void mutableClearSpace(char* str) {
	int counter = 0;
	for (int i = 0; str[i] != 0; ++i) {
		str[i - counter] = str[i];
		if (str[i] == ' ') {
			++counter;
		}
	}
	str[(int) strlen(str) - counter] = 0;
}

char* immutableClearSpace(const char* str) {
	char* str_cpy = stringCopy(str);
	mutableClearSpace(str_cpy);
	return str_cpy;
}

void mutableFilter(char* str) {
	int counter = 0;
	for (int i = 0; str[i] != 0; ++i) {
		str[i - counter] = str[i];
		if (!((str[i] == ' ') ||
			((str[i] >= 'a') && (str[i] <= 'z')) ||
			((str[i] >= 'A') && (str[i] <= 'Z')) ||
			((str[i] >= '0') && (str[i] <= '9'))))
		{
			++counter;
		}
	}
	str[(int) strlen(str) - counter] = 0;
}

char* immutableFilter(const char* str) {
	char* str_cpy = stringCopy(str);
	mutableFilter(str_cpy);
	return str_cpy;
}


bool isInteger(const char* str) {
	bool point = false;
	int i = 0;
	if (str[i] == '-' || str[i] == '+') {
		++i;
	}
	if (str[i] == '\0' || str[i] == '.') {
		return false;
	}
	while (str[i] != '\0') {
		if (str[i] == '.' && point == false) {
			point = true;
		}
		else if ((str[i] < '0') || (str[i] > '9')) {
			return false;
		}
		++i;
	}
	return true;
}

bool isLetters(const char* str) {
	for (int i = 0; str[i] != '\0'; ++i) {
		if (!(str[i] >= 'A' && str[i] <= 'Z') && !(str[i] >= 'a' && str[i] <= 'z')) {
			return false;
		}
	}
	return true;
}