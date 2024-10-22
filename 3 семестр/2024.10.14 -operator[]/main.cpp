#include "string.h"

int main()
{
	String str = String("Kirill Chikpikmik");
	String str1 = str[0][6];
	String str2 = str[11][16];
	str1.print();
	str2.print();
};
