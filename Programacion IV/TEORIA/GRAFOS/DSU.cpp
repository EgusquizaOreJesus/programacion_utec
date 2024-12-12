#include "iostream"
#include "vector"
#include "set"
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


int main(){
    //test 1
    vector<char> data = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    //  0     1    2    3    4    5    6    7
    auto *ds = new DisjoinSetArray<char>(data);//makeset
    cout<<"# sets:"<<ds->sets()<<endl;//8
    ds->Union(0, 2);
    ds->Union(5, 6);
    ds->Union(1, 6);
    ds->Union(7, 0);
    ds->Union(4, 3);
    ds->Union(4, 5);
    cout<<"# sets:"<<ds->sets()<<endl;//2
    cout << "padre: " <<ds->findParent(5) << endl;
    cout<<"isConnected(1, 4):"<<ds->isConnected(1, 4)<<endl;//1
    cout<<"isConnected(2, 4):"<<ds->isConnected(2, 4)<<endl;//0
    cout<<"isConnected(0, 6):"<<ds->isConnected(0, 6)<<endl;//0
    //test 2
    vector<char> set1 = ds->getElementsSet(4);
    sort(set1.begin(), set1.end());
    cout<<"sets[0]: "<<set1[0]<<endl;//'b'
    cout<<"sets[1]: "<<set1[1]<<endl;//'d'
    ds->Union(3, 1);
    ds->Union(2, 5);
    cout<<"# sets:"<<ds->sets()<<endl;//1
//    delete ds;
}