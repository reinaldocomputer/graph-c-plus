#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Graph.h"

/*
    Menu option
        -i | input file
*/

void processing(char *file_name)
{
    FILE *pFile;
    pFile = fopen(file_name,"r+");
    if(pFile == NULL){
        std::cout << "Error:" << file_name << " doesn't exist" << std::endl;
        return ;
    }

    int V, A, ori, dest, weight;
    std::cout << "Processing:" << file_name << std::endl;
    while(fscanf(pFile, " %d", &V) !=  EOF){
        Graph mygraph(V);
        fscanf(pFile, " %d", &A);
        for (int i = 0; i < A; i++)
        {
            fscanf(pFile, " %d", &ori);
            fscanf(pFile, " %d", &dest);
            fscanf(pFile, " %d", &weight);
            
            mygraph.add_edge(ori, dest, weight);
        }
        // mygraph.print_edges();
        // mygraph.dfs(0,Graph::dfs_print);
        //if(mygraph.detect_cyclic()) std::cout<<"Cycle Detected"<<std::endl;
        // mygraph.topological_sort(Graph::topo_print);
        // mygraph.calc_degree_vertices(Graph::g_print);
        // mygraph.bfs(0, Graph::g_print);
        // std::cout << "Connected Graph"<<std::endl;
        // if(mygraph.is_connected_graph()) std::cout<<"is connected"<<std::endl;
        // else std::cout<<"isn't connected"<<std::endl;
        // mygraph.get_transpose().print_edges();
        // mygraph.strongly_connected_components(Graph::g_print);
        mygraph.minimum_spanning_tree(Graph::mst_prim, Graph::g_print);
    }
    fclose(pFile);
}

int main(int argc, char *argv[])
{
    if(strcmp(argv[1],"-i") == 0){
        for (int i = 2; i < argc; i++)
        {
            processing(argv[i]);
        }        
    }
    else if(strcmp(argv[1],"-h") == 0)
        std::cout << "-i | Input File" << std::endl;
    else std::cout << "Choose a valid option" << std::endl;


}
