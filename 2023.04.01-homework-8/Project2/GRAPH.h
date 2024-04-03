#pragma once
#include <iostream>

class CGraph
{
private:
	int _vertexes;
	int _edges;
	int** _matrix;
	int* _color_vertexes;
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	
	void setVertexes(int vertexes);
	int getVertexes();

	void setEdges(int edges);
	int getEdges();

	void ReadMatrix();
	void initMatrix();
	void MakeMatrix();
	void PrintMatrix();

	int Count_edges();
	
	int* DegVertex();
	void print_DegVertex();

	int CountBadRoad();
	void init_color_vertexes();
	void PrintColorVertex();
	void ReadColorVertex();

};
