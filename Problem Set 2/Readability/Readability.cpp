#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int nOfLetters(const char* input);
int nOfWords(const char* input);
int nOfSentences(const char* input);
double colemanIndex(int nOfLetters, int nOfWords, int nOfSentences);
void printGrade(int numOfLetters, int numOfWords, int numOfSentences);

int main(void) {

	char input[255] = {};

	printf("Enter a paragragh to be graded: \n\n");
	fgets(input, 255, stdin);
	printf("\n");


	int numOfLetters = nOfLetters(input);
	int numOfWords = nOfWords(input);
	int numOfSentences = nOfSentences(input);
	

	printf("%i letter(s) \n", numOfLetters);
	printf("%i word(s) \n", numOfWords);
	printf("%i sentence(s) \n\n", numOfSentences);

	printGrade(numOfLetters, numOfWords, numOfSentences);
}

// Counting number of letters excluding white spaces & special characters in a giving input of string.
int nOfLetters(const char* input) {

	int n = 0;
	/*const char* validChar = "abcdefghijklmnopqrstuvwxyz";
	const char* invalidChar = "?!:,\" ";*/

	while (*input != '\0') {

		if (*input != ' ' && *input != '?' && *input != '!' && *input != ',' 
			&& *input != ':' && *input != '"' && *input != '.' && *input != '\''
			&& *input != ';' && *input != '-') {

			n++;
		}

		input++;
	}
	
	return n;
}

// Counting number of words in a giving input of strings.
int nOfWords(const char* input) {

	int n = 0;
	int length = strlen(input);
	
	for (int i = 0; input[i] != '\0'; i++) {

		if (input[i + 1] == ' ')
		{
			n++;
		}
	}

	if (input[length - 1] != ' ') {

		n++;
	}

	return n;
}

// Counting number of sentences in giving input of strings.
int nOfSentences(const char* input) {

	int n = 0;
	int length = strlen(input);

	for (int i = 0; input[i] != '\0'; i++) {

		if (input[i] == '.' || input[i] == '!' || input[i] == '?')
		{
			n++;
		}
	}

	return n;
}

// Computing the Coleman-Liau  index.
double colemanIndex(int nOfLetters, int nOfWords, int nOfSentences) {

	double index = 0;
	double L = 0;
	double S = 0;

	L = ((double)nOfLetters / nOfWords) * 100;
	S = ((double)nOfSentences / nOfWords) * 100;

	index = 0.0588 * L - 0.296 * S - 15.8;

	return ceil(index);
}

// Printing out the grade.
void printGrade(int numOfLetters, int numOfWords, int numOfSentences) {

	int index = colemanIndex(numOfLetters, numOfWords, numOfSentences);

	if (index < 1) {

		printf("Before Grade 1 \n");
	}
	else if (index >= 16) {

		printf("Grade 16+ \n");
	}
	else {

		printf("Grade %d \n", index);
	}
}

