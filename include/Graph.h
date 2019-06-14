#include <vector>
#include <stack>

struct edge{
    int dest;
    int weight;

    edge(){
        dest = 0;
        weight = 0;
    }
    edge(int d, int w){
        dest = d;
        weight = w;
    }

    bool operator <=(struct edge b) const{
        if(weight < b.weight) return true;
        return false;
    }
};

class Graph{
    public:
    enum general_option{
        g_print = 0,
    };

    enum dfs_option{
        dfs_print = 0,
        dfs_cyclic,
        dfs_topological_sort,
        dfs_scc,
        dfs_default,
    };

    enum mst_algorithm{
        mst_prim,
        mst_kruskal,
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
    bool add_edge(int ori, struct edge new_edge);
    bool print_edges();
    bool dfs(enum dfs_option option);
    bool bfs(int v, enum general_option option);
    bool is_cyclic;
    bool detect_cyclic();
    bool topological_sort(enum topological_sort_option option);
    bool calc_degree_vertices(enum general_option option);
    bool is_connected_graph();
    bool strongly_connected_components(enum general_option option);
    std::vector<std::vector <struct edge > > get_adj();
    Graph get_transpose();
    std::vector<int> minimum_spanning_tree(mst_algorithm algorithm, general_option option);
private:
    unsigned int V;
    std::vector <int> degree_of_vertices;
    std::vector<std::vector<struct edge> > adj;
    std::stack<int> topological_order;
    std::stack<int> scc_stack;  
    bool dfs_visit(int v, int visited[], enum dfs_option option, unsigned int lvl);
    bool print_degree_vertices();
    bool scc_visit(int v, int visited[], Graph &T, enum general_option option);
};
