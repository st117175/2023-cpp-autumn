#include <iostream>

struct Node
{
	int data;
	Node* next;

	Node(int data, Node* next = nullptr)
		:data(data), next(next) {}

	Node(const Node& src)
		: data(src.data), next(nullptr) {}

	~Node()
	{
		data = 0; next = nullptr;
	}

	friend std::ostream& operator<<(std::ostream& stream, Node*& node)
	{
		stream << node->data << " ";
		return stream;
	}
	//конструкторы(2), деструктор, оператор вывода
};

class LinkedList
{
public:
	LinkedList() : head(nullptr) {}
	~LinkedList() { dispose(); }
	int Length();
	bool IsEmpty();
	void PushHead(int data);

	//вставляет элемент data на позицию index
	void Insert(int index, int data);
	void PushTail(int data);

	//извлекает головной элемент
	int PopHead();

	//извлекает данные из позиции index
	//и удаляет элемент из списка
	int Extract(int index);
	int PopTail();

	//получает данные из позиции index
	//без удаления из списка
	int Data(int index);
	void swap(int ia, int ib);
	void sort();
	//оператор вывода в поток
	friend std::ostream& operator<<(std::ostream& stream, const LinkedList& list);
private:
	void dispose();

	//извлекает данные из ноды и удаляет саму ноду
	int PopData(Node* node); //!
	void InsertNode(int index, Node* node); //!
	Node* ExtractNode(int index); //!
	bool indexValid(int index);
	Node* head;
};

int main(int argc, char* argv[])
{
	LinkedList list;
	std::cout << list << std::endl;
	list.PushHead(1);
	std::cout << list << std::endl;
	list.PushTail(3);
	std::cout << list << std::endl;
	list.Insert(1, 2);
	std::cout << list << std::endl;
	list.Insert(3, 4);
	std::cout << list << std::endl << std::endl;
	std::cout << list << std::endl;
	std::cout << list.PopHead() << " ";
	std::cout << list.Extract(1) << " ";
	std::cout << list.PopTail() << " ";
	std::cout << list.Extract(0) << std::endl;
	std::cout << list << std::endl << std::endl;

	list.PushHead(3); list.PushHead(4); list.PushHead(1); list.PushHead(2);
	list.PushHead(7); list.PushHead(5); list.PushHead(8); list.PushHead(6);
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;
	return EXIT_SUCCESS;
}

int LinkedList::Length()
{
	int Length = 0;
	Node* tmp = head;
	if (head == nullptr)
	{
		return 0;
	}
	while (tmp->next != nullptr)
	{
		Length++;
		tmp = tmp->next;
	}
	return Length + 1;
}

bool LinkedList::IsEmpty()
{
	if (Length() == 0)
	{
		return true;
	}
	return false;
}

void LinkedList::PushHead(int data)
{
	Node* node =new Node(data, head);
	head = node;
}

void LinkedList::Insert(int index, int data)
{
	if (index == 0)
	{
		return PushHead(data);
	}
	if (index == Length())
	{
		return PushTail(data);
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	Node* node = new Node(data, tmp->next);
	tmp->next = node;
	delete tmp;
}

void LinkedList::PushTail(int data)
{
	Node* tmp = head;
	while (tmp->next != nullptr)
	{
		tmp = tmp->next;
	}
	Node* node = new Node(data);
	tmp->next = node;
}

int LinkedList::PopHead()
{
	if (IsEmpty())
	{
		return -1;
	}
	Node* tmp = head;
	head = head->next;
	int res = tmp->data;
	delete tmp;
	return res;
}

int LinkedList::PopTail()
{
	Node* tmp = head;
	for (int i = 0; i < Length(); ++i)
	{
		tmp = tmp->next;
	}
	int res = tmp->data;
	tmp = nullptr;
	return res;
}

int LinkedList::Extract(int index)
{
	if (IsEmpty())
	{
		return -1;
	}
	if (!indexValid(index))
	{
		return -1;
	}
	Node* tmp = head;
	for (int i = 0; i < index - 1; ++i)
	{
		tmp = tmp->next;
	}
	int res = tmp->next->data;
	Node* helper = tmp->next->next;
	delete tmp->next;
	tmp->next = helper;
	delete helper;
	return res;
}

int LinkedList::Data(int index)
{
	Node* tmp = head;
	for (int i = 0; i < index + 1; ++i)
	{
		tmp = tmp->next;
	}
	int res = tmp->data;
	delete tmp;
	return res;
}

void LinkedList::dispose()
{
	while (!IsEmpty())
	{
		PopHead();
	}
}

int LinkedList::PopData(Node* node)
{
	int res = node->data;
	delete node;
	return res;
}

void LinkedList::InsertNode(int index, Node* node)
{
	if (index == 0)
	{
		node->next = head;
		head = node;
		return;
	}

	if (!indexValid(index))
	{
		return;
	}

	if (index == Length())
	{
		Node* tmp = head;
		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		tmp->next = node;
		return;
	}
	if (index < Length())
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; ++i)
		{
			tmp = tmp->next;
		}
		node->next = tmp->next;
		tmp->next = node;
	}
}

Node* LinkedList::ExtractNode(int index)
{
	if (!indexValid(index))
	{
		return nullptr;
	}
	if (index == 0)
	{
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
	if (index < Length())
	{
		Node* tmp = head;
		for (int i = 0; i < index - 1; i++)
		{
			tmp = tmp->next;
		}
		Node* res = tmp->next;
		tmp->next = tmp->next->next;
		return res;
	}
	if (index == Length() - 1)
	{
		Node* tmp = head;
		while (tmp->next->next != nullptr)
		{
			tmp = tmp->next;
		}
		Node* res = tmp->next;
		tmp->next = nullptr;
		return res;
	}
}

bool LinkedList::indexValid(int index)
{
	if (index >= 0 && index <= Length())
	{
		return true;
	}
	return false;
}

void LinkedList::swap(int ia, int ib)
{
	if (ia == ib || !indexValid(ia) || !indexValid(ib))
	{
		return;
	}
	if (ia > ib)
	{
		return swap(ib, ia);
	}
	Node* nodea = ExtractNode(ib);
	Node* nodeb = ExtractNode(ia);
	InsertNode(ia, nodeb);
	InsertNode(ib, nodea);
}

void LinkedList::sort()
{
	for (int i = 0; i < Length(); ++i)
	{
		for (int j = 0; j < Length(); ++j)
		{
			if (Data(j) > Data(j + 1))
			{
				swap(j, j + 1);
			}
		}
	}
}

std::ostream& operator<<(std::ostream& stream, const LinkedList& list)
{
	Node* tmp = list.head;
	while (tmp != nullptr)
	{
		stream << tmp << " ";
		tmp = tmp->next;
	}
	return stream;
}




