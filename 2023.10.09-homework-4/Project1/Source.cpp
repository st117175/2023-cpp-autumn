#include <iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;

	int* a = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> *(a + i);
	}

	int kolich = 0;

	for (int i = 0; i < n; i ++)
	{
		if (*(a + i) > 0)
		{
			++kolich;
		}
	}
	std::cout << kolich;

	free(a);

	return EXIT_SUCCESS;
}
