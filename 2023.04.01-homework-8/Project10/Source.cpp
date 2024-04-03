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

	void ReadMatrix()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			for (int j = 0; j < _vertexes; ++j)
			{
				std::cin >> _matrix[i][j];
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

	int* DegVertex()
	{
		int* degVertex = new int [_vertexes] {0};
		for (int i = 0; i < _vertexes; ++i)
		{
			int deg = 0;
			for (int j = 0; j < _vertexes; ++j)
			{
				if (_matrix[i][j] == 1)
				{
					deg++;
				}
			}
			degVertex[i] = deg;
		}
		return degVertex;
	}

	void print_DegVertex()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			std::cout << DegVertex()[i] << " ";
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
	graph.print_DegVertex();


	return EXIT_SUCCESS;
}