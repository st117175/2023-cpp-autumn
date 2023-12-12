#include <iostream>

void hanoy(int n, int start, int finish)
{
	if (n == 0)
	{
		return;
	}
	else
	{
		if (n <= 0)
		{
			return;
		}

		int res = 6 - start - finish;

		if (n == 1)
		{
			std::cout << 1 << " " << start << " " << finish << std::endl;
		}
		else
		{
			hanoy(n - 1, start, finish);
			hanoy(n - 2, finish, res);
			std::cout << 0 << " " << start << " " << finish << std::endl;
			hanoy(n - 2, res, start);
			hanoy(n - 1, start, finish);
		}
	}
}


int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	hanoy(n, 1, 3);
	return EXIT_SUCCESS;
}