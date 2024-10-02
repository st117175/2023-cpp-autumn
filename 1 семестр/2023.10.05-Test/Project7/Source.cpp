#include <iostream>
#include <iomanip>

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << std::setw(2) << std::setfill('0') << (2 * n - 1) - (i + j) << " ";
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
