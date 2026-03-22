// stack.h
#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack();
    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
    void display();
};

#endif
