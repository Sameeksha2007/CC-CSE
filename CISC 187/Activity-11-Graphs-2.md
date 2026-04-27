# Activity 11: Graphs 2
## Question 1: Explain with the help of an example "Why Dijkstra's algorithm fails on negative weights".
```
    (2)       (3)
A -------> C -------> D
|                     ^
|         (5)         |
+-------> B ----------+
               (-6)
```
Edges: A→C (2), A→B (5), C→D (3), B→D (−6)


Dijkstra's algorithm always picks the vertex that is unvisited and then marks it done. When a vertex is marked done, that means that the algorithm will not be checked again.

The algorithm starts with A and then finds two options (C = 2 and B = 5), but since C is smaller, it chooses it, then reaches D leading ot the total of 5 (2 + 3) and then D is marked done.

Later, the algorithm goes to B and then continues to D leading to the total to equal -1 (5 + -6), and since this is less than 5, this is the shorter path; but earlier D was marked done, therefore, this is skipped, and the final shortest path reported is 5 though the real answer is -1.

This happens because Dijkstra assumes that once a vertex is done, no cheaper path to it can show up later. This is true when all weights are positive, because every extra step makes the path more expensive. But when there is a negative edge path with longer edge can actually be shorter, but Dijkstra cannot redo the answer.
