#include <iostream>

void hanoi1(int n, int start, int finish) 
{
	if (n > 0) 
	{
		int tmp = 6 - start - finish;
		hanoi1(n - 1, start, tmp);
		std::cout << n << " " << start << " " << finish << std::endl;
		hanoi1(n - 1, tmp, finish);
	}
}

void hanoi2(int n)
{
	int k;
	if (n % 2 == 0) 
	{
		k = 3;
	}
	else 
	{
		k = 2;
	}

	int i = 1;
	hanoi1(n, i, k);

	int tmp = 5 - k;
	for (int i = n; i > 0; i--) 
	{
		hanoi1(i - 1, k, tmp);
		std::swap(k, tmp);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi2(n);

	return EXIT_SUCCESS;
}