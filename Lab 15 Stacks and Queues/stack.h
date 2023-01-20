#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 1000

class Stack
{
  public:
  int top;
  int a[MAX]; // Maximum size of Stack
  Stack() { top = -1; }
  bool push(int x);
  int pop();
  int peek();
  bool isEmpty();
};

bool Stack::isEmpty() {
    if (top==-1) {
        return true;
    }
    return false;
}

bool Stack::push(int x) {
    if (top+1==MAX) {
        return false;
    }
    else {
        top+=1;
        a[top] = x;
        return true;
    }
}

int Stack::peek() {
    if (!isEmpty()) {
        return a[top];
    }
    else {
        return 0;
    }
}

int Stack::pop() {
    if (isEmpty()) {
        return 0;
    }
    int res = a[top];
    top--;
    return res;
}