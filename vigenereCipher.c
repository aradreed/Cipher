// Caesar Cipher
// Arad Reed

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void vigenere(char keyword[], char str[]);

int main(int argc, char* argv[0]) {
	char str[] = "This is a test sentence. It works!";
		
	if (argc < 2) {
		printf("%s", "Please enter a keyword!");
		return 1;
	}
	
	else {
		vigenere(argv[1], str);
		printf("%s\n", str);
	}
	
	return 0;
		
}

int getKey(char keyLetter) {
	// Given a letter, finds the key to encode by
	
	if (isupper(keyLetter))
		return keyLetter - 'A';
	else 
		return keyLetter - 'a';
}

void vigenere(char keyword[], char str[]) {
	int length = strlen(str);
	int keywordLength = strlen(keyword);
	int j = 0;
	
	for (int i = 0; i < length; i++) {
		
		if (islower(str[i])) {
			str[i] = ((str[i] - 'a' + getKey(keyword[j])) % 26) + 'a';
			j = (j+1) % keywordLength;
		}
		
		else if (isupper(str[i])) {
			str[i] = ((str[i] - 'A' + getKey(keyword[j])) % 26) + 'A';
			j = (j+1) % keywordLength;
		}
	}
}