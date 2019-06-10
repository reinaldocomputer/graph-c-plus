#include <vector>
#include <stack>

class Graph{
    public:
    enum general_option{
        g_print = 0,
    };

    enum dfs_option{
        dfs_print = 0,
        dfs_cyclic,
        dfs_topological_sort,
    };

    enum topological_sort_option{
        topo_print = 0,
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
    bool dfs(int v, enum dfs_option option);
    // bool bfs(int v, enum general_option option);
    bool is_cyclic;
    bool detect_cyclic();
    bool topological_sort(enum topological_sort_option option);
    bool calc_degree_vertices(enum general_option option);

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
    std::stack<int> topological_order;
    bool dfs_visit(int v, int visited[], enum dfs_option option, unsigned int lvl);
    bool print_degree_vertices();
};
