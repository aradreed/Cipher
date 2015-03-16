# Cipher
## Description
caesarCipher takes an option of encrypt or decrypt, a filename, and a key (a positive integer) and outputs the files line encrypted and decrypted using the key in a Caesar Cipher.

vigenereCipher takes a keyword (a string) and does the same as a Caesar Cipher but using the values of each letter in the keyword lined up with the letters in the string to be encoded. This one encodes the string "This is a test sentence. It works!" 

## Usage
Caesar Cipher

''''
./caesarCipher encrypt message.txt 13
''''

Vigenere Cipher

''''
./vigenereCipher password
''''