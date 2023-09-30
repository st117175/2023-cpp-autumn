#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int f0 = 0;
	int f1 = 1;
	int fn = 0;
	if (n == 0) {
		std::cout << 0;
	}
	else if (n == 1) {
		std::cout << 1;
	}
	else {
		n = n - 1;
		while (n > 0) {
			fn = f0 + f1;
			f0 = f1;
			f1 = fn;
			n--;
		}
		std::cout << fn;
	}
	return EXIT_SUCCESS;
}