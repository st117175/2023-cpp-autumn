#include <iostream>
int main(int argc, char* argv[])
{

	int n = 0;
	std::cin >> n;
	int q = n / 60;
	int w = (n - q * 60) / 20;
	int e = (n - q * 60 - w * 20) / 10;
	int r = (n - q * 60 - w * 20 - e * 10) / 5;
	int t = (n - q * 60 - w * 20 - e * 10 - r * 5);
	int sum1 = q * 440 + w * 230 + e * 125 + r * 70 + t * 15;
	int sum2 = (q + 1) * 440;
	int sum3 = q * 440;
	int deshevle = 0;
	if (n % 60 > 0 && n % 60 < 40) {
		deshevle = sum1;
	}
	else if (n % 60 >= 40 && n % 60 < 60) {
		deshevle = sum2;	
	}
	else if (n % 60 == 0) {
		deshevle = sum3;
	}
	if (deshevle == sum1) {
		std::cout << t << " " << r << " " << e << " " << w << " " << q;
	}
	if (deshevle == sum2) {
		std::cout << 0 << " " << 0 << " " << 0 << " " << 0 << " " << q + 1;
	}
	if (deshevle == sum3) {
		std::cout << 0 << " " << 0 << " " << 0 << " " << 0 << " " << q;
	}
 

	
	return EXIT_SUCCESS;
}
