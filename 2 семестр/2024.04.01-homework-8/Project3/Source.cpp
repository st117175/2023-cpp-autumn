#include "Header.h"

int main(int argc, char* argv[])
{
	int vertexes = 0;

	std::cin >> vertexes;

	CGraph graph(vertexes, 0);
	graph.ReadMatrix();
	graph.ReadColorVertex();
	std::cout << graph.CountBadRoad();

	return EXIT_SUCCESS;
}