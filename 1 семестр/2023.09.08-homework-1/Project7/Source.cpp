#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	int m = a - 1;
	int k = a + 1;
	std::cout << "The next number for the number " << a << " is " << k << "." << std::endl;
	std::cout << "The previous number for the number " << a << " is " << m << ".";
    return EXIT_SUCCESS;
}