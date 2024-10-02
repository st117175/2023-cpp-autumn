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

	int max = *a;
	int min = *a;
	for (int i = 0; i < n; ++i)
	{
		if (max < *(a + i))
		{
			max = *(a + i);
		}

		if (min > *(a + i))
		{
			min = *(a + i);
		}
	}

	int num_min = 0;
	for (int l = 0; l < n - 1; ++l)
	{
		if (*(a + l) == min)
		{
			num_min = l;
			break;
		}
	}
	
	int num_max = 0;
	for (int j = n - 1; j >= 0; --j)
	{
		if (*(a + j) == max)
		{
			num_max = j;
			break;
		}
	}

	*(a + num_min) = max;
	*(a + num_max) = min;

	for (int i = 0; i < n; ++i)
	{
		std::cout << *(a + i) << " ";
	}

	free(a);

	return EXIT_SUCCESS;
}

