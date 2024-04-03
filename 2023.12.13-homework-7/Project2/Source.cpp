#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{

	FILE* f1 = fopen("ink.txt", "r");

	char s[]{ 0 };
	int count = 0;
	while (fscanf(f1, "%s", s) != EOF)
	{
		count++;
	}
	fclose(f1);

	FILE* f2 = fopen("outk.txt", "w");
	fprintf(f2, "%s %d", "words found:", count);
	fclose(f2);

	f1 = fopen("ink.txt", "r");
	char strMax[]{ 0 };

	int NumOfSent = 0;
	int NumOfSentMax = 0;
	int countMax = 0;
	while (!feof(f1))
	{
		int count = 0;
		while (fscanf(f1, "%c") != '.')
		{
			if (fscanf(f1, "%c") == ' ')
			{
				++count;
			}
		}
		++NumOfSent;
		if (countMax < count + 1)
		{
			countMax = count + 1;
			NumOfSentMax = NumOfSent;
		}
	}
	fclose(f1);

	f1 = fopen("ink.txt", "r");
	int help = 0;
	while (help < NumOfSentMax - 1)
	{
		if (fscanf(f1, "%c") != '.')
		{
			++help;
		}
	}
	fscanf(f1, "%[.]", strMax);
	fclose(f1);

	f2 = fopen("outk.txt", "w");
	fprintf(f2, "%s", strMax);
	fclose(f2);

	return EXIT_SUCCESS;
}