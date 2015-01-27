The affine directory contains a program for encrypting and decrypting plainText using the Affine cipher.
Example usage: echo HELLO | affine encrypt 7 2
Example usage: echo ZEBBW | affine decrypt 7 2

The affine_brute_force directory contains a program that will print out all of the possible keys and plainText values given a cipher. 
Example usage: affine_brute_force file cipher.txt | less
Example usage: affine_brute_force string ZEBBW | less

The affinelib directory contains functions to encrypt and decrypt characters using the Affine cipher.

These programs can only encrypt and decrypt uppercase letters [A-Z], will leave space characters(' ', '\t', '\n', '\v', '\f', '\r') unchanged and does not check the validity of text or keys.

These programs can be compiled using make.