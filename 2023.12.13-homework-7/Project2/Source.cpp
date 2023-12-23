#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	FILE* f1 = fopen("in.txt", "r");

	char s[]{ 0 };
	int count = 0;
	while (fscanf(f1, "%s", s) != EOF)
	{
		count++;
	}
	fclose(f1);

	FILE* f2 = fopen("out.txt", "w");
	fprintf(f2, "%s %d", "words found:", count);
	fclose(f2);


	f1 = fopen("in.txt", "r");
	int maxCount = 0;
	int count1 = 0;
	while (fscanf(f1, "%s") != EOF)
	{
		while (fscanf(f1, "%c") != '.')
		{
			if (fscanf(f1, "%c") == ' ')
			{
				++count1;
			}
		}
		if (maxCount < count1 + 1)
		{
			maxCount = count1 + 1;
		}
		count1 = 0;
	}

	int numOfSentence = 0;
	while (fscanf(f1, "%s") != EOF)
	{
		while (fscanf(f1, "%c") != '.')
		{
			if (fscanf(f1, "%c") == ' ')
			{
				++count1;
			}
		}
		++numOfSentence;
		if (count1 == maxCount)
		{
			break;
		}
		count1 = 0;
	}

	int j = 0;
	char maxSentence[]{ 0 };
	int m = 0;
	while (fscanf(f1, "%s") != EOF)
	{
		while (m < numOfSentence - 1)
		{
			if (fscanf(f1, "%c") == '.')
			{
				++m;
			}
		}
		while (fscanf(f1, "%c") != '.')
		{
			maxSentence[j] = fscanf(f1, "%c");
			++j;
		}
	}
	maxSentence[j] = '\0';
	fclose(f1);

	f2 = fopen("out.txt", "w");
	fprintf(f2, "%s", maxSentence);
	fclose(f2);

	return EXIT_SUCCESS;
}