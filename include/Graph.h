#include <vector>

class Graph{
private:
    struct edge{
        int dest;
        int weight;

        edge(){
            dest = 0;
            weight = 0;
        }
    };
    int V;
    std::vector<std::vector<struct edge> > adj;
protected:

public:
    Graph(int V);
    ~Graph(){}

    bool add_edge(int ori, int dest, int weight);
    bool print_edges();

};
