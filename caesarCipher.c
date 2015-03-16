// Caesar Cipher
// Arad Reed

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define STR_LENGTH 256

void caesar(int key, char text[]);
void decaesar(int key, char text[]);

int main(int argc, char* argv[0]) {
	char str[STR_LENGTH];

	if (argc < 4) {
		printf("Please pass in a decrypt/encrypt, a filename, and a key value!\n");
		return 1;
	}
	
	else {
		bool encrypt;
		
		// Check whether encrypting or decrypting
		if (strcmp(argv[1], "encrypt") == 0) 
			encrypt = true;
		else if (strcmp(argv[1], "decrypt") == 0)
			encrypt = false;
		else {
			printf("Please enter a valid option (encrypt/decrypt)");
			return 1;
		}
		
		FILE* file = fopen(argv[2], "r");
		
		if (file == NULL) {
			printf("Please enter a valid filename");
			return 2;
		}
		
		int key = atoi(argv[3]);
		
		while(fgets(str, sizeof(str), file) != NULL) {
			if (encrypt) {
				caesar(key, str);
				printf("%s", str);
			}
			else {
				decaesar(key, str);
				printf("%s", str);
			}
		}
	}
	
	return 0;
}

void caesar(int key, char str[]) {
	int length = strlen(str);
	
	for (int i = 0; i < length; i++) {
		if (islower(str[i])) {
			str[i] = ((str[i] - 'a' + key) % 26) + 'a';
		}
		else if (isupper(str[i])) {
			str[i] = ((str[i] - 'A' + key) % 26) + 'A';
		}
	}
		
}

void decaesar(int key, char str[]) {
	int length = strlen(str);

	for (int i = 0; i < length; i++) {
		if (islower(str[i])) {
			int num = (str[i] - 'a' - key);
			
			// Mod interacts differently with negative values. qc + r (nonnegative) = num
			if (num < 0)
				num += 26;
			
			str[i] = (num % 26) + 'a';
		}
		else if (isupper(str[i])) {
			int num = (str[i] - 'A' - key);
			
			if (num < 0)
				num += 26;
			
			str[i] = (num % 26) + 'A';
		}
	}
}