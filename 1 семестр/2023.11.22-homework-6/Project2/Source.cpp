#include <iostream>

void hanoi(int n, int start, int finish)
{
	if (n == 1)
	{
		std::cout << n << " " << start << " " << 2 << std::endl;
		std::cout << n << " " << 2 << " " << finish << std::endl;
	}
	else
	{
		hanoi(n - 1, start, finish);
		std::cout << n << " " << start << " " << 2 << std::endl;
		hanoi(n - 1, finish, start);
		std::cout << n << " " << 2 << " " << finish << std::endl;
		hanoi(n - 1, start, finish);
	}
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoi(n, 1, 3);

	return EXIT_SUCCESS;
}
