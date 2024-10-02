#include <fstream> 

void printSolution(double* equation, int value)
{
	std::ofstream fout("solution.txt");
	for (int i = 0; i < 2 * value - 1; i += 2)
	{
		fout << "(" << equation[i] << "; " << equation[i + 1] << ")" << std::endl;
	}
	fout.close();
}

void printSolutionRoot(double** equation, int value)
{
	std::ofstream fout("solution.txt");
	for (int i = 0; i < value; ++i)
	{
		fout << "(" << equation[i][0] << "; " << equation[i][1] << ")" << std::endl;
	}
	fout.close();
}

void record_points_root(double** equation, int value)
{
	std::ofstream fout("Points.txt");
	fout << value << " ";
	for (int i = 0; i < value; ++i)
	{
		fout << equation[i][0] << " " << equation[i][1] << " ";
	}
	fout.close();
}

void record_points(double* equation, int value)
{
	std::ofstream fout("Points.txt");
	fout << value << " ";
	for (int i = 0; i < 2 * value - 1; i += 2)
	{
		fout << equation[i] << " " << equation[i + 1] << " ";
	}
	fout.close();
}

int Check_count()
{
	int value = 0;
	std::ifstream fin("Points.txt");
	fin >> value;
	fin.close();
	return value;
}

void ReadPoints(double** Points)
{
	int value = 0;
	std::ifstream fin("Points.txt");
	fin >> value;
	for (int i = 0; i < value; ++i)
	{
		double Re = 0;
		double Im = 0;
		fin >> Re >> Im;
		Points[i][0] = Re;
		Points[i][1] = Im;
	}
	fin.close();
}

void critical_case(int Num_of_case)
{
	if (Num_of_case == 0)
	{
		std::ofstream fout("Solution.txt");
		fout << "NO SOLUTION";
		fout.close();
	}
	if (Num_of_case == 1)
	{
		std::ofstream fout("Solution.txt");
		fout << "The solution is the entire complex plane";
		fout.close();
	}
	if (Num_of_case == -1)
	{
		std::ofstream fout("Solution.txt");
		fout << "You have entered a non-natural degree";
		fout.close();
	}
}
