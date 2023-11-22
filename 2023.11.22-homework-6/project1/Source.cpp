#include <iostream>

void hanoi(int n, int start, int finish)
{
	if (n == 1)
	{
		std::cout << n << " " << start << " " << finish << std::endl;
	}
	else
	{
		int temp = 6 - start - finish;
		hanoi(n - 1, start, temp);
		std::cout << n << " " << start << " " << finish << std::endl;
		hanoi(n - 1, temp, finish);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);

	return EXIT_SUCCESS;
}
