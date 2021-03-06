#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
#include "Queue.h"

struct vertex;

struct edge {
    vertex *neighbor;
    int weight;
    edge(vertex* verty, int weightIn) {
        neighbor = verty;
        weight = weightIn;
    }
};

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    vertex *parent;
    bool visited;
    std::vector<adjVertex> adj;
    Queue *graphQueue = new Queue(100);
    std::vector<edge*> links;
    int distance = INT_MAX;

};


class Graph
{
    public:
        Graph(){};
        ~Graph(){};  
        void addEdge(std::string v1, std::string v2, int weight);
        void addVertex(std::string name);
        void isAdjacent(std::string v1, std::string v2);
        void displayEdges();
        void displayVerticesNearMe(std::string name, int miles);
        void displayVertices();
        vertex *findVertex(std::string name);
        bool enqueueIndividuals(vertex *vertToAdd,person individual);
        void printQueueFromGraph(vertex *vert);
        bool vertexExists(string address);
        void printShortestPath(string start1, string end1);

    protected:
    private:
        Queue *graphQueue;
        std::vector<vertex> vertices;
        bool allVisitedCheck();
        vertex* getMinNode();
        bool allVerticesVisited();



        
};

#endif // GRAPH_H
