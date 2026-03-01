# Activity 4a: Sorting Algorithms
## Question 1: Proof that, under the average-case scenario, the insertion sort has a time complexity of O(N^2). Draw a clear figure and show all the operations clearly.
For average-case scenarios:
- i = 1   →  ~1/2 comparisons
- i = 2   →  ~2/2 comparisons
- i = 3   →  ~3/2 comparisons
- i = N-1 →  ~(N-1)/2 comparisons
- total average = (1/2) + (2/2) + ... + ((N-1)/2) = (1/2) (1 + 2 + ... + (N-1))
- total ~ (1/2) × (N(N-1)/2) = (N^2 - N)/4 ~ N^2 --> O(N^2)
  
In insertion sort, each number we insert usually moves halfway back. This means that when we add all of the half-moves for N together, then the total grows in the N^2 form.  

## Question 2: Insertion sort normally begins with i = 1 (0-based indexing). Let N = 5 and assume the array is in descending order (worst case). 
#### Count operations where: 
#### a comparison is A[j] > key
#### 2a shift is A[j+1] = A[j]
Array: [5, 4, 3, 2, 1]
Worst Case --> every element will shift fully left
#### a) Start the algorithm at i = 1. Verify the total operations = 20.
- Start at i = 1 -> key = 4 -> 5 > 4 == yes (1 comparison) -> Shift 5 (1 shift) -> [4, 5, 3, 2, 1] (total operation = 2)
- Start at i = 2 -> key = 3 -> 5 > 3 == yes (1 comparison) -> Shift 5 (1 shift) -> 4 > 3 == yes (1 comparison) -> Shift 4 (1 shift) -> [3, 4, 5, 2, 1] (total operation = 4)
- Start at i = 3 -> key = 2 -> 3 comparisons (5>2, 4>2, 3>2) + 3 shifts -> [2, 3, 4, 5, 1] (total operation = 6)
- Start at i = 4 -> key = 1 -> 4 comparisons (5>1, 4>1, 3>1, 2>1) + 4 shifts -> [1, 2, 3, 4, 5] (total operation = 8)
- Total Comparisons = 2 + 4 + 6 + 8 = **20**
#### b) Start the algorithm at i = 2, then i = 3. Count operations again.
Case 1: where i = 2
- Start at i = 2 -> key = 3 -> 2 comparisons (4>3, 5>3) + 2 shifts -> [3, 5, 4, 2, 1] (total operation = 4)
- Start at i = 3 -> key = 2 -> 3 comparisons (4>2, 5>2, 3>2) + 3 shifts -> [2, 3, 5, 4, 1] (total operation = 6)
- Start at i = 4 -> key = 1 -> 4 comparisons (4>1, 5>1, 3>1, 2>1) + 4 shifts -> [1, 2, 3, 5, 4] (total operation = 8)
- Total Comparisons = 4 + 6 + 8 = **18**

Case 2: where i = 3
- Start at i = 3 -> key = 2 -> 3 comparisons (3>2, 4>2, 5>2) + 3 shifts -> [2, 5, 4, 3, 1] (total operation = 6)
- Start at i = 4 -> key = 1 -> 4 comparisons (3>1, 4>1, 5>1, 2>1) + 4 shifts -> [1, 2, 5, 4, 3] (total operation = 8)
- Total Comparisons = 6 + 8 = **14**

#### c) For (b), does the algorithm still sort the entire array? Explain.
In part (b), the algorithm does not sort the entire array. This happens because insertion sort thinks that since we are starting for a different i value, the previous would be sorted correctly. It does not check the sorting of the elements at are not told to be checked. The previous indexs are not checked and compared.

## Question 3: The following function returns whether or not a capital “X” is present within a string. 
```C++
function containsX(string) {
	foundX = false;
	for(let i = 0; i < string.length; i++) { 
		if (string[i] === "X") {
			foundX = true; 
		}
	}
	return foundX; 
}
```
#### a) What is this function’s time complexity regarding Big O Notation?
The function iterates through every character in the string, regardless of if 'X' is found early or not. Here the N is every character; therefore, the time complexity will be O(N) in all cases because the loop will always run N iterations in all cases.  
- Best case = O(N)
- Average case = O(N)
- Worst case = O(N)

#### b) Then, modify the code to improve the algorithm’s efficiency for best- and average-case scenarios.
Improved Efficiency Code
```C++
function containsX(string) {
    for (let i = 0; i < string.length; i++) {
        if (string[i] === "X") {
            return true;   // stop early
        }
    }
    return false; // if 'X' was never found
}
```
- Best case = O(1) -- returns on the first 
- Average case = O(N/2) ~ O(N) -- this is approximately half the work
- Worst case = O(N) -- checks everything
