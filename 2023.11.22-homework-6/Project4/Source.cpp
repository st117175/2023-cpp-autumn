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
		hanoi(n - 1, start, finish);
		std::cout << n << " " << start << " " << temp << std::endl;
		hanoi(n - 1, finish, start);
		std::cout << n << " " << temp << " " << finish << std::endl;
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