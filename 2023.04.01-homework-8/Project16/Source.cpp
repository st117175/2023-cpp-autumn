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
		for (int i = 2; i <= _vertexes; ++i)
		{
			int num = 0;
			std::cin >> num;
			_matrix[num - 1][i - 1] = 1;
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

	int* TrackTo1(int num1)
	{
		int num1_ = num1;
		int* TrackTo1 = new int [_vertexes] {0};
		while (true)
		{
			int k = 1;
			TrackTo1[0] = num1;
			for (int i = 0; i < _vertexes; ++i)
			{
				if (_matrix[num1][i] == 1)
				{
					TrackTo1[k] = i;
					k++;
					*&num1_ = i;
					if (num1 == 1)
					{
						break;
					}
				}
			}
		}
		return TrackTo1;
	}

	int SearchNearestRelative(int num1, int num2)
	{
		bool flag = true;
		int i = _vertexes - 1;
		int NearestRelative = 1;
		while (flag == true)
		{
			if (TrackTo1(num1)[i - 1] == TrackTo1(num2)[i - 1])
			{
				NearestRelative = TrackTo1(num1)[i - 1];
				--i;
			}
			else
			{
				break;
			}
		}
		return NearestRelative;
	}

};

int main(int argc, char* argv[])
{
	int vertexes = 0;
	std::cin >> vertexes;
	CGraph graph(vertexes);

	int num1 = 0;
	int num2 = 0;

	std::cin >> num1;
	std::cin >> num2;
	graph.MakeMatrix();

	std::cout << graph.TrackTo1(num1);
	graph.SearchNearestRelative(num1, num2);

	return EXIT_SUCCESS;
}