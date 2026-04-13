# Activity 9: Binary Heaps
## Question 1: Draw what the following heap would look like after we insert the value 11 into it:
Start from first heap and 11 is placed at the last node (right child of 5). When the sorting starts:
- 11 > 5 -- swap
- 11 > 9 -- swap
- 11 > 10 -- swap
- 11 is the root, no parent above it -- finish
  
## Question 2: Draw what the previous heap would look like after we delete the root node.
Replace the root (11) with the last node (5), then remove the last node:
- 5 < 10 -- swap
- 5 < 9 -- swap
- 5 > 3 -- stop
- 10 is the root -- final
  
## Question 3: Imagine you’ve built a brand-new heap by inserting the following numbers into the heap in this particular order: 55, 22, 34, 10, 2, 99, 68. If you then pop them from the heap one at a time and insert the numbers into a new array, in what order would the numbers now appear?
When the elements are popped one by one from the max-heap, then the largest element is removed. The output then creates a descending order:
99, 68, 55, 34, 22, 10, 2
