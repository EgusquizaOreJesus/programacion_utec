#include <utility>

#include "iostream"
#include "vector"
#include "set"
using namespace std;

using namespace std;

struct Edge
{
    char init;
    char end;
    int weight;
};


using namespace std;

template<typename T>
class DisjoinSet{
    int* rank;
    int* parent;
public:
    ~DisjoinSet()=default;
    virtual void MakeSet(T x) = 0;
    virtual int Find(T x) = 0;

    virtual void Union(T x, T y) = 0;
    virtual bool isConnected(T x, T y) = 0;

};

template<typename T>
class DisjoinSetTree: public DisjoinSet<T>
{




};

template<typename T>
class DisjoinSetArray: public DisjoinSet<T>
{
public:
    vector<T> data;
    T* rank;
    T* parent;

public:
    DisjoinSetArray(vector<T> data_){
        int i = 0;
        rank = new T[data_.size()];
        parent = new T[data_.size()];
        for(auto v: data_){
            rank[i] = 0;
            parent[i] = i;
            data.push_back(v);
            i++;
        }
    }
    void MakeSet(T x) override{
        parent[x] = x;
        rank[x] = 0;
    }
    int findParent(int x){
        if (x == parent[x]){
            return x;
        }
        else return parent[x] = findParent(parent[x]);
    }
    bool sameParent(T x, T y){
        T parent1 = findParent(x);
        T parent2 = findParent(y);
        return parent1 == parent2;
    }
    int getRank(T x){
        T parent_ = findParent(x);
        return rank[parent_];
    }
    int Find(T x) override{
        return 0;
    }

    void Union(T x, T y) override{
        T parent1 = findParent(x);
        T parent2 = findParent(y);
        if (rank[parent1] < rank[parent2]){
            parent[parent1] = parent[parent2];
        }
        else if (rank[parent1] > rank[parent2]){
            parent[parent2] = parent[parent1];
        }
        else{
            parent[parent2] = parent[parent1];
            rank[parent1]++;
        }
    }
    void Union(int x, int y){
        T parent1 = findParent(x);
        T parent2 = findParent(y);
        if (rank[parent1] < rank[parent2]){
            parent[parent1] = parent[parent2];
        }
        else if (rank[parent1] > rank[parent2]){
            parent[parent2] = parent[parent1];
        }
        else{
            parent[parent2] = parent[parent1];
            rank[parent1]++;
        }
    }
    bool isConnected(T x, T y) override{
        T parent1 = findParent(x);
        T parent2 = findParent(y);
        return parent1 == parent2;
    }
    int sets(){
        set<T> padres;
        for (int i = 0; i < data.size(); ++i) {
            padres.insert(findParent(i));
        }
        return padres.size();
    }

    vector<T> getElementsSet(int index){
        vector<T> elements;
        for (int i = 0; i < data.size(); ++i) {
            if (findParent(index) == findParent(i)){
                elements.push_back(data[i]);
            }
        }
        return elements;
    }
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}
vector<Edge> kruskal(vector<char> vertices, vector<Edge> edges){
    vector<Edge> result;
    DisjoinSetArray<char> ds(std::move(vertices));

    sort(edges.begin(), edges.end(), compareEdges);

    for (auto edge : edges) {
        auto root1 = ds.findParent(int(edge.init - 'A'));
        auto root2 = ds.findParent(int(edge.end - 'A'));
        if (root1 != root2) {
            result.push_back(edge);
            ds.Union(root1, root2);
        }
    }

    return result;
}
ostream& operator<<(ostream& os, Edge arista){
    os << arista.init << ", " << arista.end << ", " << arista.weight;
    return os;
}

int main(){
    vector<char> vertices = {'A','B','C','D','E','F','G','H'};
    vector<Edge> aristas =
            {{'A', 'B', 1},
             {'A', 'C', 3},
             {'A', 'D', 5},
             {'B', 'D', 6},
             {'C', 'D', 4},
             {'C', 'E', 7},
             {'D', 'F', 2},
             {'E', 'F', 9},
             {'E', 'G', 4},
             {'F', 'H', 3},
             {'G', 'H', 8},
            };
    vector<Edge> result = kruskal(vertices, aristas);

    for(Edge edge : result){
        cout<<edge<<endl;
    }
    //'A', 'B', 1
    //'D', 'F', 2
    //'A', 'C', 3
    //'F', 'H', 3
    //'C', 'D', 4
    //'E', 'G', 4
    //'C', 'E', 7
}
