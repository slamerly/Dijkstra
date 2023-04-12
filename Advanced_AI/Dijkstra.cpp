#include "Dijkstra.h"
#include <iostream>

Dijkstra::Dijkstra(vector<vector<int>>* graphP, int debP)
{
    graph = graphP;
    startNode = debP;
}

Dijkstra::~Dijkstra()
{
}

void Dijkstra::setGraph(vector<vector<int>>* graphP)
{
    graph = graphP;
}

void Dijkstra::setStartNode(int startNodeP)
{
    startNode = startNodeP;
}

void Dijkstra::Research()
{
    initialize(graph, startNode);

    for (size_t i = 0; i < graph->size(); i++)
    {
        restNodes.push_back(i);
    }

    while (!restNodes.empty())
    {
        int node1 = findMin(restNodes);
        if (node1 != -1)
        {
            auto iter = find(begin(restNodes), end(restNodes), node1);
            restNodes.erase(iter);
            //cout << restNodes.size() << endl;
            for (size_t i = 0; i < restNodes.size(); i++)
            {
                updateDistance(node1, restNodes.at(i));
            }
        }
    }

    //result
    
    cout << "RESULT - Origin(" << startNode << ")" << endl;
    cout << "Predecesor:    Distance:" << endl;
    for (size_t i = 0; i < predecessor.size(); i++)
    {
        cout << i << ": " << predecessor.at(i) << "               " << distance.at(i) << endl;
    }
    cout << endl;
    
}

void Dijkstra::Destination(int dest)
{
    cout << "---- DIJKSTRA ----" << endl;
    cout << "ORIGIN(" << startNode << ") - DESTINATION(" << dest << ")" << endl;
    cout << "Cost: " << distance.at(dest) << endl;

    cout << "Road: " << dest << " <- ";
    int cpt = dest;
    while ( cpt != startNode )
    {
        cout << predecessor.at(cpt);
        cpt = predecessor.at(cpt);
        if (cpt != startNode)
            cout << " <- ";
    }
}

void Dijkstra::initialize(vector<vector<int>>* mat, int deb)
{
    vector<int> line;
    for (size_t i = 0; i < mat->size(); i++)
    {
        if (i == deb)
            distance.push_back(0);
        else
            distance.push_back(1000000);
        //cout << distance.at(i) << ", ";

        predecessor.push_back(i);
    }
    //cout << endl;
}

int Dijkstra::findMin(vector<int> mat)
{
    int min = 1000000;
    int node = -1;
    for (size_t i = 0; i < mat.size(); i++)
    {
        if (distance[mat[i]] <= min)
        {
            min = distance[mat[i]];
            node = mat[i];
            break;
        }
    }
    //cout << "Find min : " << node << endl;
    return node;
}

void Dijkstra::updateDistance(int node1, int node2)
{
    if (distance.at(node2) > distance.at(node1) + graph->at(node1).at(node1) + graph->at(node1).at(node2))
    {
        distance[node2] = distance.at(node1) + (graph->at(node1).at(node1) + graph->at(node1).at(node2));
        predecessor[node2] = node1;
        //cout << node2 << ": dist: " << distance.at(node2) << ", predecesor: " << predecesor.at(node2) << endl;
    }
}