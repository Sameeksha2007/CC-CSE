## Stack Implementation Using a Linked List in C++
This project shows how stack is implemented using singly linked list in C++.

# Execution
Run Program:
g++ -std=c++17 main.cpp stack.cpp -o stack_demo
./stack_demo

# Sample Output
```
Stack elements:
40
30
20
10

Top element: 30

Stack elements:
30
20
10

Stack Underflow
```

# File Overview
| File | What it does |
|------|-------------|
| stack.h | Node struct and Stack class |
| stack.cpp | push, pop, peek, isEmpty, display |
| main.cpp | Test program |


# Time Complexity
| Operation | Time |
|-----------|------|
| push | O(1) |
| pop | O(1) |
| peek | O(1) |
| isEmpty | O(1) |
| display | O(n) |

# Reflection Questions
1. Why is a linked list efficient for stack implementation?
- A linked list works well for stack implementations because all operations occur at one end which is the top. The head node is directly accessible; therefore, inserting or removing elements is done efficiently. Linked lists also can grow dynmically which is better than arrays becuse they are fixed.

2. What is the time complexity of push and pop operations?
- Both push and pop operations have time complexity of O(1). They only update the few pointers.

3. What happens if memory is not deallocated after pop?
- If memory is not deallocated after pop, the node that is removed stays in memory even though it is not part of the stack. There will be no more reference to it anymore. This will cause a memory leak which means that the memory is being used but not freed. 

4. Compare a stack implemented with an array versus a linked list.
   
| | Array | Linked List |
|-|-------|-------------|
| Size | Fixed | Can gorw if required |
| push/pop | O(1) | O(1) |
| Memory | Less overhead | Extra pointer per node |
| Can overflow? | Yes | No (until heap is full) |
