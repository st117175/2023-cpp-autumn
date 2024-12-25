#include "Data.h"

bool Column::is_empty() 
	{
   		return head == nullptr;
	}

void Column::push_cell_front(std::string str)
{
	Node* newNode = new Node(str, head);
	head = newNode;
}

void Column::push_cell_back(std::string str)
{
	Node* newNode = new Node(str, nullptr);
	if(head == nullptr)
	{
			head = newNode;
	}
	else
	{
		Node* tmp = head;
		while(tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}

void Column::Insert_cell(int index, std::string str)
{
	if(index == 0)
	{
		push_cell_front(str);
	}
	else
	{
		Node* newNode = new Node(str, nullptr);
		Node* tmp = head;
		for(int i = 0; i < index - 1; ++i)
		{
			if(tmp->next == nullptr)
			{
				return;
			}
			tmp = tmp->next;
		}
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}

//Get information from column by index
std::string Column::Data_cell(int index)
{
	Node* tmp = head;
	if(tmp == nullptr)
	{
		return "";
	}
	else
	{
		for(int i = 0; i < index; ++i)
		{
			tmp = tmp->next;
		}
		std::string res = tmp->data;
		return res;
	}
}

void Column::change_data_cell(int index, std::string newData)
{
	Node* tmp = head;
	if(tmp == nullptr)
	{
		return;
	}
	else
	{
		for(int i = 0; i < index; ++i)
		{
			tmp = tmp->next;
		}
		tmp->data = newData;
	}
}

void Column::pop_cell_front()
{
	if(head == nullptr)
	{
		return;
	}
	Node* tmp = head;
	head = head->next;
	delete tmp;
}

void Column::pop_cell_back()
{
	if(head == nullptr)
	{
		return;
	}
	if(head->next == nullptr)
	{
		delete head;
		head = nullptr;
		return;
	}
	Node* tmp = head;
	while(tmp->next->next != nullptr)
	{
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = nullptr; 
}

void Column::Delete_cell(int index)
{
	if(index == 0)
	{
		pop_cell_front();
	}
	else
	{
		Node* tmp = head;
		for(int i = 0; i < index - 1; ++i)
		{
			if(tmp->next == nullptr)
			{
				return;
			}
			tmp = tmp->next;
		}
		if(tmp->next == nullptr)
		{
			return;
		}
		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
	}
}

int Column::length()
{
	int len = 1;
	if(head == nullptr)
	{
		return 0;
	}
	Node* tmp = head;
	while(tmp->next != nullptr)
	{
		tmp = tmp->next;
		++len;
	}
	return len;
}

double Column::max(bool first_line)
{
    double maxElement = std::stod((*this).Data_cell(first_line)); // Инициализируем начальным элементом

    for (int i = 1 + first_line; i < (*this).length(); ++i) 
    {
        if (std::stod((*this).Data_cell(i)) > maxElement) 
        {
            maxElement = std::stod((*this).Data_cell(i));
        }
    }
    return maxElement;
}

double Column::min(bool first_line)
{
    double minElement = std::stod((*this).Data_cell(first_line)); // Инициализируем начальным элементом

    for (int i = 1 + first_line; i < (*this).length(); ++i) 
    {
        if (std::stod((*this).Data_cell(i)) < minElement) 
        {
            minElement = std::stod((*this).Data_cell(i));
        }
    }
    return minElement;
}

double Column::average_value(bool first_line)
{
	double sum = 0;
	for (int i = first_line; i < (*this).length(); ++i) 
    {
    	sum += std::stod((*this).Data_cell(i));
    }
    return sum/((*this).length() - first_line);
}

double Column::standard_deviation(bool first_line)
{
	double average = (*this).average_value(first_line);
	double sum_of_square = 0;
	for(int i = first_line; i < (*this).length(); ++i)
	{
		sum_of_square += (std::stod((*this).Data_cell(i)) - average)*(std::stod((*this).Data_cell(i)) - average);
	}
	return sqrt(sum_of_square/((*this).length() - first_line));
}

void Column::print()
{
	for(int i = 0; i < (*this).length(); ++i)
	{
		std::cout << (*this).Data_cell(i) << "---";
	}
	std::cout << std::endl;
}

std::string Column::operator[](int index)
{
	return (*this).Data_cell(index);
}