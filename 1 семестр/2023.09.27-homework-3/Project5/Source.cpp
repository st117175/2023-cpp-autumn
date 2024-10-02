#include <iostream>
int main(int argc, char* argv[])
{
    int k = 0;
    int i = 0;
    std::cin >> k;
    int n = 0;
    while (n < k) {
        n++;
        int z = n;
        int m = 0;
        while (z)
        {
            m = m * 10 + z % 10;
            z /= 10;
        }
        if (m == n) {
            i++;
        }
    }
    std::cout << i;
    return EXIT_SUCCESS;
}