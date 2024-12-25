#include "Data.h"


class Dataset
{
private:
	Data* information;
	int number_of_lines;
	int number_of_columns;
	std::pair<bool, bool> p;
public:
	Dataset(std::string link, int nml, int nmc, bool first_column, bool first_line);
//nml and nmc - count of lines and columns excluding column and line with names
//bool first_column responsible for creating line indexing(1 - need to create(we create it ourselves, in file it isn't) , 0 - no need(it is in file))
//bool first_line responsible for creating column indexing(1 - need to create(we create it ourselves, in file it isn't) , 0 - no need(it is in file))
	~Dataset()
	{
		delete information;
	}

	friend std::string stabilization(std::string str);

	void head(int n);
	void head();
	void tail(int n);
	void tail();
	void insert(int index);
	void remove(int index);
	void print();
	void describe(std::string name);

	Column* find_by_name(std::string name);

	Column operator[](int index);
};



