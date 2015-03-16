// Caesar Cipher
// Arad Reed

// Make sure passed integer isn't negative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void caesar(int key, char text[]);
void decaesar(int key, char text[]);

int main(int argc, char* argv[0]) {
	char str[] = {"Be sure to drink your Ovaltine!"};
	
	if (argc < 2) {
		printf("Please pass in a key value!\n");
		return 1;
	}
	
	else {
		int key = atoi(argv[1]);
		
		caesar(key, str);
		printf("%s\n", str);
		
		decaesar(key, str);
		printf("%s\n", str);
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
		
}