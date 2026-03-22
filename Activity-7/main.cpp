// main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.display();

    s.pop();

    cout << "Top element: " << s.peek() << endl;

    s.display();

    // Test underflow
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    return 0;
}
