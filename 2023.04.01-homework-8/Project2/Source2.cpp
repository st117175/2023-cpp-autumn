#include "GRAPH.h"

int main(int argc, char* argv[])
{
	int vertexes = 0;
	int edges = 0;
	std::cin >> vertexes;
	std::cin >> edges;
	CGraph graph(vertexes, edges);
	graph.MakeMatrix();
	graph.print_DegVertex();
	//graph.PrintMatrix();

	return EXIT_SUCCESS;
}