#include <iostream>
#include <cmath>

int main(int argc, char* argv[])
{
	long int x = 0;
	std::cin >> x;
	int znacheniex = x;
	long int k = 0;
	long int i = 0;
	while (x > 0) { //этот цикл для того, чтобы посчитать кол-во цифр в числе (i)
		k = x % 10;
		x = x / 10;
		++i;
	}
	long int m = 0;
	while (i > 0) { //здесь, зная кол-во цифр, мы знаем, на какую степень десятки нужно домножить цифру, чтобы записать ее в итоговое число
		k = znacheniex % 10;
		znacheniex = znacheniex / 10;
		m = m + k * pow(10, i - 1);
		--i;
	}
	std::cout << m;
	return EXIT_SUCCESS;
}