#include <iostream>
#include <cstdlib>
#include <ctime>

void printMenu()
{
	std::cout << "0 - EXIT" << std::endl;
	std::cout << "1 - PRINT ARRAY" << std::endl;
	std::cout << "2 - ADD ELEMENT" << std::endl;
	std::cout << "3 - DELETE ELEMENT" << std::endl;
	std::cout << "4 - ARRANGE IN ASCENDING ORDER" << std::endl;
	std::cout << "5 - UNWRAP ARRAY" << std::endl;
	std::cout << "6 - CHANGE MAX AND MIN" << std::endl;
	std::cout << "7 - DELETE DUPLICATE" << std::endl;
	std::cout << "8 - ADD SEVERAL RANDOM ELEMENTS" << std::endl;
}

void unwrapArray(int*& a, int& tyu)
{
	if (a != nullptr)
	{
		for (int i = 0; i < (tyu / 2); ++i)
		{
			std::swap(a[i], a[tyu - i - 1]);
		}
	}
	else
	{
		std::cout << "empty" << std::endl;
	}
}

void printArray(int* a, int& tyu)
{
	if (a == nullptr)
	{
		std::cout << "empty" << std::endl;
	}
	else
	{
		for (int i = 0; i < tyu; ++i)
		{
			std::cout << a[i] << " ";
		}
	}
	std::cout << std::endl;
}

void expandArray(int*& a, int& tyu)
{
	int* newA = new int[tyu + 1] { 0 };
	if (a != nullptr)
	{
		for (int i = 0; i < tyu; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++tyu;
}

void addElement(int*& a, int& tyu, int newElement)
{
	expandArray(a, tyu);
	a[tyu - 1] = newElement;
}

void deleteElement(int*& a, int& tyu, int& num)
{
	if (a != nullptr)
	{
		int* newA = new int[tyu - 1];
		for (int i = 0; i < num; ++i)
		{
			newA[i] = a[i];
		}
		for (int j = num; j < tyu - 1; ++j)
		{
			newA[j] = a[j + 1];
		}
		delete[] a;
		a = newA;
		--tyu;
	}
	else
	{
		std::cout << "empty" << std::endl;
	}
}

void ascending(int*& a, int& tyu)
{
	if (a != nullptr)
	{
		for (int k = 0; k < tyu - 1; ++k)
		{
			for (int i = 0; i < tyu - 1; ++i)
			{
				if (a[i] > a[i + 1])
				{
					std::swap(a[i], a[i + 1]);
				}
			}
		}
	}
	else
	{
		std::cout << "empty" << std::endl;
	}
}

int searchMin(int* a, int& tyu)
{
	int min = a[0];
	for (int i = 0; i < tyu; ++i)
	{
		if (a[i + 1] < a[i])
		{
			min = a[i + 1];
		}
	}
	for (int j = 0; j < tyu; ++j)
	{
		if (a[j] == min)
		{
			min = j;
		}
	}
	return min;
}

int searchMax(int* a, int& tyu)
{
	int max = a[0];
	for (int i = 0; i < tyu; ++i)
	{
		if (a[i + 1] > a[i])
		{
			max = a[i + 1];
		}
	}
	for (int j = 0; j < tyu; ++j)
	{
		if (a[j] == max)
		{
			max = j;
		}
	}
	return max;
}

void changeMaxMin(int*& a, int& tyu)
{
	if (a != nullptr)
	{
		std::swap(a[searchMax(a, tyu)], a[searchMin(a, tyu)]);
	}
	else
	{
		std::cout << "empty" << std::endl;
	}
}

void deleteDuplicate(int*& a, int& tyu)
{
	if (a != nullptr)
	{
		for (int i = 0; i < tyu - 1; ++i)
		{
			for (int j = i + 1; j < tyu; ++j)
			{
				if (a[i] == a[j])
				{
					deleteElement(a, tyu, j);
				}
			}
		}
	}
	else
	{
		std::cout << "empty" << std::endl;
	}
}

void addRandomElements(int*& a, int& tyu, int count)
{
	srand(time(NULL));
	for (int i = 0; i < count; ++i)
	{
		addElement(a, tyu, rand());
	}
}
