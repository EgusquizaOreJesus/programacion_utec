#ifndef NODE_H
#define NODE_H

using namespace std;

template <typename TK>
struct Node {
  // array de keys
  TK* keys;
  // array de punteros a hijos
  Node** children;
  // cantidad de keys
  int count;
  // indicador de nodo hoja
  bool leaf;

  Node() : keys(nullptr), children(nullptr), count(0), leaf(true) {}
  Node(int M, bool _leaf = true) {
    this->keys = new TK[M-1];
    this->children = new Node<TK>*[M];
    for(int i=0; i < M; i++){
      this->children[i] = nullptr;
    }
    this->count = 0;
    this->leaf = _leaf;
  }

  int insert(TK value) {
    int i = this->count - 1;
    for(; i >= 0; i--){
      if(value > this->keys[i]){
        break;
      }else{
        this->keys[i+1] = this->keys[i];
      }
    }
    this->keys[i + 1] = value;
    (this->count)++;
    return i+1;
  }

  int insert(Node<TK>* node, int M, Node<TK>* cmp) {
    int i = M - 1;
    for(; i >= 0; i--){
      if(children[i] == cmp){
        break;
      }else{
        this->children[i+1] = this->children[i];
      }
    }
    this->children[i + 1] = node;
    return i+1;
  }

  void print(){
    for(int i = 0; i < this->count; i++){
      cout<<this->keys[i]<<" ";
    }
    cout<<endl;
  }

  void killSelf() {
    for(int i = 0; i<= this->count; i++){
      if(this->children[i] != nullptr){
        this->children[i]->killSelf();
      }
    }
    if(this->keys != nullptr) delete[] this->keys;
    if(this->children[0] == nullptr) delete[] this->children;
    delete this;
  }

  void display(const string& sep = ",") {
    int i;
    for(i = 0; i < count; i++){
      if(children[i] != nullptr){
          children[i]->display();
      }
      cout<<keys[i]<<sep;
    }
    if(children[i] != nullptr){
      children[i]->display();
    }
  }

  void toString(string& result, const string& sep = ",") {
    int i;
    for(i = 0; i < count; i++){
      if(children[i] != nullptr){
          children[i]->toString(result, sep);
      }
      result += std::to_string(keys[i]) + sep;
    }
    if(children[i] != nullptr){
      children[i]->toString(result, sep);
    }
  }

  void display_keys(const string& sep = ",") {
    int i;
    for(i = 0; i < count; i++){
        cout<<keys[i]<<sep;
    } 
  }


  void remove(int idx){
    for (;idx<count-1; idx++){
      this->keys[idx] = this->keys[idx+1];
    }
    this->count = this->count-1;
  }

  void remove(int idx, int M){
    for (;idx<=count; idx++){
      this->children[idx] = this->children[idx+1];
    }
    for (int i = this->count + 1; i < M; i++){
      this->children[i] = nullptr;
    }
  }
};

#endif