#ifndef ENCODING_AND_DECODINGFUNCTIONS_H_INCLUDED
#define ENCODING_AND_DECODINGFUNCTIONS_H_INCLUDED



void mutableEncodeCaesar(char* str, int k);

char* immutableEncodeCaesar(const char* str, int k);

void mutableDecodeCaesar(char* str, int k);

char* immutableDecodeCaesar(const char* str, int k);

void mutableEncodeXor(char* str, const char* password);

char* immutableEncodeXor(const char* str, const char* password);

void mutableDecodeXor(char* str, const char* password);

char* immutableDecodeXor(const char* str, const char* password);

#endif