#include <iostream>

int main(int argc, char* argv[])
{
	unsigned int a = 0;
	std::cin >> a;

	const int BITS = sizeof(unsigned int) * 8;

	if (a == 0)
	{
		a = ~a;
	}
	else
	{
		int nachalo = BITS - 1;
		int konec = 0;
		
		while ((a >> nachalo & 1) == 0)
		{
			--nachalo;
		}
		
		while ((a >> konec & 1) == 0)
		{
			++konec;
		}

		nachalo--;
		konec++;

		unsigned int mask = 0;
		for (int i = konec; i <= nachalo; ++i)
		{
			mask = mask | (1 << i);
		}

		a = a ^ mask;

		std::cout << "0b ";
		for (int i = BITS - 1; i >= 0; --i)
		{
			std::cout << ((a >> i) & 1) << (i % 4 == 0 ? " " : "");
		}
		std::cout << std::endl;
	}

	return EXIT_SUCCESS;
}
