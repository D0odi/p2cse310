#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"

class Graph
{
private:
    int numOfVertices;
    int numOfEdges;
    Vertex *vertices;
    Edge **edges;
    int **matrix;

public:
    Graph();
    Graph(int numOfVertices, int numOfEdges);
    void addEdge(Edge *edge);
    void printGraph();
    void printOddDegreeVertices();
    void dijkstraShortestPaths(int source);
};

#endif