#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Graph.h"

enum operation{
    op_none = 0,
    op_test = 1,
};
/*
    Menu option
        -i | input file
*/

void processing(char *file_name, enum operation op)
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
        switch(op){
            case op_test:
                mygraph.print_edges();
                mygraph.calc_degree_vertices(Graph::g_print);
                mygraph.bfs(0, Graph::g_print);
                if(mygraph.detect_cyclic()) std::cout<<"Cycle Detected"<<std::endl;
                mygraph.topological_sort(Graph::topo_print);
                mygraph.strongly_connected_components(Graph::g_print);
                mygraph.minimum_spanning_tree(Graph::mst_prim, Graph::g_print);
                mygraph.minimum_spanning_tree(Graph::mst_kruskal, Graph::g_print);
             break;
             case op_none:
             default:
             break;
        }
    }
    fclose(pFile);
}

int main(int argc, char *argv[])
{
    if(strcmp(argv[1],"-i") == 0){
        for (int i = 2; i < argc; i++)
        {
            processing(argv[i], op_none);
        }        
    }
    else if(strcmp(argv[1],"-it") == 0){
        for (int i = 2; i < argc; i++)
        {
            processing(argv[i], op_test);
        }        
    }    
    else if(strcmp(argv[1],"-h") == 0){
        std::cout << "-i | Input File" << std::endl;
        std::cout << "-it | Input File and Test" << std::endl;
    }
    else std::cout << "Choose a valid option" << std::endl;


}
