# Queues

<div align="center">
  <img src="https://github.com/HelanaNady/DataStructure/assets/84867341/d89eb698-df26-44ac-9dea-f3eaec1f10ec" alt="Queue" width="65%">
</div>


Queues are FIFO structure first in-first out. The first item added is the first one removed.

- [Linked list implementation](#Linked-list-implementation)
- [Array implementation](#Array-implementation)

## Types 
- priority queues
- DEqueues

-----
## QueueInterface Class

<p align="center">
  <img src="https://github.com/HelanaNady/DataStructures/assets/84867341/e0caee98-d234-4f2c-9049-17286540ffb1" alt="Queue GIF">
</p>


```cpp
#pragma once
template< class T> 
class QueueInterface 
{ 
public: 
    /** Sees whether this queue is empty. 
    @return True if the queue is empty, or false if not. */ 
    virtual bool isEmpty() const = 0; 

    /** Adds a new entry to the back of this queue. 
    @post If the operation was successful, newEntry is at the
    back of the queue. 
    @param newEntry The object to be added as a new entry. 
    @return True if the addition is successful or false if not. */ 
    virtual bool enqueue( const T& item) = 0;

    /** Removes the front of this queue. 
    @post If the operation was successful, the front of the queue
    has been removed. 
    @return True if the removal is successful or false if not. */ 
    virtual bool dequeue() = 0;

    /** Returns the front of this queue. 
    @pre The queue is not empty. 
    @post The front of the queue has been returned, and the
    queue is unchanged. 
    @return The front of the queue. */ 
    virtual T peekFront() = 0; 
}; // end QueueInterface 

```
----

## Linked list implementation 
A linked list implementation offers dynamic resizing as new elements are added 
  
#### Class definition 

```cpp
template <typename T>
class ArrayQueue : public QueueInterface 
{
private:
    Node<T>* frontPtr;
    Node<T>* backPtr;
public:
    LinkedQueue();
    bool isEmpty() const;
    bool enqueue(const T& item);
    bool dequeue();
    T peekFront();
    ~ LinkedQueue();
};
```
- assuming class node is implemented
- We will need a head pointer as usual and a tail pointer for the enqueue operation

#### isEmpty

```cpp
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
    return (!frontPtr && !backPtr);
}
```

#### enqueue

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/f81691df-f663-4d20-9602-9622232a12ed)

```cpp
template <typename T>
bool LinkedQueue<T>::enqueue(T item)
{
    Node<T>* newNodePtr = new Node<T>(item);

    //if node inserted is the first one
    if (frontPtr == nullptr)
        frontPtr = newNodePtr;
    else
        backPtr->next = newNodePtr;

    backPtr = newNodePtr;
    return true;
}
```

#### dequeue

![Pasted image 20240218003733](https://github.com/HelanaNady/DataStructures/assets/84867341/14237241-0e3b-4a07-a358-148393408db6)


```cpp
template <typename T>
bool LinkedQueue<T>::dequeue()
{
    if (isEmpty())
        throw std::out_of_range("can not dequeue from an empty queue");

    Node<T>* nodeToDeletePtr = frontPtr;
    frontPtr = frontPtr->next;
    delete nodeToDeletePtr;

    if (frontPtr == nullptr) //if list becomes empty set back to null
        backPtr = nullptr;

    return true;
}
```

#### peekfront

```cpp
template< class T> 
ItemType ArrayQueue<T>::peekFront()
{ 
    if (isEmpty())
	throw std::out_of_range("peekFront() called with empty queue");
    return front->item; 
} 
```
## Array implementation 
An array implementation provides faster access 

### Naïve approach: linear array
Using a linear array isn't the most efficient way, every time we dequeue an item we have to shift all items to the left so we don't run out of space, that process takes O(n).

### Circular array 
A better approach is to use a circular array, when you reach the end of it you go back to the beginning in a cycle that way we won't need to shift anything!

There is just one small problem with circular array is you can't detect whether a queue is empty or full easily, Consider the following two examples:

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/083481cb-ffcf-48e6-9e74-243c137c756f)

In both cases: empty and full queue front can be ahead of back. There are multiple ways we can solve this problem: one way is to keep a count of the items or use a Boolean variable `isFull` .

Another solution would be to sacrifice one location of the array to always be empty and declare the array to be of `size + 1`

The new conditions become:
- for full queue: `front == (back + 1) % (size + 1)`
- for empty queue: `front == back `

and we increment the indices using the following relations: 
- `front = (front + 1) % (size + 1)`
- `back = (back + 1) % (size + 1)`

In order for this solution to work and be easy to implement we either change:
- The front index to point to the location before the first item 
- The back index to point to the location after the last item 

The difference between both approaches is the way `enqueue` and `peekFront()` are implemented
- Front points to location before first item 
	- In `peekFront` you return the element after front 
- Back points to location after last item 
	- In `enqueue` you add the item then increment the back index 

Since they are both very similar we will explain only one (the second case)

#### Class definition 

```cpp
template <typename T>
class ArrayQueue : public QueueInterface 
{
private:
    int front;
    int back;
    int size;
    T* items;
public:
    ArrayQueue(int size);
    bool isEmpty() const;
    bool enqueue(const T& item);
    bool dequeue();
    T peekFront();
    ~ ArrayQueue();
};
```

- Front and back indices to keep track of start and end 
- The array is dynamically allocated based on the size specified

#### Constructor 

```cpp
template <typename T>
bool ArrayQueue<T>::ArrayQueue(int size) : front(0), back(0), size(size)
{
    items = new T[size + 1];
}
```
![Pasted image 20240227002240](https://github.com/HelanaNady/DataStructures/assets/84867341/b6ec4a68-22c3-4184-b719-ae2b535a52cd)

####  isEmpty

```cpp
template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return front == back;
}
```

#### enqueue() 

- The back index  points to the location after the last item 

```cpp
template <typename T>
bool ArrayQueue<T>::enqueue(const T& item) 
{
    if(front == (back + 1) % (size + 1))
	throw std::out_of_range("queue is full can not add more items");

    items[back] = item;
    back = (back+1) % (size + 1);
    return true;
}
```

#### dequeue

```cpp
template <typename T>
bool ArrayQueue<T>::dequeue() 
{
    if(isEmpty())
	throw std::out_of_range("can not dequeue from an empty queue");
		
    front = (front+1) % (size + 1);
    return true;
}
```

we increment the front index, note that "deleting" is advancing front and overwriting the old item when a new item is added to the same location.

#### peekFront

```cpp
template <typename T>
T ArrayQueue<T>::peekFront() 
{
    if(isEmpty())
	throw std::out_of_range("empty queue");
    return items[front];
}
```

----

# Applications 

- **ask scheduling**: Operating systems schedule processes using queues, ensuring tasks are executed in the order they are received.
- **Simulation**: Queues can model real-world queues, such as lines at a store or traffic light wait times.
- **Breadth-first search (BFS) in trees and graphs**: BFS algorithms often use queues to explore nodes level by level.


