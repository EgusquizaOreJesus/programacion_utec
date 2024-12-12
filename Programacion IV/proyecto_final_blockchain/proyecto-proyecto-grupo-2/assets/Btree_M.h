#ifndef BTree_H
#define BTree_H
#include <iostream>
#include <stack>
#include <cmath>
#include <queue>
#include "node_M.h"

using namespace std;

template<typename TK>
struct SplitResult_M
{
  TK key;
  Node_M<TK> *right_tree;
  SplitResult_M(){ right_tree = nullptr;}
  SplitResult_M(TK _k, Node_M<TK> *_node) : key(_k), right_tree(_node){}
};

template <typename TK>
class BTree_M {
 private:
  Node_M<TK>* root;
  int M;  // Degree or order of the tree
  int n; // Total number of elements in the tree.



 public:
  explicit BTree_M(int M) : root(nullptr), M(M), n(0) {}

  bool search(TK key){return search(this->root, key);};// Indicates whether an element is found or not
  void insert(TK key);// Insert an element
  void remove(TK key);// Remove an element.
  int height(){return height(this->root);};// Height of the tree. Consider height -1 for an empty tree.
  string toString(const string& sep){return toString(this->root, sep);};  // In-order traversal.

  TK minKey(){return minKey(this->root);};  // Minimum value of the key in the tree.
  TK maxKey(){return maxKey(this->root);};  // Maximum value of the key in the tree.
  void clear(){this->root->killSelf(); this->root = nullptr; n = 0;}; // Remove all elements from the tree.
  int size(){return n;}; // Returns the total number of inserted elements.
  ~BTree_M(){this->root->killSelf();};     // Free memory.

    vector<TK> rango_search(TK a , TK b){
        return root->buscar_range(a,b);
    }
  private:

  bool search(Node_M<TK>*& node, TK key);

  SplitResult_M<TK>* insert(Node_M<TK>* &node, TK key);
  void relocate(Node_M<TK>* &node, TK key, Node_M<TK>* key_right_tree = nullptr);
  Node_M<TK> *generate_right_node(Node_M<TK> *&node, int from);
  SplitResult_M<TK> *split_even(Node_M<TK> *&node, TK key, Node_M<TK> *key_right_tree = nullptr);
  SplitResult_M<TK> *split_odd(Node_M<TK> *&node, TK key, Node_M<TK> *key_right_tree = nullptr);

  void remove(Node_M<TK>* child, Node_M<TK>* parent, TK key);
  Node_M<TK>* successor(Node_M<TK>* node, int idx);

    [[maybe_unused]] Node_M<TK>* predecessor(Node_M<TK>* node, int idx);
    [[maybe_unused]] Node_M<TK>* minNode(Node_M<TK>* node);
    [[maybe_unused]] Node_M<TK>* maxNode(Node_M<TK>* node);

  int height(Node_M<TK>* node);
  string toString(Node_M<TK>* node, const string& sep);

  TK minKey(Node_M<TK>* node);
  TK maxKey(Node_M<TK>* node);


};

template<typename TK>
Node_M<TK> *BTree_M<TK>::maxNode(Node_M<TK> *node) {
    return nullptr;
}

template<typename TK>
bool BTree_M<TK>::search(Node_M<TK>*& node, TK key){
  if(node == nullptr){return false;}

  for(int i = 0; i < node->count; i++){
      if(node->keys[i] == key){
          return true;
      } else{
          if(key < node->keys[i]){
              return search(node->children[i], key);
          }
          if(i+1 == node->count){
              return search(node->children[i+1], key);
          }
      }
  }
  return false;
}

template<typename TK>
void BTree_M<TK>::remove(TK key){
  if(root != nullptr){
	remove(root, root, key);
	}
  n--;
}

