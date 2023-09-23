#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;
	int f = n % 100;
	int k = f % 10;
	if (f == 1) {
		std::cout << n << " " << "bochka";
	}
	if (f == 2 || f == 3 || f == 4) {
		std::cout << n << " " << "bochki";
	}
	if (f >= 5 && f <= 20) {
		std::cout << n << " " << "bochek";
	}
	if (f > 20 && k == 1) {
		std::cout << n << " " << "bochka";
	}
	if (f > 20 && (k == 2 || k == 3 || k == 4)) {
		std::cout << n << " " << "bochki";
	}
	if (f > 20 && ((k >= 5 && k <= 9) || k == 0 )) {
		std::cout << n << " " << "bochek";
	}
	if (n == 1000 || n == 0 || n == 100 || n == 200 || n == 300 || n == 400 || n == 500 || n == 600 || n == 700 || n == 800 || n == 900) {
		std::cout << n << " " << "bochek";
	}
	return EXIT_SUCCESS;
}
