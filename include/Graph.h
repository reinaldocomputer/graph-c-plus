#include <vector>

class Graph{
    public:
    enum dfs_option{
        print = 0,
        cyclic,
        fin,
    };

    enum vertice_color{
        white,
        gray,
        black,
    };    

    Graph(int V);
    ~Graph(){}

    bool add_edge(int ori, int dest, int weight);
    bool print_edges();
    bool print_degree_vertices();
    bool dfs(int v, enum dfs_option option);
    bool is_cyclic;
    bool detect_cyclic();

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
    std::vector <int> degree_of_vertices;
    std::vector<std::vector<struct edge> > adj;

    bool calc_degree_vertices();
    bool dfs_visit(int v, int visited[], enum dfs_option option, unsigned int lvl);
};
