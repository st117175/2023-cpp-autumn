#include <iostream>

int main(int argc, char* argv[])
{
	unsigned int a = 0;
	std::cin >> a;

	const int BITS = sizeof(unsigned int) * 8;
	
	int sum = 0;
	for (int i = BITS - 1; i >= 0; --i)
	{
		sum += (a & 1);
		a = a >> 1;
	}
	std::cout << sum;

	return EXIT_SUCCESS;
}
