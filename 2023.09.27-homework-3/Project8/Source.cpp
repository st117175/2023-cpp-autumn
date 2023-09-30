#include <iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int b = 0;
	int n = 0;

	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	if (n > a && n > b) {
		std::cout << "imposible";
	}
	else {
		while (a += a < b){

			std::cout << ">A" << std::endl;
			std::cout << "A>B" << std::endl;


		}
		int x = 0;
		x = b / a;
		a = (x + 1) * a - b;
		std::cout << "B>" << std::endl;
		std::cout << "A>B" << std::endl;
	}

	return EXIT_SUCCESS;//это не решение, если что, так, жалкая попытка
}