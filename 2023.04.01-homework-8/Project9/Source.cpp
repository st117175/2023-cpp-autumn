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

	void MakeMatrix()
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			int degVertex = 0;
			std::cin >> degVertex;
			if (degVertex != 0)
			{
				for (int j = 1; j <= degVertex; ++j)
				{
					int num = 0;
					std::cin >> num;
					_matrix[num - 1][i] = 1;
				}
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
				std::cout << _matrix[j][i] << " ";
			}
			std::cout << std::endl;
		}
	}

};

int main(int argc, char* argv[])
{
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);
	graph.MakeMatrix();

	std::cout << graph.getVertexes() << std::endl;
	graph.PrintMatrix();

	return EXIT_SUCCESS;
}