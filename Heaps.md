# Heaps

![max_heap_deletion_animation](https://github.com/HelanaNady/DataStructures/assets/137416623/f325daf1-9be8-4d13-92bd-49b843b90315)
A ***heap*** is a binary tree-based data structure that satisfies the property: the value of each node is greater than or equal to the value of its children. This property makes sure that the root node contains the maximum or minimum value (depending on the type of heap), and the values decrease or increase as you move down the tree

## Contents

- [Types of Heaps](#Types-of-Heaps)
- [Heap Operations](#Heap-Operations)
- [Heap Applications](#Heap-Appllications)
- [Useful videos](#Useful-videos)
- [Useful articles](#Useful-articles)
- [For practice](#For-practice)

  

![2024-05-04 (1)](https://prepbytes-misc-images.s3.ap-south-1.amazonaws.com/assets/1674109793492-Difference%20Between%20Max%20Heap%20and%20Min%20Heap2.png)

  

## Types of Heaps

 ### [1] Max Heaps
- any  node is always greater than its child node/s and the key of the root node is the largest among all other nodes.

![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/maxheap_1.png)
  
 ### [2] Min Heaps
- any  node is  always smaller than the child node/s and the key of the root node is the smallest among all other nodes.

  

![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/minheap_0.png)

----

## Heap Operations

Some of the important operations performed on a heap are described below along with their algorithms.

- ***Heapify:*** the process of creating a heap data structure from a binary tree. It is used to create a Min-Heap or a Max-Heap.

1. Let the input array be ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/array_1.png)

2. Create a complete binary tree from the array ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/completebt-1_0.png)

3. Start from the first index of non-leaf node whose index is given by ```n/2 - 1```
4. Set current element ``i`` as ``largest``
5. The index of left child is given by `2i + 1` and the right child is given by `2i + 2`.

	If `leftChild` is greater than `currentElement` (i.e. element at `ith` index), set ``leftChildIndex`` as largest.

	If ``rightChild`` is greater than element in `largest`, set `rightChildIndex` as `largest`.

6. Swap `largest` with `currentElement`
7. Repeat steps 3-7 until the subtrees are also heapified.
 ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/swap_1.png)

- Below is the cpp implementation in case of Max heaps:  

```cpp
void heapify(int arr[], int N, int i)

{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
        
    // If right child is larger than largest so far
    if (r < N && arr[r] > arr[largest])
        largest = r;

    // If largest is not root

    if (largest != i) 
    {
        swap(arr[i], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, N, largest);
    }

}
```

----

```cpp

// Min heap

void heapify(int arr[], int N, int i)

{

    int smallest = i; // Initialize smallest as root

    int l = 2 * i + 1; // left = 2*i + 1

    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is smaller than root

    if (l < N && arr[l] < arr[smallest])

        smallest = l;

    // If right child is smaller than smallest so far

    if (r < N && arr[r] < arr[smallest])

        smallest = r;

    // If smallest is not root

    if (smallest != i) {

        swap(arr[i], arr[smallest]);

        // Recursively heapify the affected sub-tree

        heapify(arr, N, smallest);

    }

}

```

  
  

- ****Insert:**** Adds a new element to the heap while maintaining the heap property.

1. Insert the new element at the end of the tree.

![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/insert-heap-1.png)

  
  

2. Heapify the tree.

![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/insert-heap-2.png)

  

```cpp

void insertNode(int arr[], int& n, int Key)

{

    // Increase the size of Heap by 1

    n = n + 1;

    // Insert the element at end of Heap

    arr[n - 1] = Key;

    // Heapify the new node following a

    // Bottom-up approach

    heapify(arr, n, n - 1);

}

```

  
  
  

- ***Delete Element from Heap:*** Adds a new element to the heap while maintaining the heap property.

1. Select the element to be deleted.
 ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/delete-1_1.png)

  2. Swap it with the last element.
 ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/delete-2_1.png)

 3. Heapify the tree.
 ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/delete-4_0.png)
 
````cpp
void deleteNode(int arr[], int& n, int i)
{
    // Get the last element
    int lastElement = arr[n - 1];

    // Replace node at index i with last element
	 arr[i] = lastElement;

    // Decrease size of heap by 1
    n = n - 1;

    // heapify the modified heap
    heapify(arr, n, i);
}

```` 



## Heap Applications

- Heaps are commonly used to implement priority queues, where elements are retrieved based on their priority (maximum or minimum value).

- Heapsort is a sorting algorithm that uses a heap to sort an array in ascending or descending order.

- Heaps are used in graph algorithms like Dijkstra’s algorithm and Prim’s algorithm for finding the shortest paths and minimum spanning trees.
----
## Difference between Max Heap and Min Heap

| Max Heap   | Min Heap |
| ---- | ---- |
| 1. The data at the root node should be greater than each of the child nodes. | 1. The data at the root node should be smaller than each of the child nodes. |
|2. The element having the highest value has the highest priority assigned to it.| 2. The element having the lowest value has the highest priority assigned to it. |
| 3. The first value to be extracted is the maximum value. |3. The first value to be extracted is the minimum value.
| 4. It is used for the purpose of implementing Priority Queue.| 4. It is used for the purpose of implementing Dijkstra Graph Algorithm and Minimum Spanning Trees. |
|5. It is used to sort the array in ascending order using Heap Sort.|5. It is used to sort the array in ascending order using Heap Sort.|
|6. Operations performed in Max Heap include Extract Maximum, Get Maximum and Insertion.|6. Operations performed in Min Heap include Extract Minimum, Get Minimum and Insertion|
|7. The root of the tree must have the maximum value.|7. The root of the tree must have the minimum value.|


---
## Useful Videos

  

## Useful articles
- [Heap Data Structure |geeksforgeeks](https://www.geeksforgeeks.org/heap-data-structure/#heap-data-structure-applications)
- [Programiz](https://www.programiz.com/dsa/heap-data-structure)
## For practice

- [Coding Interview Questions | TakeUforward](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
