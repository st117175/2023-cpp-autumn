#include <iostream>
int main(int argc, char* argv[])
{
	long int x = 0;
	int del = 0;
	std::cin >> x;
	int i = 1;
	while(i * i < x) {
		if (x % i == 0) {
			del += 2;
		}
		i++;
	}
	if (i * i == x) {
		del += 1;
	}
	std::cout << del;
	return EXIT_SUCCESS;
}