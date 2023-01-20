#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX 1000

class Queue {
  public:
    int rear_value;
    int a[MAX]; // Maximum size of Queue
    Queue() { rear_value = -1; }
    bool enqueue(int x);
    int dequeue();
    int front();
    int rear();
};

bool Queue::enqueue(int x) {
    if (rear_value+1==MAX) {
        return false;
    }
    else {
        rear_value++;
        a[rear_value] = x;
        return true;
    }
}

int Queue::dequeue() {
    if (rear_value==-1) {
        return 0;
    }
    else {
        int res = a[0];
        for (int i = 0; i < rear_value-1; i++) {
            a[i] = a[i+1];
        }
        rear_value--;
        return res;
    }
}

int Queue::front() {
    if (rear_value==-1) {
        return 0;
    }
    else {
        return a[0];
    }
}

int Queue::rear() {
    if (rear_value==-1) {
        return 0;
    }
    else {
        return a[rear_value];
    }
}