#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <stdio.h>
#include <stdlib.h>

char* strcat(char* str1, char* str2)
{
	int len1 = strlen(str1), len2 = strlen(str2);
	for (int i = strlen(str1); i < len1 + len2; i++) {
		str1[i] = str2[i - len1];
	}
	str1[len1 + len2] = '\0';
	return str1;
}

int strstr(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int temp = 0;
	for (int i = 0; i < len1; ++i)
	{
		int indexStr1 = i;
		int indexStr2 = 0;

		while (indexStr2 < len2)
		{
			if (str1[indexStr1] == str2[indexStr2])
			{
				++indexStr1;
				++indexStr2;
			}
			else
			{
				break;
			}
		}

		if (indexStr2 == len2 - 1)
		{
			return i;
			break;
		}
	}
}

char* substr(char* str1, int index, int len)
{
	char ululu[]{ 0 };
	int k = 0;
	for (int i = index; i < index + len; ++i)
	{
		ululu[k] = str1[i];
		++k;
	}
	ululu[k] = '\0';

	return ululu;
}

int strcmp(char* str1, char* str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int i = 0;
	while (i < ((len1 < len2) ? len1 : len2))
	{
		if (str1[i] == str2[i])
		{
			++i;
		}
		else
		{
			return str1[i] - str2[i];
		}
	}
	if (i == (len1 < len2) ? len1 : len2)
	{
		return len1 - len2;
	}
}

char* strmult(char* str1, int num)
{
	int len = strlen(str1);
	char newstr[]{ 0 };
	for (int i = 0; i < num; ++i)
	{
		for (int j = i * len; j < i * len + len; ++j)
		{
			newstr[j] = str1[j % len];
		}
	}
	newstr[len * num] = '\0';

	return newstr;
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[]{ 0 };
	fscanf(f, "%s", &a);
	char b[]{ 0 };
	fscanf(f, "%s", &b);
	fclose(f);

	f = fopen("out.txt", "w");

	//fprintf(f, "%s", strcat(a, b));
	//fprintf(f, "%d", strstr(a, b));
	//fprintf(f, "%s", substr(a, 5, 5));
	//fprintf(f, "%d", strcmp(a, b));
	//fprintf(f, "%s", strmult(a, 3));

	fclose(f);

}