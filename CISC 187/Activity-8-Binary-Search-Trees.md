# Activity 8: Binary Search Trees
## Question 1: Imagine you were to take an empty binary search tree and insert the following sequence of numbers in this order: [1, 5, 9, 2, 4, 10, 6, 3, 8]. Draw a diagram showing what the binary search tree would look like. Remember, the numbers are being inserted in the order presented here.
- 1 → root
- 5 > 1 → right of 1
- 9 > 1 → right, > 5 → right of 5
- 2 > 1 → right, < 5 → left of 5
- 4 > 1 → right, < 5 → left, > 2 → right of 2
- 10 > 1 → right, > 5 → right, > 9 → right of 9
- 6 > 1 → right, > 5 → right, < 9 → left of 9
- 3 > 1 → right, < 5 → left, > 2 → right, < 4 → left of 4
- 8 > 1 → right, > 5 → right, < 9 → left, > 6 → right of 6

## Question 2: If a well-balanced binary search tree contains 1,000 values, what is the maximum number of steps it would take to search for a value within it?
For a well-balanced binary search tree that contains 1,000 values, the max steps to search:
- Well balanced BST -- O(log N), N = 1000
- log base 2 (1000) = 10 steps
- this works because when we step down the tree eliminates half the remaining nodes. 

## Question 3: Write an algorithm that finds the greatest value within a binary search tree.
Greatest Value within a BST (the largest value is always the righmost node)
- Start at root node
- Check if there is child node; if no then this is greatest value
- If there is child node, move to the right
- Repeat step 2 

## Question 4: Write a code in C++ using the same array mentioned in #1 and implement a binary search tree. Only insertion operation is required.
``` C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    int arr[] = {1, 5, 9, 2, 4, 10, 6, 3, 8};
    int n = 9;

    Node* root = NULL;

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    cout << "BST created successfully!";
    return 0;
}
```
