#include "Graph.h"
#include <exception>
#include <iostream>

/*
    option list
    0 - print

*/


bool Graph::dfs_visit(int v, bool visited[], enum dfs_option option, unsigned int lvl)
{
    try{
        visited[v] = true;
        switch(option){
                case print:
                    for(unsigned int i = 0; i < lvl; i++) std::cout<<"  ";
                    std::cout<<"["<<v<<"]"<<std::endl;
                break;

                default:
                break;
        }

        for (unsigned int i = 0; i < this->adj[v].size(); i++)
        {
            if(!visited[adj[v][i].dest])
                dfs_visit(adj[v][i].dest, visited, option, lvl+1);
        }
    }
    catch(std::exception &e){
        std::cout<<"Error in dfs_visit"<<std::endl;
        return false;
    }
    return true;
}

bool Graph::dfs(int v, enum dfs_option option)
{
    try{
        bool visited[this->V] = {};
        dfs_visit(v, visited, option, 0);
    } catch(std::exception &e){
        std::cout<<"Error in DFS"<<std::endl;
        return false;
    }
    return true;
}

bool Graph::calc_degree_vertices()
{
    try{
        for (unsigned int i = 0; i < this->adj.size(); i++)
        {
            for (unsigned int j = 0; j < adj[i].size(); j++)
            {
                degree_of_vertices[adj[i][j].dest]++;
            }
        }
    }catch(std::exception &e){
        std::cout << "Problem in Calc Degree Vertices" << std::endl;
        return false;
    }

    return true;
}

bool Graph::print_degree_vertices()
{
    if(!calc_degree_vertices()){
        return false;
    }
    try
    {
        std::cout << "Degree of Vertices" << std::endl;
        for (unsigned int i = 0; i < degree_of_vertices.size(); i++)
        {
            std::cout << i << ": " << degree_of_vertices[i] << std::endl;
        }
    } catch(std::exception &e){
        std::cout << "Error: Print Vertices's Degree" << std::endl;
        return false;
    }
    return true;
}

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
    this->adj = std::vector<std::vector <struct edge> >(V);
    this->degree_of_vertices = std::vector<int>(V,0);
}

bool Graph::print_edges()
{
    try{
        for (unsigned int i = 0; i < this->adj.size(); i++)
        {
            std::cout << "Vertice " << i << " Edges" << std::endl;
            for (unsigned int j = 0; j < this->adj[i].size(); j++)
            {
                std::cout << "[DEST]: " << this->adj[i][j].dest << "[WEIGHT]: " << adj[i][j].weight << std::endl;
            }   
        }
    } catch(std::exception &e){
        std::cout << "Error: print_edges" << std::endl;
    }

    return true;
}
