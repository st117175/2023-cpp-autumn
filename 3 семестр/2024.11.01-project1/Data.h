#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cmath>

struct Node
{
	std::string data;
	Node* next;

	Node(std::string data, Node* next = nullptr)
		:data(data), next(next) {}
};

class Column
{
	private:
		Node* head;
	public:
		Column(): head(nullptr) {}
		bool is_empty();
		void push_cell_front(std::string str);
		void push_cell_back(std::string str);
		void Insert_cell(int index, std::string str);
		std::string Data_cell(int index);
		void change_data_cell(int index, std::string newData);
		void pop_cell_front();
		void pop_cell_back();
		void Delete_cell(int index);
		int length();
		void print();

		double max(bool first_line);
		double min(bool first_line);
		double average_value(bool first_line);
		double standard_deviation(bool first_line);

		std::string operator[](int index);
};

struct Data
{
	Column* Arr_of_Col = nullptr;

	Data(int count)
	{
		this->Arr_of_Col = new Column[count];
	}
	~Data()
	{
		delete[] Arr_of_Col;
	}
};