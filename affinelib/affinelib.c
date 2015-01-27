/**
 * Created on: Jan 25, 2015
 * Author: Jake Crane
 *
 * This library allows programs to encrypt and decrypt characters using the affine cipher.
 * It only supports encrypting and decrypting plainText uppercase values [A-Z].
 * The validity of input and keys is not checked.
 */

#include "affinelib.h"

int modinverse(int a, int m) {
	int n = 1;
	while((n*a) % m != 1) {
		n++;
	}
	return n;
}

/**
 * plainText is a character to be encrypted
 * k1 is the first key
 * k2 is the second key
 * Returns a ecrypted char
 */
char encryptchar(char plainText, int k1, int k2) {
	return (char)((((plainText - 'A') * k1 + k2) % 26)) + 'A';
}

/**
 * cipher is a char to decrypt
 * k1 is the first key
 * k2 is the second key
 * Returns a decrypted char
 */
char decryptchar(char cipher, int k1, int k2) {
	int a = modinverse(k1, 26) * ((cipher - 'A') - k2);
	int result = (a % 26 + 26) % 26;
	return (char)(result + 'A');
}