template<typename TK>
void BTree_M<TK>::remove(Node_M<TK>* child_node, Node_M<TK>* parent, TK key){
  int i = 0;
	bool found = false;
	for(; i < child_node->count;i++){
		if(key == child_node->keys[i]){
			found = true;
			break;
		}
	}
    // *Not found and it is a leaf node.
	if (!found & child_node->leaf){
    return;
	}
    // *Not found and it is an internal node.
	else if(!found & !child_node->leaf){
		int idx = 0;
		for(; idx<child_node->count; idx++){
			if(key < child_node->keys[idx]){
				remove(child_node->children[idx], child_node, key);
				break;
			}
			else if (idx+1 == child_node->count){
				remove(child_node->children[idx+1], child_node, key);
				break;
			}
		}
	}
    // *Found and it is a leaf node.
	else if (found & child_node->leaf){
		child_node->remove(i);
	}
    // *Found and it is an internal node.
	else if (found & !child_node->leaf){
		Node_M<TK>* sc = successor(child_node, i);
		TK temp = sc->keys[0];
		sc->keys[0] = key;
		child_node->keys[i] = temp;
		remove(child_node->children[i+1], child_node, key);
	}

  // !Important
  int minKeys = floor((this->M-1)/2);
  if (child_node->count < minKeys && child_node != this->root){
    int index_child = 0;

    for (; index_child <= parent->count; index_child++){
      if (parent->children[index_child] == child_node){
        break;
      }
    }

    Node_M<TK>* sibling_node = nullptr;
    int idxKeyParent;
    int idxNodeSibling;
    bool right = false;
    if (index_child == 0) // *Immediate right.
    {
        idxNodeSibling = index_child + 1;
      idxKeyParent = index_child;
      right = true;
      if(parent->children[index_child + 1]->count > minKeys){
          sibling_node = parent->children[index_child + 1];
      }
    }
    else if (index_child == parent->count) // *Immediate left.
    {
      idxKeyParent = index_child - 1;
        idxNodeSibling = index_child - 1;
      if(parent->children[index_child - 1]->count > minKeys){
          sibling_node = parent->children[index_child - 1];
      }
    }
    else if (0 < (index_child & index_child < parent->count)) // *Immediate right and left.
    {
      if(parent->children[index_child + 1]->count > minKeys){
          sibling_node = parent->children[index_child + 1];
        idxKeyParent = index_child;
        right = true;
      } else if(parent->children[index_child - 1]->count > minKeys){
          sibling_node = parent->children[index_child - 1];
        idxKeyParent = index_child - 1;
      } else {
          idxNodeSibling = index_child + 1;
        idxKeyParent = index_child;
        right = true;
      }
    }

    // Rotation
    if(sibling_node != nullptr){
      child_node->insert(parent->keys[idxKeyParent]);
      parent->remove(idxKeyParent);
        right ? parent->insert(sibling_node->keys[0]) : parent->insert(sibling_node->keys[sibling_node->count - 1]);
        right ? sibling_node->remove(0) : sibling_node->remove(sibling_node->count - 1);
      if(!(child_node->leaf)){
        if(right){
          child_node->children[child_node->count] = sibling_node->children[0];
          sibling_node->remove(0, this->M);
        }else{
          for(int index=child_node->count; index >= 0; index--){
            child_node->children[index + 1] = child_node->children[index];
          }
          child_node->children[0] = sibling_node->children[sibling_node->count + 1];
          sibling_node->remove(sibling_node->count + 1, this->M);
        }
      }
    // Merge
    }else{

      Node_M<TK>* node_sibling = parent->children[idxNodeSibling];
        if(!right){
        Node_M<TK>* temp = child_node;
        child_node = node_sibling;
        node_sibling = temp;
        idxNodeSibling++;
      }

      // Insert elements from the sibling into the node.
      int indexInsertedParent = child_node->insert(parent->keys[idxKeyParent]);
      parent->remove(idxKeyParent);
      for(int index_sibling=0; index_sibling<node_sibling->count;index_sibling++){
        child_node->insert(node_sibling->keys[index_sibling]);
      }
      // Insert leaves from the sibling node into the merge node.
      if(!(child_node->leaf)){
        for(int idx_child_sibling = 0; idx_child_sibling <= node_sibling->count; idx_child_sibling++){
          child_node->children[indexInsertedParent+1] = node_sibling->children[idx_child_sibling];
            node_sibling->children[idx_child_sibling] = nullptr;
          indexInsertedParent++;
        }
      }
      Node_M<TK>* temp = node_sibling;
      parent->remove(idxNodeSibling, this->M);
      temp->killSelf();
    }
  } else if (child_node == this->root && child_node->count == 0){

      if(child_node->children[0] != nullptr){
      Node_M<TK>* temp = child_node->children[0];
      child_node->children[0] = nullptr;
      this->root->killSelf();
      this->root = temp;
    }
  }
}

template<typename TK>
Node_M<TK>* BTree_M<TK>::successor(Node_M<TK>* node, int idx){
	return minNode(node->children[idx+1]);
}

template<typename TK>
[[maybe_unused]] Node_M<TK>* BTree_M<TK>::predecessor(Node_M<TK>* node, int idx){
	return maxNode(node->children[idx-1]);
}

template<typename TK>
Node_M<TK>* BTree_M<TK>::minNode(Node_M<TK>* node){
  if(node->leaf){
    return node;
  }else{
      return minNode(node->children[0]);
  }
}

template<typename TK>
Node_M<TK>* maxNode(Node_M<TK>* node){
  if(node->leaf){
    return node;
  }else{
      return maxNode(node->children[node->count]);
  }
}

template<typename TK>
void BTree_M<TK>::insert(TK key){
  if(this->root == nullptr){
    this->root = new Node_M<TK>(this->M, true);
    root->insert(key);
  }else{
    SplitResult_M<TK>* split_result = insert(this->root, key);
    if(split_result != nullptr){
      auto *parent = new Node_M<TK>(M, false);
      parent->keys[0] = split_result->key;
      parent->children[0] = root;
      parent->children[1] = split_result->right_tree;
      parent->count = 1;
      root = parent;
    }
  }
  (this->n)++;
}

