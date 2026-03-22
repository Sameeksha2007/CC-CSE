// stack.cpp
#include "stack.h"

// Set top to null (empty stack)
Stack::Stack()
{
    top = nullptr;
}

// Add new node at the top
void Stack::push(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Remove node from the top
void Stack::pop()
{
    if (top == nullptr)
    {
        cout << "Stack Underflow" << endl;
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

// Return top value
int Stack::peek()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return top->data;
}

// Return true if stack has no nodes
bool Stack::isEmpty()
{
    return top == nullptr;
}

// Print every node from top to bottom
void Stack::display()
{
    if (top == nullptr)
    {
        cout << "Stack is empty" << endl;
        return;
    }

    cout << "Stack elements:" << endl;

    Node* temp = top;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
