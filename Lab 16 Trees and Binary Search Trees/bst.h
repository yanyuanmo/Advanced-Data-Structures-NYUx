#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BST
{
  public:
  int data;
  BST *left, *right;
  BST() : data(0), left(nullptr), right(nullptr) {};
  BST(int x): data(x), left(nullptr), right(nullptr) {};
  void insert(int x);
  int nth_node(int n);
};

void BST::insert(int x) {
    if (x > this->data) {
        if (this->right!=nullptr) {
            this->right->insert(x);
        }
        else {
            BST *node = new BST(x);
            this->right = node;
        }
    }
    else {
        if (this->left!=nullptr) {
            this->left->insert(x);
        }
        else {
            BST *node = new BST(x);
            this->left = node;
        }
    }
}

int BST::nth_node(int n){
    static int count = 0;
    static int res;
    if (left != NULL){
        left->nth_node(n);
    }
    count++;
    if (count == n) {
        res = data;
    }
    if (right != NULL){
        right->nth_node(n);
    }

    return res;
}
