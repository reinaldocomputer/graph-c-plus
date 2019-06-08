#pragma once
#include "Graph.h"
#include <exception>
#include <iostream>

bool Graph::add_edge(int ori, int dest, int weight)
{
    struct edge new_edge;
    try{
        new_edge.dest = dest;
        new_edge.weight = weight;
        adj[ori].push_back(new_edge);
    } catch (std::exception &e){
        std::cout<<"We got an error when we tried to add a new edge."<<std::endl;
        return false;
    }

    return true;
}

Graph::Graph(int V)
{
    this->V = V;
    adj = std::vector<std::vector <struct edge> >(V);
}

bool Graph::print_edges()
{
    try{
        for (int i = 0; i < this->adj.size(); i++)
        {
            std::cout << "Vertice " << i << " Edges" << std::endl;
            for (int j = 0; j < this->adj[i].size(); j++)
            {
                std::cout << "[DEST]: " << this->adj[i][j].dest << "[WEIGHT]: " << adj[i][j].weight << std::endl;
            }   
        }
    } catch(std::exception &e){
        std::cout << "Error: print_edges" << std::endl;
    }

    return true;
}
