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

	CGraph(int vertexes, int edges)
		: _vertexes(vertexes), _edges(edges)
	{
		initMatrix();
	}

	CGraph(const CGraph& src) : _vertexes(src._vertexes) {
		initMatrix();
		for (int i = 0; i < _vertexes; ++i)
		{
			for (int j = 0; j < _vertexes; ++j)
			{
				_matrix[i][j] = src._matrix[i][j];
			}
		}
	}

	~CGraph()
	{
		disposeMatrix();
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

	void disposeMatrix()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
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

	void MakeMatrix()
	{
		for (int i = 0; i < _edges; ++i)
		{
			int str = 0;
			int stlb = 0;
			std::cin >> str;
			std::cin >> stlb;
			_matrix[stlb - 1][str - 1] = 1;
		}
	}

	bool Turnir()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			if (_matrix[i][i] == 1)
			{
				return false;
			}
			for (int j = i + 1; j < _vertexes; ++j)
			{
				if (_matrix[i][j] + _matrix[j][i] != 1)
				{
					return false;
				}
			}

		}
		return true;
	}

	void PrintTurnir()
	{
		if (Turnir() == true)
		{
			std::cout << "YES";
		}
		else
		{
			std::cout << "NO";
		}
	}

};

int main(int argc, char* argv[])
{
	int vertexes = 0;
	std::cin >> vertexes;
	int edges = 0;
	std::cin >> edges;
	CGraph graph(vertexes, edges);
	graph.MakeMatrix();
	graph.PrintTurnir();

	return EXIT_SUCCESS;
}