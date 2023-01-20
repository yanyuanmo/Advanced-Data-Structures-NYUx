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

void csv_import2(NODE** data, string filename){
    ifstream iFile;
    string firstname,lastname,email;
    iFile.open(filename);
    if (!iFile) cout << "Not open." << endl;
    NODE *prev = nullptr;

    while (getline(iFile,firstname,',') && getline(iFile,lastname,',') && getline(iFile,email,'\n')){
        NODE *node = new NODE;
        node->firstname = firstname;
        node->lastname = lastname;
        node->email = email;
        node->next = nullptr;

        // *cur = *node;
        if (prev) {
            prev->next = node;
            prev = prev->next;
        }
        else {
            *data = node;
            prev = node;
        }
    }
}