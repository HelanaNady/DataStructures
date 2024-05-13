# Heaps

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/4b5ccd87-d9de-45e1-98c6-cb4510a0e762)

A **Heap** is a binary tree-based data structure there are two types:
- **Max Heap:** any node is greater than its children where the parent node always contains the maximum element of this sub-tree
- **Min Heap:** any node is smaller than its children where the parent node always contains the minimum element of this sub-tree

**Heaps** maintain data in semi-order. It is a good tradeoff between having to maintain a complete order and searching through random chaos. They allow quick access to the max and min element in O(1) thus they become useful when we want to remove the element with highest/lowest value (priority) quickly ex: in priority queue.

Sometimes they are called binary heaps and are nearly complete binary trees 
- Height of Heap = log(n)



How to represent Heaps ?
- using a binary tree
- using an array 

## Contents

- [Heap Operations](#Heap-Operations)
	- Heapify
	- insert
	- delete
- [Heap Applications](#Heap-Appllications)
- [Useful videos](#Useful-videos)
- [Useful articles](#Useful-articles)
- [For practice](#For-practice)

  

----

## Heap Operations
Some of the important operations performed on a heap are described below along with their algorithms.

#### Heapify 

- ***Heapify:*** the process of creating a heap data structure from a binary tree. It is used to create a Min-Heap or a Max-Heap.

If the input is an array we will first build a binary tree from it where the root node will be at index 0 and its children are at the following indices:
- Left child index = 2i + 1 
- Right child index = 2i + 2 

> We here assume that the parent node of the tree starts at index 0 
> sometimes to make calculations easier you will see implementations of the heap where the root node is at index 1 instead making:
> - The left child index = 2i
> - The right child index = 2i + 1 

To heapify a tree we wil heapify each node that would take n* logn complexity , a more optimized approach would be to only heapify the non-leaf node 
we can find the index of the last non-leaf node using the following formula : 
last non-leaf node index = n/2 - 1;

```cpp
static void buildHeap(int arr[], int n)
{
	// Index of last non-leaf node
	int startIndex = (n / 2) - 1;

	for (int i = startIndex; i >= 0; i--)
		heapify(arr, n, i);
}
```

 Perform reverse level order traversal from last non-leaf node and heapify each node

1. Let the input array be ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/array_1.png)

2. Create a complete binary tree from the array ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/completebt-1_0.png)




 ![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/swap_1.png)

```cpp
void maxHeapify(int arr[], int n, int parent) 
{
    int largest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    // If left child is larger than parent
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is no longer the parent
    if (largest != parent) 
    {
        std::swap(arr[parent], arr[largest]);
        maxHeapify(arr, n, largest);
    }
}
```

----

```cpp
void minHeapify(int arr[], int n, int parent) {
    int smallest = parent;
    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    // If left child is smaller than parent
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not parent
    if (smallest != parent) {
        std::swap(arr[parent], arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}
```


  #### insert 
  
  
- ****Insert:**** Adds a new element to the heap while maintaining the heap property.

1. Insert the new element at the end of the tree.

![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/insert-heap-1.png)

  
  

2. Heapify the tree.

![2024-05-04 (1)](https://www.programiz.com/sites/tutorial2program/files/insert-heap-2.png)

  

```cpp

void insertNode(int arr[], int& n, int key)
{
    // Increase the size of Heap by 1
    n = n + 1;
    // Insert the element at end of Heap
    arr[n - 1] = key;
    // Heapify the new node following a Bottom-up approach
    heapify(arr, n, n - 1);
}
```

Inserstion is quite simple we insert teh element and heapify the tree all over 


#### Delete 
![max_heap_deletion_animation](https://github.com/HelanaNady/DataStructures/assets/137416623/f325daf1-9be8-4d13-92bd-49b843b90315)


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

## Difference between Max Heap and Min Heap

|                           | Max Heap                                          | Min Heap                                                                                     |
| ------------------------- | ------------------------------------------------- | -------------------------------------------------------------------------------------------- |
| **Root Value**            | Largest element                                   | Smallest element                                                                             |
| **Priority**              | Highest value has highest priority                | Lowest value has highest priority                                                            |
| **First Extracted Value** | Maximum value                                     | Minimum value                                                                                |
| **Common Applications**   | - Priority Queues<br>- Heapsort (ascending order) | - Dijkstra's Algorithm<br>- Prim's Minimum Spanning Tree<br>- Heapsort (ascending order)<br> |



---
## Useful Videos

## Useful articles
- [Heap Data Structure | geeksforgeeks](https://www.geeksforgeeks.org/heap-data-structure/#heap-data-structure-applications)
- [Programiz](https://www.programiz.com/dsa/heap-data-structure)
## For practice

- [Coding Interview Questions | TakeUforward](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
