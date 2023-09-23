#include <iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	if (a == 0 && b == 0) {
		std::cout << "INF";
	}
	else if (a != 0) {
		if (b == 0 && d != 0) {
			std::cout << 0;
		}
		else if (b != 0 && b % a == 0) {
			int x1 = (- b / a);
			if ((b * c) != (a * d)) {
				std::cout << x1;
			}
			else {
				std::cout << "NO";
			}
		}
		else if (b % a != 0) {
			std::cout << "NO";
		}
	}
	else {
		std::cout << "NO";
	}
	
	

	return EXIT_SUCCESS;
}