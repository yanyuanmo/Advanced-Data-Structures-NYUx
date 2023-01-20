#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class NODE {
  public:
    string firstname;
    string lastname;
    string email;
    NODE* next;
};

void add_node_tail(NODE** data, string firstname,string lastname, string email) {
    NODE *node = new NODE;
    node->firstname = firstname;
    node->lastname = lastname;
    node->email = email;
    node->next = nullptr;
    if (*data == nullptr){
        *data = node;
        return;
    }

    NODE *endfinder = *data;
    while(endfinder->next!=nullptr) {
        endfinder = endfinder->next;
    }
    endfinder->next = node;
    return;
}


// NODE* data = nullptr; 

// add_node_tail(&data,”aspen”,”olmsted”,”aspeno@aol.com”);