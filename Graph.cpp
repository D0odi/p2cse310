#include "Graph.h"
#include "Edge.h"
#include <iostream>

Graph::Graph(int numOfVertices, int numOfEdges)
{
    this->matrix = new int *[numOfVertices];
    for (int i = 0; i < numOfVertices; ++i)
    {
        this->matrix[i] = new int[numOfVertices];
        for (int j = 0; j < numOfVertices; j++)
        {
            matrix[i][j] = 0;
        }
    }
    this->numOfVertices = numOfVertices;
    this->numOfEdges = numOfEdges;
    vertices = new Vertex[numOfVertices];
    edges = new Edge *[numOfEdges];

    for (int i = 0; i < numOfVertices; i++)
    {
        vertices[i].setIndex(i + 1);
        vertices[i].setDegree(0);
    }

    for (int i = 0; i < numOfEdges; i++)
    {
        edges[i] = nullptr;
    }
}

void Graph::addEdge(Edge *newEdge)
{

    int start = newEdge->getStart() - 1;
    int end = newEdge->getEnd() - 1;

    matrix[start][end] = 1;
    matrix[end][start] = 1;
    vertices[start].setDegree(vertices[start].getDegree() + 1);
    vertices[end].setDegree(vertices[end].getDegree() + 1);

    std::cout << "Added edge "
              << ": (" << start + 1 << ", " << end + 1 << std::endl;
}

void Graph::printGraph()
{
    std::cout << "The adjacency matrix of G:" << std::endl;
    for (int i = 0; i < numOfVertices; ++i)
    {
        for (int j = 0; j < numOfVertices; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::dijkstraShortestPaths(int source)
{
    // Initialize distances to all vertices as infinite
    int *distances = new int[numOfVertices];
    for (int i = 0; i < numOfVertices; ++i)
    {
        distances[i] = INT_MAX;
    }

    // Create an array to track if a vertex is processed
    bool *processed = new bool[numOfVertices];
    for (int i = 0; i < numOfVertices; ++i)
    {
        processed[i] = false;
    }

    // Set the distance of the source vertex to itself as 0
    distances[source - 1] = 0;

    // Loop to find shortest paths for all vertices
    for (int count = 0; count < numOfVertices - 1; ++count)
    {
        // Find the vertex with the minimum distance value
        int minDistance = INT_MAX, minIndex;
        for (int v = 0; v < numOfVertices; ++v)
        {
            if (!processed[v] && distances[v] <= minDistance)
            {
                minDistance = distances[v];
                minIndex = v;
            }
        }

        // Mark the selected vertex as processed
        processed[minIndex] = true;

        // Update the distance value of the adjacent vertices of the selected vertex
        for (int v = 0; v < numOfVertices; ++v)
        {
            if (!processed[v] && matrix[minIndex][v] && distances[minIndex] != INT_MAX && distances[minIndex] + matrix[minIndex][v] < distances[v])
            {
                distances[v] = distances[minIndex] + matrix[minIndex][v];
            }
        }
    }

    // Print the distances to all vertices
    std::cout << "Single source shortest path lengths from node " << source << std::endl;
    for (int i = 0; i < numOfVertices; ++i)
    {
        if (distances[i] != INT_MAX)
        {
            std::cout << i + 1 << ": " << distances[i] << std::endl;
        }
        else
        {
            std::cout << i + 1 << ": INF" << std::endl;
        }
    }

    // Cleanup dynamically allocated memory
    delete[] distances;
    delete[] processed;
}

void Graph::printOddDegreeVertices()
{
    std::cout << "The odd degree vertices in G:" << std::endl;
    std::cout << "O = { ";
    for (int i = 0; i < numOfVertices; ++i)
    {
        if (vertices[i].getDegree() % 2 == 1)
        {
            std::cout << vertices[i].getIndex() << " ";
        }
    }
    std::cout << "}" << std::endl;
}