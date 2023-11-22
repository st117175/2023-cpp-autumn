#include <iostream>

bool khe(int a, int b)
{
	if (a == 1 && b == 2)
	{
		return 1;
	}

	if (a == 2 && b == 1)
	{
		return 0;
	}

	if (a == 2 && b == 3)
	{
		return 1;
	}

	if (a == 3 && b == 2)
	{
		return 0;
	}

	if (a == 3 && b == 1)
	{
		return 1;
	}

	if (a == 1 && b == 3)
	{
		return 0;
	}
}

void hanoi(int n, int a, int b) {
	if (n > 0) {
		int tmp = 6 - a - b;
		if (khe(a, b)) 
		{
			hanoi(n - 1, a, tmp);
			std::cout << n << " " << a << " " << b << std::endl;
			hanoi(n - 1, tmp, b);
		}
		else 
		{
			hanoi(n - 1, a, b);
			std::cout << n << " " << a << " " << tmp << std::endl;
			hanoi(n - 1, b, a);
			std::cout << n << " " << tmp << " " << b << std::endl;
			hanoi(n - 1, a, b);
		}
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);

	return EXIT_SUCCESS;
}