#include <iostream>
int main(int argc, char* argv[])
{
	long long int a = 0;
	long long int b = 0;
	long long int c = 0;
	long int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	for (int i = 0; i <= 1000; i++) {
		if (a * i * i * i + b * i * i + c * i + d == 0) {
			std::cout << i << " ";
		}
		else {
			std::cout << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
