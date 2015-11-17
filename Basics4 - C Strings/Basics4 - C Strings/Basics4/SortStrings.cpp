#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <vector>
#pragma warning( disable : 4996 )

#include "SortStrings.h"



void ReorderAlphabetical(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on alphabetical order, (a begin, z end)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) hint: qsort() - might be a good function to know
	
	int len = strlen(inString);
	
	// double size buffer: half for input, half for output.
	char *buff = (char*)calloc((len + 1) * 2, sizeof(char));
	char *buff2 = buff + len + 1;

	// inString is inmutable, need to copy into buffer before use strtok. 
	strcpy(buff, inString);
	char *token = strtok(buff, " ");
	std::vector<char*> tokenList(10);
	int i = 0;
	while (token) {
		tokenList[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	int size = i;
	i = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (strcmp(tokenList[j - 1], tokenList[j]) > 0)
			{
				char * tmp = tokenList[j];
				tokenList[j] = tokenList[j - 1];
				tokenList[j - 1] = tmp;
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%s\n", tokenList[i]);
		strcat(buff2, tokenList[i]);
		if (i != size - 1)
		{
			strcat(buff2, " "); 
		}
	}
	strcpy(outString, buff2);
	free(buff);
}



void ReorderWordLength(const char * const inString, char * const outString )
{
	// 1) reorder the words in the string, words are separated with spaces
	// 2) sort words on their word length order, (short, longest)
	// 3) you don't know how many words 
	// 4) if dynamically create any buffers inside this routine, clean them up
	// 5) use strtok and strcat in your answer
	// 6) hint: qsort() - might be a good function to know

	int len = strlen(inString);

	// double size buffer: half for input, half for output.
	char *buff = (char*)calloc((len + 1) * 2, sizeof(char));
	char *buff2 = buff + len + 1;

	// inString is inmutable, need to copy into buffer before use strtok. 
	strcpy(buff, inString);
	char *token = strtok(buff, " ");
	std::vector<char*> tokenList(10);
	int i = 0;
	while (token) {
		tokenList[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	int size = i;
	i = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (int j = 1; j < size - i; j++)
		{
			if (
				(strlen(tokenList[j - 1]) > strlen(tokenList[j])) ||
				((strlen(tokenList[j - 1]) == strlen(tokenList[j])) && (strcmp(tokenList[j - 1], tokenList[j]) > 0)))
			{
				char * tmp = tokenList[j];
				tokenList[j] = tokenList[j - 1];
				tokenList[j - 1] = tmp;
			}
		}
	}
	for (i = 0; i < size; i++)
	{
		printf("%s\n", tokenList[i]);
		strcat(buff2, tokenList[i]);
		if (i != size - 1)
		{
			strcat(buff2, " ");
		}
	}
	strcpy(outString, buff2);
	free(buff);
}



