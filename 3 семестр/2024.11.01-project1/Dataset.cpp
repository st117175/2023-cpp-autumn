#include "Dataset.h"


Dataset::Dataset(std::string link, int nml, int nmc, bool first_column, bool first_line): number_of_lines(nml + first_line), number_of_columns(nmc + first_column)//nml and nmc - count of lines and columns excluding column and line with names
{
	information = new Data(number_of_columns + first_column);
	std::ifstream f;
	f.open(link);
	if (!f)
	{
		std::cout << "Uh oh, SomeText.txt could not be opened for reading!" << std::endl;
		return;
	}
	for(int i = first_line; i < number_of_lines; ++i)
	{
		for(int j = first_column; j < number_of_columns; ++j)
		{
			std::string cell;
				f >> cell;
			information->Arr_of_Col[j].push_cell_back(cell);
		}
	}
	f.close();
	if(first_column == 1)
	{
		for(int i = first_line; i < number_of_lines; ++i)
		{
			information->Arr_of_Col[0].push_cell_back(std::to_string(i));
		}
	}
	if(first_line == 1)
	{
		std::cout << "enter names of columns";
		for(int i = 0; i < number_of_columns; ++i)
		{
			std::string name = "";
			std::cin >> name;
			information->Arr_of_Col[i].push_cell_front(name);
		}
	}
	p = {first_column, first_line};
}
//bool first_column responsible for creating line indexing(1 - need to create(we create it ourselves, in file it isn't) , 0 - no need(it is in file))
//bool first_line responsible for creating column indexing(1 - need to create(we create it ourselves, in file it isn't) , 0 - no need(it is in file))

std::string stabilization(std::string str)
{
	int n = str.size();
	for(int i = 0; i < 7 - n; ++i)
	{
		str += " ";
	}
	return str;
}

void Dataset::head(int n)
{
	std::cout << "method 'head'" << std::endl;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < number_of_columns; ++j)
		{
			std::cout << stabilization(information->Arr_of_Col[j].Data_cell(i));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Dataset::head()
{
	if(number_of_lines < 5)
	{
		head(number_of_lines);
	}
	else
	{
		head(5);
	}
	std::cout << std::endl;
}

void Dataset::tail(int n)
{
	std::cout << "method 'tail'" << std::endl;
	if((*this).p.second == 1)
	{
		for(int i = 0; i < number_of_columns; ++i)
		{
			std::cout << stabilization(information->Arr_of_Col[i].Data_cell(0));
		}
		std::cout << std::endl;
	}
	for(int i = number_of_lines - n; i < number_of_lines; ++i)
	{
		for(int j = 0; j < number_of_columns; ++j)
		{
			std::cout << stabilization(information->Arr_of_Col[j].Data_cell(i));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Dataset::tail()
{
	if(number_of_lines <= 5)
	{
		tail(number_of_lines - (*this).p.second);
	}
	else
	{
		tail(5);
	}
	std::cout << std::endl;
}

void Dataset::insert(int index)
{
	std::cout << "method insert" << std::endl;
	for(int i = 0; i < number_of_columns; ++i)
	{
		information->Arr_of_Col[i].Insert_cell(index, "0");
	}
	++number_of_lines;
	std::cout << std::endl;

	//change indexing of lines
	if((*this).p.first == 1)
	{
		for(int i = index; i < number_of_lines; ++i)
		{
			information->Arr_of_Col[0].change_data_cell(i, std::to_string(i));
		}
	}
}

void Dataset::remove(int index)
{
	std::cout << "method remove" << std::endl;
	for(int i = 0; i < number_of_columns; ++i)
	{
		information->Arr_of_Col[i].Delete_cell(index);
	}
	number_of_lines--;
	std::cout << "was removed line by index " << index << std::endl << std::endl;

	//change indexing of lines
	if((*this).p.first == 1)
	{
		for(int i = index; i < number_of_lines; ++i)
		{
			information->Arr_of_Col[0].change_data_cell(i, std::to_string(i));
		}
	}
}

void Dataset::print()
{
	for(int i = 0; i < number_of_lines; ++i)
	{
		for(int j = 0; j < number_of_columns; ++j)
		{
			std::cout << stabilization(information->Arr_of_Col[j].Data_cell(i));
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

Column* Dataset::find_by_name(std::string name)
{
	for(int i = 0; i < number_of_columns; ++i)
	{
		if(information->Arr_of_Col[i].Data_cell(0) == name)
		{
			return &information->Arr_of_Col[i];
		}
	}
	std::cout << "this column is not. Oh, no, EROR....";
}

void Dataset::describe(std::string name)
{
	std::cout << "method describe" << std::endl;
	Column* curr = (*this).find_by_name(name);
	std::cout << "max element from column called ''" << name << "'' is" << (*curr).max((*this).p.second) << std::endl;
	std::cout << "min element from column called ''" << name << "'' is" << (*curr).min((*this).p.second) << std::endl;
	std::cout << "average value from column called ''" << name << "'' is" << (*curr).average_value((*this).p.second) << std::endl;
	std::cout << "standart deviation of elements from column called ''" << name << "'' is" << (*curr).standard_deviation((*this).p.second) << std::endl;
	std::cout << std::endl;
}

Column Dataset::operator[](int index)
{
	Column line;
	for(int i = 0; i < number_of_columns; ++i)
	{
		line.push_cell_back(information->Arr_of_Col[i].Data_cell(index));
	}
	return line;
}