#include <iostream>


class CGraph
{
private:
	int _vertexes;
	int _edges;
	int** _matrix;
public:

	CGraph()
		: _vertexes(0), _edges(0), _matrix(nullptr) {}

	CGraph(int vertexes)
		: _vertexes(vertexes), _edges(0)
	{
		initMatrix();
	}

	~CGraph()
	{
		delete[] _matrix;
		delete[] Istoki();
		delete[] Stoki();
	}

	void setVertexes(int vertexes) { _vertexes = vertexes; }
	int getVertexes() { return _vertexes; }

	void setEdges(int edges) { _edges = edges; }
	int getEdges() { return _edges; }

	void initMatrix()
	{
		if (_vertexes == 0)
		{
			return;
		}
		_matrix = new int* [_vertexes];
		for (int i = 0; i < _vertexes; ++i)
		{
			_matrix[i] = new int[_vertexes] { 0 };
		}
	}

	void ReadMatrix()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			for (int j = 0; j < _vertexes; ++j)
			{
				std::cin >> _matrix[j][i];
			}
		}
	}

	void PrintMatrix()
	{
		if (_matrix == nullptr)
		{
			if (_vertexes == 0)
			{
				std::cout << "Graph empty" << std::endl;
			}
		}
		for (int i = 0; i < _vertexes; ++i)
		{
			for (int j = 0; j < _vertexes; ++j)
			{
				std::cout << _matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	int* Istoki()
	{
		int* Istoki = new int[_vertexes] {0};
		for (int i = 0; i < _vertexes; ++i)
		{
			bool flag = true;
			for (int j = 0; j < _vertexes; ++j)
			{
				if (_matrix[i][j] == 1)
				{
					flag = false;
				}
			}
			if (flag == true)
			{
				Istoki[i] = 1;
			}
		}
		return  Istoki;
	}

	void PrintIstoki()
	{
		int countIstoki = 0;
		for (int i = 0; i < _vertexes; ++i)
		{
			if (Istoki()[i] == 1)
			{
				countIstoki++;
			}
		}
		std::cout << countIstoki << " ";

		for (int j = 0; j < _vertexes; ++j)
		{
			if (Istoki()[j] == 1)
			{
				std::cout << j + 1 << " ";
			}
		}
		std::cout << std::endl;
	}

	int* Stoki()
	{
		int* Stoki = new int[_vertexes] {0};
		for (int i = 0; i < _vertexes; ++i)
		{
			bool flag = true;
			for (int j = 0; j < _vertexes; ++j)
			{
				if (_matrix[j][i] == 1)
				{
					flag = false;
				}
			}
			if (flag == true)
			{
				Stoki[i] = 1;
			}
		}
		return  Stoki;
	}

	void PrintStoki()
	{
		int countStoki = 0;
		for (int i = 0; i < _vertexes; ++i)
		{
			if (Stoki()[i] == 1)
			{
				countStoki++;
			}
		}
		std::cout << countStoki << " ";

		for (int j = 0; j < _vertexes; ++j)
		{
			if (Stoki()[j] == 1)
			{
				std::cout << j + 1 << " ";
			}
		}
		std::cout << std::endl;
	}

};

int main(int argc, char* argv[])
{
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);
	graph.ReadMatrix();

	graph.PrintIstoki();
	graph.PrintStoki();

	return EXIT_SUCCESS;
}