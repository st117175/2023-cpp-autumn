#include "Dataset.h"

int main()
{
	Dataset chart("chart.txt", 5, 5, 1, 1);
	chart.print();
	chart.remove(2);
	chart.print();
	chart.tail(3);
	chart.tail();
	chart.head(4);
	chart.head();
	chart.insert(1);
	chart.print();
	chart.describe("2");
	chart[1].print();
	std::cout << chart[3][0];
}