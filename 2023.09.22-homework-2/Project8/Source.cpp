#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a >= b && b >= c) {
		int z = a;
		a = c;
		c = z;
		std::cout << a << " " << b << " " << c;
	}
	if (a >= c && c >= b) {
		int x = a;
		a = b;
		b = x;
		std::cout << a << " " << b << " " << c;
	}
	if (b >= a && a >= c) {
		int v = b;
		b = c;
		c = v;
		std::cout << a << " " << b << " " << c;
	}
	if (b >= c && c >= a) {
		int l = b;
		b = a;
		a = l;
		std::cout << a << " " << b << " " << c;
	}
	if (c >= a && a >= b) {
		int m = c;
		c = b;
		b = m;
		std::cout << a << " " << b << " " << c;
	}
	if (c >= b && b >= a) {
		int q = c;
		c = a;
		a = q;
		std::cout << a << " " << b << " " << c;
	}
	return EXIT_SUCCESS;
}