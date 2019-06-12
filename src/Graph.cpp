#include "Graph.h"
#include <exception>
#include <iostream>
#include <queue>

/*
    option list
    0 - print

*/

std::vector<std::vector <struct edge> >Graph::get_adj()
{
    return this->adj;
}

bool Graph::scc_visit(int v, int visited[], Graph &T, enum general_option option)
{
    if(visited[v] == white){
        if(option == g_print) std::cout <<"["<<v<<"]"<< " ";
        visited[v] = gray;
        for(unsigned int i=0; i < T.get_adj()[v].size(); i++)
        {
            scc_visit(T.get_adj()[v][i].dest, visited, T, option);
        }
        visited[v] = black;
    }
    return true;
}

bool Graph::strongly_connected_components(enum general_option option)
{
    //Kosaraju's Algorithm
    dfs(dfs_scc);

    Graph T = this->get_transpose();

    //Mark all vertices as white (not visited)
    int visited[this->V] = {};

    bool print = false;
    switch(option){
        case g_print:
            print = true;
            std::cout<<"Strongly Connected Components"<<std::endl;
        break;
        default:
        break;
    }
    while(not this->scc_stack.empty()){
        if(print) std::cout<<std::endl;
        int current = this->scc_stack.top();
        this->scc_stack.pop();
        scc_visit(current, visited, T, option);
    }
    if(print) std::cout<<std::endl;
    return true;
}

bool Graph::add_edge(int ori, struct edge new_edge)
{
    try{
        this->adj[ori].push_back(new_edge);
    }catch(std::exception &e){
        std::cout<<"Add Edge Error"<<std::endl;
        return false;
    }
    return true;
}

Graph Graph::get_transpose()
{
    Graph transpose(this->V);

    for(unsigned int i = 0; i < this->V; i++){
        for(unsigned int j = 0; j < this->adj[i].size();j++){
            int new_ori = this->adj[i][j].dest;
            struct edge new_edge(i, this->adj[i][j].weight);
            transpose.add_edge(new_ori, new_edge);
        }
    }

    return transpose;
}

bool Graph::is_connected_graph()
{
    for(unsigned int i = 0; i < this->V; i++){
        int visited[this->V] = {};
        dfs_visit(i, visited, dfs_default, 0);
        for(unsigned int j = 0;j<this->V;j++) if(visited[j] == white) return false;
    }

    return true;
}

bool Graph::bfs(int v, enum general_option option)
{
    try{
        // Mark all vertices as white (not visited).
        int visited[this->V] = {};
        std::queue <int> q;
        q.push(v);

        while(!q.empty()){
            int current = q.front();
            q.pop();
            //Mark vertice as visited
            if(visited[current] == white){
                visited[current] = gray;

                switch(option){
                    case g_print:
                        std::cout<<"["<<current<<"]"<<std::endl;
                    break;
                    default:
                    break;
                }

                for (unsigned int i = 0; i < adj[current].size(); i++)
                {
                    int dest = adj[current][i].dest;
                    q.push(dest);
                }
            }
        }

    
    }catch(std::exception &e){
        std::cout<<"BFS Error"<<std::endl;
        return false;
    }
    return true;
}

bool Graph::topological_sort(enum topological_sort_option option)
{
    if(detect_cyclic()){
        std::cout<<"Topological Sort Error: Cyclic Graph"<<std::endl;
        return false;
    }
    try{
        bool print_option = false;

        switch(option){
            case topo_print:
                print_option = true;
            break;
            default:
            break;
        }
        int visited[this->V] = {};
        for(unsigned int i = 0; i < this->V; i++){
            dfs_visit(i, visited, Graph::dfs_topological_sort, 0);
        }

        if(print_option){
            std::cout<<"Topological Sort"<<std::endl;
            while(not topological_order.empty()){
                int c_vertice = topological_order.top();
                topological_order.pop();
                std::cout << "[" << c_vertice << "]" << std::endl; 
            }
        }
    }catch(std::exception &e){
        std::cout<<"Topological Sort Error " << e.what() <<std::endl;
        return false;
    }

    return true;
}

bool Graph::detect_cyclic()
{
    dfs(Graph::dfs_cyclic);
    if(is_cyclic) return true;
    return false;
}

bool Graph::dfs_visit(int v, int visited[], enum dfs_option option, unsigned int lvl)
{
    try{
        if(not visited[v] == Graph::white){
            return false;
        }
        visited[v] = Graph::gray;
        bool detect_cyclic = false;
        bool topological_sort_option = false;
        bool scc = false;

        switch(option){
                case dfs_print:
                    for(unsigned int i = 0; i < lvl; i++) std::cout<<"  ";
                    std::cout<<"["<<v<<"]"<<std::endl;
                break;
                case dfs_cyclic:
                    if(this->is_cyclic) return true;
                    detect_cyclic = true;
                break;
                case dfs_topological_sort:
                    topological_sort_option = true;
                break;
                case dfs_scc:
                    scc = true;
                break;
                default:
                break;
        }

        for (unsigned int i = 0; i < this->adj[v].size(); i++)
        {
            dfs_visit(adj[v][i].dest, visited, option, lvl+1);
            if(detect_cyclic && visited[adj[v][i].dest] == Graph::gray){
                this->is_cyclic = true;
            }
        } 
        visited[v] = Graph::black;
        if(topological_sort_option) this->topological_order.push(v);
        if(scc) this->scc_stack.push(v);

    }
    catch(std::exception &e){
        std::cout<<"Error in dfs_visit"<<std::endl;
        return false;
    }
    return true;
}

bool Graph::dfs(enum dfs_option option)
{
    try{
        // Mark all vertice as white (not visited)
        int visited[this->V] = {};
        for(unsigned int i = 0;i < this->V; i++)
            dfs_visit(i, visited, option, 0);
    } catch(std::exception &e){
        std::cout<<"Error in DFS"<<std::endl;
        return false;
    }
    return true;
}

bool Graph::calc_degree_vertices(enum general_option option)
{
    try{
        for (unsigned int i = 0; i < this->adj.size(); i++)
        {
            for (unsigned int j = 0; j < adj[i].size(); j++)
            {
                degree_of_vertices[adj[i][j].dest]++;
            }
        }
        switch(option){
            case g_print:
                print_degree_vertices();
            break;
            default:
            break;
        }

    }catch(std::exception &e){
        std::cout << "Problem in Calc Degree Vertices" << std::endl;
        return false;
    }

    return true;
}

bool Graph::print_degree_vertices()
{
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
    this->is_cyclic = false;
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
