#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "cpluspluslabs.h"

using namespace std;

Node* new_node(int key){
    Node *newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

Node* insertnb(Node* node, int key) {
    if (node==nullptr) {
        node = new_node(key);
        return node;
    }
    else if (key < node->key) {
        node->left = insertnb(node->left, key);
        node->left->height = node->height++;
    }
    else if (key > node->key) {
        node->right = insertnb(node->right, key);
        node->right->height = node->height++;
    }
    return node;
}

Node *left_rotate(Node *x){
    
    Node *newHead = x->right;
    Node *transferBranch = newHead->left;
    
    newHead->left = x;
    x->right = transferBranch;

    newHead->height = 1;
    newHead->left->height = newHead->height + 1;
    newHead->right->height = newHead->height + 1;
    
    return newHead;
}
Node *right_rotate(Node *x){
    Node *newHead = x->left;
    Node *transferBranch = newHead->right;
    
    newHead->right = x;
    x->left = transferBranch;
    
    newHead->height = 1;
    newHead->left->height = newHead->height + 1;
    newHead->right->height = newHead->height + 1;
    
    return newHead;
}

int get_balance(Node *x){
    if (x == NULL)
        return 0;
    
    int left, right;
    if (x->left == NULL)
        left = 0;
    else
        left = x->left->height;
    if (x->right == NULL)
        right = 0;
    else
        right = x->right->height;
        
    return left - right;
}

Node* insert(Node* node, int key){
    Node *insertedNode = insertnb(node, key);
    if (get_balance(insertedNode) > 1)
        insertedNode = right_rotate(insertedNode);
    if (get_balance(insertedNode) < -1)
        insertedNode = left_rotate(insertedNode);
    return insertedNode;
}

