#ifndef STRINGFUNCTIONS_H_
#define STRINGFUNCTIONS_H_
#include <stdbool.h>

char* inputString();

char* stringCopy(const char* str);

void mutableToUpper(char* str);

char* immutableToUpper(const char* str);

void mutableToLower(char* str);

char* immutableToLower(const char* str);

void mutableStrip(char* str);

char* immutableStrip(const char* str);

void mutableClearSpace(char* str);

char* immutableClearSpace(const char* str);

void mutableFilter(char* str);

char* immutableFilter(const char* str);

bool isInteger(const char* str);

bool isLetters(const char* str);

#endif // STRINGFUNCTIONS_H_