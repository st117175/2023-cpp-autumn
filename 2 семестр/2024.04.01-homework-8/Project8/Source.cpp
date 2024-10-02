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

	CGraph(int vertexes,int edges)
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
		delete[] DegVertex();
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

	int Count_edges()
	{
		int count = 0;
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
				if (_matrix[i][j] >= 1)
				{
					count++;
				}
			}
		}
		setEdges(count / 2);
		return count / 2;
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
			int stlb = 0;
			int str = 0;
			std::cin >> stlb;
			std::cin >> str;
			_matrix[str - 1][stlb - 1] = 1;
		}
	}

	void PrintListSmejnosti()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			std::cout << DegVertex()[i] << " ";
			for (int j = 0; j < _vertexes; ++j)
			{
				if (_matrix[j][i] == 1)
				{
					std::cout << j + 1 << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	int* DegVertex()
	{
		int* degVertex = new int [_vertexes] {0};
		for (int i = 0; i < _vertexes; ++i)
		{
			int deg = 0;
			for (int j = 0; j < _vertexes; ++j)
			{
				if (_matrix[j][i] == 1)
				{
					deg++;
				}
			}
			degVertex[i] = deg;
		}
		return degVertex;
	}

};

int main(int argc, char* argv[])
{
	int vertexes = 0;
	int edges = 0;
	std::cin >> vertexes;
	std::cin >> edges;
	CGraph graph(vertexes, edges);
	graph.MakeMatrix();

	std::cout << graph.getVertexes() << std::endl;
	graph.PrintListSmejnosti();


	return EXIT_SUCCESS;
}