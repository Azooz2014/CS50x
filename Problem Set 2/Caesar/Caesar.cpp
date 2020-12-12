#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

char* caesar(char plainText[], int key);
int inputChecking(int key, int argc, char* argv[]);

int main(int argc, char* argv[])
{

	char plaintext[255];
	char* ciphertext = (char*)malloc(sizeof(char) * (255 + 1));
	int key = 0;

	if (argv[1] != NULL) {
		key = atoi(argv[1]);
	}

	// Input checking.
	inputChecking(key, argc, argv);
	

	printf("Plaintext: ");

	fgets(plaintext, 255, stdin);

	ciphertext = caesar(plaintext, key);

	printf("Ciphertext: %s \n", ciphertext);

	free(ciphertext);

	return 0;
}

//Prototyping

//int main()
//{
//
//	char plainText[] = "hello mr.Kenedy it was nice meeting your bitch!";
//	int key = 1;
//	char *cipher = caesar(plainText, key);
//
//	printf("Plaintext is : %s \n", plainText);
//	printf("key is : %d \n", key);
//	printf("Ciphertext is : %s \n", cipher);
//	free(cipher);
//
//}

char* caesar(char plainText[], int key) {

	char alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int plainTextSize = strlen(plainText);

	char* ciphertext = (char*)malloc(sizeof(char) * (plainTextSize + 1));


	// Iterate over each character in plainText string.
	for (int i = 0; i < plainTextSize; i++)
	{
		// Check if the ith character is an alphabet.
		if (isalpha(plainText[i]))
		{
			/* Iterate over each character in the alphabet and compare it
			with ith character in plaintext if matched enycrpt the letter. */
			for (int j = 0; j < 26; j++)
			{
				if (toupper(plainText[i]) == alphabet[j]) {

					if (isupper(plainText[i])) {

						ciphertext[i] = alphabet[(j + key) % 26];
						break;
					}
					else {

						ciphertext[i] = tolower(alphabet[(j + key) % 26]);
						break;
					}
				}
			}
		}
		// If not an alphabet store it as it is.
		else {
			ciphertext[i] = plainText[i];
		}
	}

	// Null termination to prevent ciphertext array from accessing forbidden memory segments. 
	ciphertext[plainTextSize] = '\0';

	return ciphertext;
}

int inputChecking(int key, int argc, char* argv[]) {

	if (argc != 2) {

		printf("usage: ./caesar key \n");
		printf("return value: %d", 1);
		/*printf("%i \n", isdigit(*argv[1]));*/
		/*printf("input is %s \n", argv);*/
		exit(1);
	}
	else if (key <= 0) {

		printf("usage: ./caesar key , please enter a a non-zero positive integer \n");
		printf("return value: %d", 2);
		exit(2);
	}
	else {
		for (char** arg = &argv[1]; *arg; ++arg) { // for each 2nd arg
			for (char* p = *arg; *p; ++p) {      // for each character in the 2nd argument
				if (isalpha(*p)) {

					printf("usage: ./caesar key \n");
					printf("return value: %d", 3);
					exit(3);
				}
			}
		}

	}
}

// debugging

//int main()
//{
//	char input[10] = {};
//
//	fgets(input, 10, stdin);
//	printf("input is %i \n", input[0]);
//	printf("isdigit? : %i \n", isdigit(input[0]));
//}

//int main(int argc, char *argv[])
//{
//	int length = strlen(*argv);
//
//	for (int i = 0; argv[i] != '\0'; i++)
//	{
//		printf("%c \n", *argv[i]);
//	}
//	
//	printf("length of argv is :%i \n", length);
//	printf("input is %i \n", *argv[1]);
//	printf("isdigit? : %i \n", isdigit(*argv[1]));
//}

//int main()
//{
//
//	char c = 'a';
//
//	if (isalpha(c) && isupper(c))
//	{
//		printf("is upper");
//	}
//}

// Solution for the reminder within alphabetical characters even if the key is bigger than the array. 
/*int main()
{

	char alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	int i;

	for (i = 0; i < 5000000; i++)
	{

	}

	printf("Letter is : %c \n", alphabet[i % 26]);
	printf("i is : %d \n", i);
	printf("modulo of i is : %d \n", i % 26);

}*/

//int main()
//{
//
//	char alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
//	char plainText[] = "Hello";
//	int plainTextSize = strlen(plainText);
//	int key = 1;
//	char ciphertext[255] = "";
//
//
//	for (int i = 0; i < plainTextSize; i++)
//	{
//
//		for (int j = 0; j < 26; j++)
//		{
//			if (toupper(plainText[i]) == alphabet[j]) {
//				
//				if (isupper(plainText[i]))
//				{
//					ciphertext[i] = alphabet[(j + key) % 26];
//					break;
//				}
//				else {
//					ciphertext[i] = tolower(alphabet[(j + key) % 26]);
//					break;
//				}
//			}
//		}
//
//	}
//
//	printf("Plaintext is : %s \n", plainText);
//	printf("key is : %d \n", key);
//	printf("Ciphertext of i is : %s \n", ciphertext);
//
//}

//Solution to iterate over each character in the 2nd argument (key) and checking it's a valid number.

/*int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("usage: ./caesar key \n");
		return 1;
	}
	
	for (char** arg = &argv[1]; *arg; ++arg) { // for each arg
		for (char* p = *arg; *p; ++p) {      // for each character
			if (isalpha(*p)) {

				printf("key is not a number. \n");
				return 2;
			}
		}
	}

	printf("OK!");
	return 0;
}*/