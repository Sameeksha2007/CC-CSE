# Activity 4b: Adaptive Algorithm
## PART A: Adaptive Sorting Selection
To measure how sorted the array is, the number of adjacent inversions is counted --> arr[i] > arr[i+1].
- With 50 integers, there will be 49 comparisons.

Case Classification Rule
- Best Case (Nearly Sorted) = inversions <= 5 (~10% of 49)
- Worst Case (Descending Order) =  inversions >= 44 (~90% of 49)
- Average Case = other situations

Appropriate Sorting Algorithm
- Almost Sorted = Insertion Sort {Best Case = O(N) + Average/Worst Case = O(N^2)}
- Otherwise = Selection Sort {All Cases = O(N^2)}

``` C++
#include <iostream>
using namespace std;

const int SIZE = 50;

// Count disorder = counter for checking how many times two neighboring numbers are in the wrong order
int countDisorder(int arr[]) {
  int count = 0;
    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1])
            count++;
    }
    return count;
}

// Selection Sort
void selectionSort(int arr[]) {
    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = i + 1; j < SIZE; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

// Insertion Sort
void insertionSort(int arr[]) {
    for (int i = 1; i < SIZE; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[SIZE];

    cout << "Enter 50 integers:\n";
    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];

    int disorder = countDisorder(arr);

    if (disorder <= 5) {
        cout << "Nearly Sorted -- Using Insertion Sort\n";
        insertionSort(arr);
    }
    else {
        cout << "Not Nearly Sorted -- Using Selection Sort\n";
        selectionSort(arr);
    }

    cout << "Sorted Array:\n";
    for (int i = 0; i < SIZE; i++)
        cout << arr[i] << " ";

    return 0;
}
```
## Part B) Case Classification Without Sorting
``` C++
#include <iostream>
using namespace std;

const int SIZE = 50;

int main() {
    int arr[SIZE];
    int disorder = 0;

    cout << "Enter 50 integers:\n";
    for (int i = 0; i < SIZE; i++)
        cin >> arr[i];

    for (int i = 0; i < SIZE - 1; i++) {
        if (arr[i] > arr[i + 1])
            disorder++;
    }

    if (disorder >= 44)
        cout << "Worst Case\n";
    else
        cout << "Average Case\n";

    return 0;
}
```

## Part C) Documentation
There are total of 49 comparisons for a 50 element array.
- Nearly Sorted or Best Case when there are less equal or equal to 5 inversions --> 10% Disorder
- Worst Case when there are more than or equal to 44 inversions --> 90% Disorder
- Any other amount of inversions is Average Case

Insertion Sort is the best for Nearly Sorted data (best case) because if the array is already almost sorted, the time complexity becomes O(N) since there will be no shifts and each element is compared only once.

Selection Sort is better for other cases because there will be same number of comparisions and the time complexity will be O(N^2) in any type of case. There will be most number of swaps. But when the array is highly unsorted then, selection sorts compares every element carefully, and nothing is missed.

Input Order Affecting Time Complexity
- Selection Sort: All Cases (Best, Average, Worst) = O(N^2) --> Input does not affect the performance.
- Insertion Sort: Best = O(N) and Average/Worst = O(N^2) --> Input does affect the performance.
