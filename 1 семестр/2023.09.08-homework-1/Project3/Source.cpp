#include <iostream>

int main(int argc, char* argv[])
{
	int long long a = 0;
	std::cin >> a;
	int long long c = a / 10; 
	int long long f = c * (c + 1);
	int long long l = f * 100 + 25;
	std::cout << l;
	return EXIT_SUCCESS;
}