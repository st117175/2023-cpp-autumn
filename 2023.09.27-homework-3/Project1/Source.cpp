#include <iostream>
int main(int argc, char* argv[])
{
	int a = 0;
	int l = 1;
	std::cin >> a;
	for (int i = 0; l <= a; i++) {
		for (int j = 0; j < i && l <= a; j++) {
			std::cout << i << " ";
			l++;
		}
	}



	return EXIT_SUCCESS;
}