/**
 * Created on: Jan 25, 2015
 * Author: Jake Crane
 *
 * This program only supports decrypting plainText uppercase values [A-Z].
 * Space characters (' ', '\t', '\n', '\v', '\f', '\r') will be left unchanged.
 * This program receives input as a string or from a file and outputs results through stdout.
 * The validity of input and keys is not checked.
 * Example usage: affine_brute_force file cipher.txt | less
 * Example usage: affine_brute_force string ZEBBW | less
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "affinelib.h"

#define K1_VALUE_LENGTH 12
const int ALL_POSSIBLE_K1_VALUES[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};

//The size of the key domain is 26 * 12 = 312
void print_all_possible_results(void (*func)(void*, int, int), void* cipher) {
	int count = 0;
	for (int k1Index = 0; k1Index < K1_VALUE_LENGTH; k1Index++) {
		for (int k2 = 0; k2 < 26; k2++) {
			printf("%d%s%d%s%d\n", count++, ": k1=", ALL_POSSIBLE_K1_VALUES[k1Index], ", k2=", k2);
			func(cipher, ALL_POSSIBLE_K1_VALUES[k1Index], k2);
			printf("\n");
		}
	}
}

void print_decrypted(char plainText, int k1, int k2) {
	if (!isspace(plainText)) {
		printf("%c", decryptchar(plainText, k1, k2));
	} else {
		printf("%c", plainText);
	}
}

void string_func(void* cipher, int k1, int k2 ) {
	char* cipher_string = (char*)cipher;
	for (int i = 0; cipher_string[i] != 0; i++) {
		print_decrypted(cipher_string[i], k1, k2);
	}
}

void file_func(void* vp, int k1, int k2 ) {
	FILE* fp = (FILE*)vp;
	char c;
	while((c = fgetc(fp)) != EOF) {
		print_decrypted(c, k1, k2);
	}
	if (fseek(fp, 0, SEEK_SET) != 0) {
		fprintf(stderr, "Error seeking to start of file");
		exit(1);
	}
}

int main(int argc, char **argv) {

	if (argc == 3 && strcmp (argv[1], "file") == 0) {
		FILE *fp = fopen(argv[2], "r");
		if(fp == NULL) {
			perror("Error opening file");
			return 1;
		}
		print_all_possible_results(file_func, (void*)fp);
	} else if (argc == 3 && strcmp (argv[1], "string") == 0) {
		print_all_possible_results(string_func, (void*)argv[2]);
	} else {
		fprintf(stderr, "usage:\n");
		fprintf(stderr, "%s file FILE_PATH\n", argv[0]);
		fprintf(stderr, "or\n");
		fprintf(stderr, "%s string STRING\n", argv[0]);
		return 1;
	}

	return 0;
}
