#include <iostream>
int main(int argc, char* argv[])
{
	int n = 0;
	int k = 0;
	int l = 1;
	std::cin >> n;
	while (l < n) {
		l *= 2;
		k++;
	}
	std::cout << k;
	return EXIT_SUCCESS;
}