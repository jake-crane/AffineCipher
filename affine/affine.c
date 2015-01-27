/**
 * Created on: Jan 25, 2015
 * Author: Jake Crane
 *
 * This program only supports encrypting and decrypting plainText uppercase values [A-Z].
 * Space characters (' ', '\t', '\n', '\v', '\f', '\r') will be left unchanged.
 * This program receives input from stdin and outputs results through stdout.
 * The validity of input and keys is not checked.
 * Example usage: echo HELLO | affine encrypt 5 8
 * Example of encrypting and decrypting: echo HELLO | affine encrypt 5 8 | affine decrypt 5 8
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "affinelib.h"

int main(int argc, char **argv) {

	char (*function_ptr)(char, int, int);

	if (argc != 4) {
		fprintf(stderr, "usage: %s (encrypt|decrypt) k1 k2\n", argv[0]);
		return 1;
	} else if (strcmp (argv[1], "encrypt") == 0) {
		function_ptr = &encryptchar;
	} else if (strcmp (argv[1], "decrypt") == 0) {
		function_ptr = &decryptchar;
	} else {
		fprintf(stderr, "usage: %s (encrypt|decrypt) k1 k2\n", argv[0]);
		return 1;
	}

	int k1 = atoi(argv[2]);
	int k2 = atoi(argv[3]);

	char c;
	while((c = fgetc(stdin)) != EOF) {
		if (!isspace(c)) {
			c = function_ptr(c, k1, k2);
		}
		printf("%c", c);
	}

	return 0;
}
