#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	bool k = a % 400 == 0;
	if (a % 4 == 0 && a % 100 != 0 || k) {
		std::cout << "YES";
	}else {
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}

