#include <vector>

class Graph{
private:
    int V;
    std::vector<int> *adj;
protected:

public:
    Graph(int V)
    {
        this->V = V;
        adj = new std::vector<int>(V);
    }

    ~Graph()
    {
       delete adj;
    }
};
