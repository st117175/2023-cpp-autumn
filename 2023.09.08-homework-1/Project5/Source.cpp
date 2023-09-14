#include <iostream>

int main(int argc, char* argv[])
{
	int v = 0;
	int t = 0;
	std::cin >> v;
	std::cin >> t;
	int k = (v * t) % 109;
	std::cout << (k + 109) % 109 + 1;
	return EXIT_SUCCESS;
}