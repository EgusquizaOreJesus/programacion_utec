#include "forward_list.h"
#include "functional"
const float maxFillFactor = 0.4;
const int maxColision = 3;
template<typename TK, typename TV>
class ChainHash
{
private:
    ForwardList<std::pair<TK, TV>> * array;
    int capacity;
    int size;
    hash<TK> hasher;
public:
    ChainHash(int cap = 13){
        this->capacity = cap;
        this->size = 0;
        this->array = new ForwardList<std::pair<TK, TV>>[this->capacity];
    }
    ~ChainHash(){
        //TODO
    }
    float fillFactor(){
        return size / (capacity * maxColision * 1.0);
    }
    void insert(pair<TK, TV> dato){
        if(fillFactor() >= maxFillFactor) rehashing();
        size_t hashcode = hasher(dato.first);
        int index =  hashcode % capacity;

        for(auto it = this->begin(index);it != this->end(index);++it){
            if ((*it).first == dato.first){
                (*it).second = dato.second;
                return;
            }
        }
        array[index].push_front(dato);
        if (bucket_size(index)>3){
            rehashing();
        }
        size++;
    }

    void remove(TK key){
        size_t hashcode = hasher(key);
        int index = hashcode%capacity;
        int pos = 1;
        for(auto it = this->begin(index);it != this->end(index);++it){
            if ((*it).first == key){
                break;
            }
            pos++;
        }
        array[index].remove(pos);
    }
    TV& operator[](TK key){
        size_t hashcode = hasher(key);
        int index = hashcode%capacity;
        auto it = this->begin(index);
        for(;it != this->end(index);++it){
            if ((*it).first == key){
                return (*it).second;
            }
        }
        pair<TK,TV> a = {key,0};
        insert(a);
        return this->operator[](key);
    }
    int bucket_count(){
        return capacity;
    }

    int bucket_size(int i){
        return array[i].size();
    }
    typename ForwardList<std::pair<TK, TV>>::iterator begin(int i){
//        if (*(array[i].begin()) )
        return array[i].begin();
    }
    typename ForwardList<std::pair<TK, TV>>::iterator end(int i){
        return array[i].end();
    }
    void display(){
        for(int i=0;i<(int)this->bucket_count();i++){
            cout<<"bucket "<<i<<" contains "<<this->bucket_size(i)<<": ";
            for(auto it = this->begin(i); it != this->end(i); ++it)
                cout<<" ("<<(*it).first<<","<<(*it).second<<") ";
            cout<<endl;
        }
        cout << endl;
    }
    ForwardList<TV> sort(){
        ForwardList<TV> temp;
        for(int i=0;i<(int)this->bucket_count();i++){
            for(auto it = this->begin(i); it != this->end(i); ++it){
                temp.push_front((*it).second);
            }
        }
        temp.sort();
        return temp;
    }
private:
    void rehashing(){
        cout << "REHASHING" <<endl;
        int new_size = bucket_count() * 2;
        auto new_table = new ForwardList<std::pair<TK, TV>>[new_size];
        for (int i = 0; i < bucket_count(); i++) {
            for (const auto& it : array[i]) {
                size_t index = hasher(it.first);
                index = index%new_size;
                new_table[index].push_back(it);
            }
        }
        // Actualizar el tamaño y la tabla hash
        capacity = new_size;
        delete[] array;
        array = new_table;
    }

};
