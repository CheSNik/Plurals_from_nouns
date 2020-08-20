/*Chekhonin Sergei Team 5*/
/*Module 13 Lab 9 programm 1*/

/*This program returns plurals from entered nouns*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100 /*a. The array should be 100 in length.*/

/*
Input - string NOUN
Output - plural of NOUN
LOgic

a. If noun ends in “y” remove the “y” and add “ies”.
b. If noun ends in “s”, “ch”, or “sh”, add “es”.
c. In all other cases, just add “s”
d. Print each noun and its plural. Try the following data:
Allow the user to keep on entering words until the word done is entered.
e. Try the following data:
Chair dairy boss circus fly dog church clue dish
*/

int main()
{
	printf("Please input as many words as you like\n");
	printf("Separate each word by at least 1 blank\n");

	char nounsCompound[SIZE];
	char nounInput[50];
	char item[20];
	char itemModified[20];
	int nextBlankPosition;
	int firstLetterPosition = 0;
	
	nounsCompound[0] = '\0';

	for (scanf("%s", nounInput); strcmp(nounInput, "done") != 0;scanf("%s", nounInput))
	{
		strcat(nounInput, " ");
		strcat(nounsCompound, nounInput);
	}

	for (nextBlankPosition = 0; nextBlankPosition < strlen(nounsCompound); nextBlankPosition++)
	{
		if (nounsCompound[nextBlankPosition] == ' ')
		{
			strncpy(item, &nounsCompound[firstLetterPosition], nextBlankPosition - firstLetterPosition);
			item[nextBlankPosition - firstLetterPosition] = '\0';
			firstLetterPosition = nextBlankPosition + 1;

			if (nounsCompound[nextBlankPosition - 1] == 'y')
			{
				strncpy(itemModified, item, strlen(item) - 1);
				itemModified[strlen(item)-1] = '\0';
				strcat(itemModified, "ies");
			}
			else if (nounsCompound[nextBlankPosition - 1] == 's' ||
				nounsCompound[nextBlankPosition - 2] == 'c' && nounsCompound[nextBlankPosition - 1] == 'h' ||
				nounsCompound[nextBlankPosition - 2] == 's' && nounsCompound[nextBlankPosition - 1] == 'h')
			{
				strncpy(itemModified, item, strlen(item));
				itemModified[strlen(item)] = '\0';
				strcat(itemModified, "es");
			}
			else
			{
				strcpy(itemModified, item);
				strcat(itemModified, "s");
			}

			printf("%s -  %s\n", item, itemModified);
		}

	}

	return 0;
}

