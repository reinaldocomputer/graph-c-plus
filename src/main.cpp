#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Graph.h"

/*
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

    char aux_input[100];
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
        mygraph.print_edges();
        mygraph.print_degree_vertices();
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
