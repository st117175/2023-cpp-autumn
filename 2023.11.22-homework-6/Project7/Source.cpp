#include <iostream>

int a[4]{ 0 };
int** rods = new int* [4] { nullptr, new int[10] {0}, new int[10] {0}, new int[10] {0}};

void shift(int from, int to)
{
	std::cout << rods[from][a[from] - 1] << " " << from << " " << to << std::endl;

	rods[to][a[to]] = rods[from][a[from] - 1];
	rods[from][a[from] - 1] = 0;

	a[to]++;
	a[from]--;
}

void swap(int& num1, int& num2)
{
	int help = num1;
	num1 = num2;
	num2 = help;
}

int topElement(int num)
{
	if (a[num] > 0)
	{
		return rods[num][a[num] - 1];
	}
	else
	{
		return 100;
	}
}

void hanoy(int n, int from, int to)
{
	if (n == 0)
	{
		return;
	}
	if (n == 1)
	{
		shift(from, to);
	}
	else
	{
		int temp = 6 - from - to;
		hanoy(n - 1, from, temp);
		shift(from, to);
		hanoy(n - 1, temp, to);
	}
}

void hanoy1()
{
	int rodsA = 1;
	int rodsB = 2;
	int rodsC = 3;
	while (a[rodsA] > 0)
	{
		int k = topElement(1);
		while (topElement(rodsC) < k)
		{
			int g = 0;
			for (int i = 0; i < a[rodsB]; ++i)
			{
				if (rods[rodsB][i] < topElement(rodsC))
				{
					g++;
				}
			}
			hanoy(g, rodsB, rodsC);
			swap(rodsB, rodsC);
		}
		shift(rodsA, rodsC);
	}

	while (a[rodsC] > 0)
	{
		int g = 0;
		for (int i = 0; i < a[rodsB]; ++i)
		{
			if (rods[rodsB][i] < topElement(rodsC))
			{
				g++;
			}
		}
		hanoy(g, rodsB, rodsC);
		swap(rodsB, rodsC);
	}
}

int main(int argc, char** argv[])
{
	int n = 0;
	std::cin >> n;

	a[1] = n;

	for (int i = n - 1; i >= 0; --i)
	{
		std::cin >> rods[1][i];
	}

	hanoy1();

	return EXIT_SUCCESS;
}