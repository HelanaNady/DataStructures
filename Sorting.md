# Selection Sort

Selection Sort is a simple comparison-based sorting algorithm. The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (or from right to left at the end), and the sublist of items remaining to be sorted.

### Characteristics:
- **Time Complexity**: O(n²) for the best, worst, and average cases.
- **Space Complexity**: O(1) because it only requires a constant amount of additional memory space.
- **Stability**: Not stable.
- **In-Place**: Yes.
### Example Code

#### Selection Sort: Left to Right (Ascending Order)

```cpp
void SelectionSort_asc_L2R(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;  // Assume the minimum element is the first element
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {  // For ascending order
				min = j;  // Find the index of the minimum element
			}
		}
		if (min != i) {
			std::swap(arr[i], arr[min]);  // Swap the minimum element with the first element
		}
	}
}

```
##
#### Selection Sort: Right to Left (Descending Order)

```cpp
void SelectionSort_asc_R2L(int arr[], int n) {
	for (int i = n - 1; i > 0; i--) {
		int max = i;  // Assume the maximum element is the last element
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > arr[max]) {  // For descending order
				max = j;  // Find the index of the maximum element
			}
		}
		if (max != i) {
			std::swap(arr[i], arr[max]);  // Swap the maximum element with the last element
		}
	}
}
```



### Explanation:

1. **Selection Sort (Left to Right)**:
   - The algorithm searches for the minimum element in the array and swaps it with the first unsorted element, building a sorted list from left to right.

2. **Selection Sort (Right to Left)**:
   - This version works in reverse, searching for the maximum element and swapping it with the last unsorted element, building a sorted list from right to left.

#
#
# Bubble Sort

Bubble Sort is a simple comparison-based sorting algorithm. It repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. This process is repeated until the list is sorted.

### Characteristics:
- **Time Complexity**: O(n²) for the worst and average cases, O(n) for the best case (when the list is already sorted).
- **Space Complexity**: O(1) because it only requires a constant amount of additional memory space.
- **Stability**: Stable.
- **In-Place**: Yes.

### Example Code

#### Bubble Sort: Left to Right (Ascending Order)

```cpp
void BubbleSort_asc_R2L(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) { // For ascending order
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
```
#### Bubble Sort: Right to Left (Ascending Order)

```cpp
void BubbleSort_asc_L2R(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = n - 1; j > n - i - 1; j--) {
            if (arr[j] < arr[j - 1]) { // For ascending order
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }
}
```

### Explanation:

1. **Bubble Sort (Left to Right)**:
   - The algorithm works by repeatedly swapping adjacent elements if they are in the wrong order, with the largest unsorted element "bubbling" to the top of the list with each pass.

2. **Bubble Sort (Right to Left)**:
   - In this variation, the algorithm compares elements from the end of the array, with the smallest unsorted element "bubbling" to the bottom of the list with each pass.

#
#

# Insertion Sort

Insertion Sort is a simple comparison-based sorting algorithm. It builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

### Characteristics:
- **Time Complexity**: O(n²) for the worst and average cases, O(n) for the best case (when the list is already sorted).
- **Space Complexity**: O(1) because it only requires a constant amount of additional memory space.
- **Stability**: Stable.
- **In-Place**: Yes.

### Example Code

#### Insertion Sort: Left to Right (Ascending Order)

```cpp
void insertionSort_asc_L2R(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) { // For ascending order
            arr[j + 1] = arr[j]; // Move elements greater than key to one position ahead of their current position
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
```

#### Insertion Sort: Right to Left (Ascending Order)

```cpp
void insertionSort_asc_R2L(int arr[], int n) {
    int i, key, j;
    for (i = n - 2; i >= 0; i--) { // Start from the second last element
        key = arr[i];
        j = i + 1;
        while (j < n && arr[j] < key) { // For ascending order
            arr[j - 1] = arr[j]; // Move elements greater than key to one position ahead of their current position
            j = j + 1;
        }
        arr[j - 1] = key;
    }
}
```

### Explanation:

1. **Insertion Sort (Left to Right)**:
   - The algorithm iteratively takes an element from the unsorted portion and places it in the correct position in the sorted portion by shifting elements to the right.

2. **Insertion Sort (Right to Left)**:
   - This variation starts from the end of the array and iteratively takes an element from the unsorted portion, placing it in the correct position by shifting elements to the left.

#
#

# Shell Sort

Shell Sort is an optimization over Insertion Sort, where elements are sorted at a specific interval (gap) first and then the gap is reduced over time. This allows elements to be moved across the array more efficiently than in a standard insertion sort.

### Characteristics:
- **Time Complexity**: Varies depending on the gap sequence, but typically between O(n^1.5) and O(n²).
- **Space Complexity**: O(1) because it only requires a constant amount of additional memory space.
- **Stability**: Not stable.
- **In-Place**: Yes.

### Example Code

#### Shell Sort: Left to Right (Ascending Order)

```cpp
void ShellSort_asc_L2R(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < n; i++) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            int j;
            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) { // For ascending order
                arr[j] = arr[j - gap];
            }
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}
```

#### Shell Sort: Right to Left (Ascending Order)

```cpp
void ShellSort_asc_R2L(int arr[], int n) {
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is gap sorted
        for (int i = n - gap - 1; i >= 0; i--) {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
            int j;
            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            for (j = i; j < n - gap && arr[j + gap] < temp; j += gap) { // For ascending order
                arr[j] = arr[j + gap];
            }
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
}
```

### Explanation:

1. **Shell Sort (Left to Right)**:
   - The algorithm starts with a large gap between elements, then reduces the gap after sorting the elements at that distance. The process continues until the gap is reduced to 1, at which point it becomes a standard insertion sort.

2. **Shell Sort (Right to Left)**:
   - This variation works similarly, but it starts from the end of the array and reduces the gap while sorting the elements from right to left.


#
#









