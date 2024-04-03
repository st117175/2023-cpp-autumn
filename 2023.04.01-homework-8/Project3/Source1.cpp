#include "Header.h"


CGraph::CGraph()
	: _vertexes(0), _edges(0), _matrix(nullptr), _color_vertexes(nullptr) {}

CGraph::CGraph(int vertexes, int edges)
	: _vertexes(vertexes), _edges(edges), _matrix(nullptr), _color_vertexes(nullptr)
{
	initMatrix();
	init_color_vertexes();
}
CGraph::~CGraph()
{
	delete[] _matrix;
	delete[] _color_vertexes;
	delete[] DegVertex();
}

void CGraph::setVertexes(int vertexes) { _vertexes = vertexes; }
int CGraph::getVertexes() { return _vertexes; }

void CGraph::setEdges(int edges) { _edges = edges; }
int CGraph::getEdges() { return _edges; }

void CGraph::initMatrix()
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
void CGraph::init_color_vertexes()
{
	if (_vertexes == 0)
	{
		return;
	}
	_color_vertexes = new int[_vertexes];
	for (int i = 0; i < _vertexes; ++i)
	{
		_color_vertexes[i] = 0;
	}
}

//for task 2
void CGraph::MakeMatrix()
{
	for (int i = 0; i < _edges; ++i)
	{
		int str = 0;
		int stlb = 0;
		std::cin >> str;
		std::cin >> stlb;
		_matrix[str - 1][stlb - 1] = 1;
		_matrix[stlb - 1][str - 1] = 1;
	}
}

//for task 1
int CGraph::Count_edges()
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

void CGraph::PrintMatrix()
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

int* CGraph::DegVertex()
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

void CGraph::print_DegVertex()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		std::cout << DegVertex()[i] << " ";
	}
	std::cout << std::endl;
}

void CGraph::ReadMatrix()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cin >> _matrix[i][j];
		}
	}
}

void CGraph::ReadColorVertex()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		std::cin >> _color_vertexes[i];
	}
}

void CGraph::PrintColorVertex()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		std::cout << _color_vertexes[i];
	}
}

int CGraph::CountBadRoad()
{
	int CountBadRoad = 0;
	for (int i = 1; i < _vertexes; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if ((_matrix[i][j] == 1) && (_color_vertexes[i] != _color_vertexes[j]))
			{
				CountBadRoad++;
			}
		}
	}
	return CountBadRoad;
}