#include <iostream>
int main(int argc, char* argv[])
{
	int k = 0;
	int m = 0;
	int n = 0;
	std::cin >> k;//вместимость сковороды(это и кол-во котлет на ней и соответственно кол-во сторон этих котлет)
	std::cin >> m;//время обжарки с одной стороны
	std::cin >> n;//кол-во котлет
	if (n >= k) {
		int st = 2 * n; //кол-во всех сторон котлет, которые нужно обжарить
		if (st >= k) {
			if (st % k == 0) {
				std::cout << st / k * m;
			}
			else if (st % k != 0) {
				std::cout << st / k * m + m;
			}
		}
	}
	else if (n < k) {
		std::cout << 2 * m;
	}
	return EXIT_SUCCESS;
}