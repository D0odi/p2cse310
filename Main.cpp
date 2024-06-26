#include "Edge.h"
#include "Graph.h"
#include <iostream>

int main()
{

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if (!std::cin.eof())
    {
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else
    {
        std::cout << "Input not found!" << std::endl;
        return 0;
    }

    Graph *graph = new Graph(numOfVertices, numOfEdges);

    while (!std::cin.eof())
    {
        int startVertice;
        int endVertice;
        std::cin >> startVertice;
        std::cin >> endVertice;
        Edge *newEdge = new Edge(startVertice, endVertice);
        graph->addEdge(newEdge);
    }

    graph->printGraph();
    int *oddDegreeVertices = graph->getOddDegreeVertices();
    for (int i = 0; i < numOfVertices; i++)
    {
        if (oddDegreeVertices[i] != -1)
        {
            graph->dijkstraShortestPaths(oddDegreeVertices[i]);
        }
        else
        {
            break;
        }
    }

    return 0;
}