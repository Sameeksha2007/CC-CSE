## Activity 13 - Space Constraints

# Question 1. Following is the 'Word Builder' algorithm. Describe its space complexity in terms of Big O.
```
function wordBuilder(array) { 
		let collection = [];
		for(let i = 0; i < array.length; i++) { 
				for(let j = 0; j < array.length; j++) {
						if (i !== j) {
								collection.push(array[i] + array[j]);
						}
				}
		}
		return collection; 
}
```

Space Complexity --> O(N^2)

For the input array of size N, the inner loop runs N times for each iteration of the outer loop.
- N * (N-1) = N^2 - N
  
# Question 2. Following is a function that reverses an array. Describe its *space* complexity in terms of Big O:
```
function reverse(array) { 
		let newArray = [];
		for (let i = array.length - 1; i >= 0; i--) { 
				newArray.push(array[i]);
		}
		return newArray;
}
```
Space Complexity --> O(N)

Function creates new vector holding N elements. 

# Question 3. Create a new function to reverse an array that takes up just $O(1)$ extra space.
```
void reverseInPlace(std::vector<int>& array) {
    size_t left = 0;
    size_t right = array.size();
    if (right == 0) return;  // guard against empty array
    right--;                  // now points to last index

    while (left < right) {
        std::swap(array[left], array[right]);
        left++;
        right--;
    }
```

# Question 4. Following are three different implementations of a function that accepts an array of numbers and returns an array containing those numbers multiplied by 2. For example, if the input is [5, 4, 3, 2, 1], the output will be [10, 8, 6, 4, 2].
````
function doubleArray1(array) { 
	let newArray = [];

	for(let i = 0; i < array.length; i++) { 
		newArray.push(array[i] * 2);
	}
	return newArray; 
}


function doubleArray2(array) {
	for(let i = 0; i < array.length; i++) {
  	array[i] *= 2;
  }
	return array; 
}


function doubleArray3(array, index=0) { 
	if (index >= array.length) { return; }
  array[index] *= 2;
  doubleArray3(array, index + 1);
	return array; 
}
````

Fill in the table that follows to describe the efficiency of these three versions in terms of both time and space:

| Version    | Time complexity | Space complexity |
| ---------- | --------------- | ---------------- |
| Version #1 | O(N)            | O(N)             |
| Version #2 | O(N)            | O(1)             |
| Version #3 | O(N)            | O(N)             |
