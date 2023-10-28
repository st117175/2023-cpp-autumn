#include "Array.h"
#include <cstdlib>
#include <ctime>

int main(int argc, char* argv[])
{
	int* a = nullptr;
	int tyu = 0;
	bool exit = false;

	while (!exit) 
	{
		{
			system("cls");
			printMenu();
			printArray(a, tyu);
			
		}

		int choise = 0;
		std::cin >> choise;

		switch (choise)
		{
		case(0):
		{
			exit = true;
			break;
		}
		case(1):
		{
			printArray(a, tyu);
			system("pause");
			break;
		}
		case(2):
		{
			std::cout << "enter the value of the element" << std::endl;
			int newElement = 0;
			std::cin >> newElement;
			addElement(a, tyu, newElement);
			break;
		}
		case(3):
		{
			std::cout << "enter the index of the element" << std::endl;
			int num = 0;
			std::cin >> num;
			deleteElement(a, tyu, num);
			break;
		}
		case(4):
		{
			ascending(a, tyu);
			break;
		}
		case(5):
		{
			unwrapArray(a, tyu);
			break;
		}
		case(6):
		{
			changeMaxMin(a, tyu);
			break;
		}
		case(7):
		{
			deleteDuplicate(a, tyu);
			break;
		}
		case(8):
		{
			std::cout << "how many elements should I add?" << std::endl;;
			int count = 0;
			std::cin >> count;
			addRandomElements(a, tyu, count);
			break;
		}
		default:
		{
			std::cout << "Unknown command" << std::endl;
			break;
		}
		}
	}
	delete[] a;
	return EXIT_SUCCESS;
}