template<typename TK>
SplitResult_M<TK>* BTree_M<TK>::insert(Node_M<TK>* &node, TK key){
  int i = 0;
  while (i < node->count && key > node->keys[i])
      i++;
  if (i < node->count && node->keys[i] == key)
      return nullptr;

  if (node->leaf)
  {
      // If the leaf has space, insert
      if (node->count < M - 1)
          relocate(node, key);
      // Split and return the result to the ancestor.
      else if (M % 2 == 0)
          return split_even(node, key);
      else
          return split_odd(node, key);
  }
  // is internal node
  else
  {
      // Insert into the respective child
      SplitResult_M<TK> *split_result = insert(node->children[i], key);
      // If split_result != nullptr, it means a split occurred in children[i]
      if (split_result != nullptr)
      {
          // If there is space, relocate the split_result
          if (node->count < M - 1)
              relocate(node, split_result->key, split_result->right_tree);
          // In the case of a split, divide and return the new node to the ancestor
          else if (M % 2 == 0)
              return split_even(node, split_result->key, split_result->right_tree);
          else
              return split_odd(node, split_result->key, split_result->right_tree);
      }
  }
  return nullptr;
}


template<typename TK>
void BTree_M<TK>::relocate(Node_M<TK> *&node, TK key, Node_M<TK> *key_right_tree){
  int i = node->count - 1;
    // Move the keys to make space for the new key.
  while (i >= 0 && key < node->keys[i]) {
      node->keys[i + 1] = node->keys[i];
      node->children[i + 2] = node->children[i + 1];
      i--;
  }
  i++;
  node->keys[i] = key;
  node->children[i + 1] = key_right_tree;
  node->count++;
}

template<typename TK>
Node_M<TK>* BTree_M<TK>::generate_right_node(Node_M<TK> *&node, int from){
  auto *right_node = new Node_M<TK>(M, node->leaf);

  // Copy keys and children from the original node.
  int i = from, j = 0;

  while (i < M - 1) // Remember that the node is full.
  {
      right_node->keys[j] = node->keys[i];
      right_node->children[j] = node->children[i];
      i++;
      j++;
  }
  right_node->children[j] = node->children[i];
  right_node->count = j;
  return right_node;
}

template<typename TK>
SplitResult_M<TK>* BTree_M<TK>::split_even(Node_M<TK>* &node, TK key, Node_M<TK> *key_right_tree){
    // Calculate the middle element
    int m = (M - 1) / 2;
    TK middle = node->keys[m];
    // Create a right node from m+1
    Node_M<TK> *right_node = generate_right_node(node, m + 1);
    // Update the count of elements in the node
    node->count = m;
    // Insert the key on the respective side
    if (key < middle)
        relocate(node, key, key_right_tree);
    else
        relocate(right_node, key, key_right_tree);
    // Return the middle element and the right node
    return new SplitResult_M<TK>(middle, right_node);
}

template<typename TK>
SplitResult_M<TK>* BTree_M<TK>::split_odd(Node_M<TK>* &node, TK key, Node_M<TK> *key_right_tree){
  Node_M<TK> *right_node;
  TK middle;
    // Calculate the center element correctly
  int m = (M - 1) / 2;
  if (key > node->keys[m])
  {
      right_node = generate_right_node(node, m + 1);
      middle = node->keys[m];
      node->count = m;
      relocate(right_node, key, key_right_tree);
  }
  else
  {
      m = m - 1;
      right_node = generate_right_node(node, m + 1);
      if (key < node->keys[m])
      {
          middle = node->keys[m];
          node->count = m;
          relocate(node, key, key_right_tree);
      }
      else
      { // In case the key to insert occupies the middle position
          middle = key;
          node->count = m + 1;
          right_node->children[0] = key_right_tree;
      }
  }
    // Return the center element and the right node
  return new SplitResult_M<TK>(middle, right_node);
}


template<typename TK>
int BTree_M<TK>::height(Node_M<TK>* node){
  if(n==0){
    return 0;
    }
  if (node == nullptr){
    return -1;
  }else{
    return 1 + height(node->children[0]);
  }


}

template<typename TK>
string BTree_M<TK>::toString(Node_M<TK>* node, const string& sep){
  string result;
  root->toString(result, sep);
  return result.substr(0,result.size()-sep.length());
}

template<typename TK>
TK BTree_M<TK>::minKey(Node_M<TK>* node){
  if(root == nullptr){throw std::out_of_range("Tree is empty");}
  if(node->leaf){
    return node->keys[0];
  }else{
      return minKey(node->children[0]);
  }


}

template<typename TK>
TK BTree_M<TK>::maxKey(Node_M<TK>* node){
  if(root == nullptr){throw std::out_of_range("Tree is empty");}
  if(node->leaf){
    return node->keys[node->count - 1];
  }else{
      return maxKey(node->children[node->count]);
  }
}




#endif
