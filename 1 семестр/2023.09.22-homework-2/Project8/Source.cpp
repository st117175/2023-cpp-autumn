#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	int max = 0;
	int min = 0;
	int sr = 0;
	if (a >= b) {
		if (b >= c) {
			 max = a;
			 min = c;
			 sr = b;
		}
		else if (b <= c) {
			if (a >= c) {
				 max = a;
				 min = b;
				 sr = c;
			}
			else if (a <= c) {
				 max = c;
				 min = b;
				 sr = a;
			}
		}
	}
	else if (a <= b) {
		if (c <= a) {
			max = b;
			min = c;
			sr = a;
		}
		else if (c >= a) {
			if (b <= c) {
				 max = c;
				 min = a;
				 sr = b;
			}
			else if (b >= c) {
				 max = b;
				 min = a;
				 sr = c;
			}
		}
	}
	a = min;
	b = sr;
	c = max;
	std::cout << a << " " << b << " " << c;
	return EXIT_SUCCESS;
}