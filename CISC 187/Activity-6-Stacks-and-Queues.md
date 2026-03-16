# Activity 6: Stacks and Queues
## Question 1: Using Figure 17 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence PUSH(S,4), PUSH(S,1), PUSH(S,3), POP(S), PUSH(S,8), and POP(S) on an initially empty stack S stored in array S [1...6]
Initial --> S[1..6] = [ -, -, -, -, -, - ], top = 0
PUSH(S,4) --> S[1..6] = [ 4, -, -, -, -, - ], top = 1
PUSH(S,1) --> S[1..6] = [ 4, 1, -, -, -, - ], top = 2
PUSH(S,3) --> S[1..6] = [ 4, 1, 3, -, -, - ], top = 3
POP(S) --> S[1..6] = [ 4, 1, 3*, -, -, - ], top = 2, removes 3
PUSH(S,8) --> S[1..6] = [ 4, 1, 8, -, -, - ], top = 3
POP(S) --> S[1..6] = [ 4, 1, 8*, -, -, - ], top = 2, removes 8
Final --> S[1..6] = [ 4, 1, , -, -, - ], top = 2

## Question 2: Using Figure 18 as a model, in the book Data Structures in C++, illustrate the result of each operation in the sequence ENQUEUE(Q,4), ENQUEUE(Q,1), ENQUEUE(Q,3), DEQUEUE(Q), ENQUEUE(Q,8), and DEQUEUE(Q) on an initially empty queue Q stored in array Q [1...6]
Initial --> Q[1..6] = [ -, -, -, -, -, - ], head = 1, tail = 1 
ENQUEUE(Q,4) --> Q[1..6] = [ 4, -, -, -, -, - ], head = 1, tail = 2
ENQUEUE(Q,1) --> Q[1..6] = [ 4, 1, -, -, -, - ], head = 1, tail = 3
ENQUEUE(Q,3) --> Q[1..6] = [ 4, 1, 3, -, -, - ], head = 1, tail = 4
DEQUEUE(Q) --> Q[1..6] = [ 4*, 1, 3, -, -, - ], head = 2, tail = 4, removes 4
ENQUEUE(Q,8) --> Q[1..6] = [ 4*, 1, 3, 8, -, - ], head = 2, tail = 5
DEQUEUE(Q) --> Q[1..6] = [ 4*, 1*, 3, 8, -, - ], head = 3, tail = 5, removes 1
Final --> [3,8]

## Question 3: Rewrite ENQUEUE and DEQUEUE to detect underflow and overflow of a queue. (see Listings 4 & 5 in the book).
ENQUEUE(Q,x)
 if (Q.head == Q.tail + 1) OR (Q.head == 1 AND Q.tail == Q.length)
     error "overflow"
 Q[Q.tail] = x
 if Q.tail == Q.length
     Q.tail = 1
 else
     Q.tail = Q.tail + 1

DEQUEUE(Q)
 if Q.head == Q.tail
     error "underflow"
 x = Q[Q.head]
 if Q.head == Q.length
     Q.head = 1
 else
     Q.head = Q.head + 1
 return x

## Question 4: A stack allows insertion and deletion of elements at only end, and a queue allows insertion at one end and deletion at the other end, a deque (double-ended queue) allows insertion and deletion at both ends. Write four O(1)-time procedures to insert elements into and delete elements from both ends of a deque implemented by an array
Insert Front 
 if DEQUE-FULL(D)
     error "overflow"
 if front == 1
     front = n
 else
     front = front - 1
 D[front] = x

Insert Rear
 if DEQUE-FULL(D)
     error "overflow"
 D[rear] = x
 if rear == n
     rear = 1
 else
     rear = rear + 1

Delete Front
 if DEQUE-EMPTY(D)
     error "underflow"
 x = D[front]
 if front == n
     front = 1
 else
     front = front + 1
 return x

Delete Rear
 if DEQUE-EMPTY(D)
     error "underflow"
 if rear == 1
     rear = n
 else
     rear = rear - 1
 x = D[rear]
 return x
