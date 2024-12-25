#include "array.h"

int main()
{
	double double_arr1[] = {3.14, 2.71, 1.61, 4.2, 0.5};    
    Array<double> doubleArray1(double_arr1);

    double double_arr2[] = {5.67, 13.62, 0.34, 4.2, 1.7};    
    Array<double> doubleArray2(double_arr2);

    std::cout << "doubleArray1 ";
    doubleArray1.show();

    std::cout << "doubleArray2 ";
    doubleArray2.show();

    std::cout << "Minimum value in doubleArray1: " << doubleArray1.minimum() << std::endl;
    std::cout << "Minimum value between doubleArray1 and doubleArray2: " << doubleArray1.minimum(doubleArray2) << std::endl;
}