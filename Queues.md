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
	virtual bool enqueue( const T& newEntry) = 0; 
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
	virtual T peekFront() const = 0; 
}; // end QueueInterface 

```
----

## Linked list implementation 

#### Constructor

#### isEmpty

```cpp
template <typename T>
bool LinkedQueue<T>::isEmpty() const
{
    if (frontPtr == nullptr && backPtr == nullptr)
        return true;
    return false;
}
```

#### enqueue

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/f81691df-f663-4d20-9602-9622232a12ed)

```cpp
template <typename T>
bool LinkedQueue<T>::enqueue(T newEntry)
{
    Node<T>* newNodePtr = new Node<T>(newEntry);

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
    if (frontPtr == nullptr)
        return false;

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
ItemType ArrayQueue<T>::peekFront() const 
	throw(PrecondViolatedExcep) 
{ 
	// Enforce precondition 
	if (isEmpty()) 
		throw PrecondViolatedExcep("peekFront() called with empty queue"); 
	return front->item; 
} 
```
## Array implementation 

Using a linear array isn't the most efficient way, every time we dequeue an item we have to shift all items to the left so we don't run out of space, that process takes O(n).

A better approach is to use a circular array, when you reach the end of it you go back to the beginning in a cycle that way we won't need to shift anything!

There is just one small problem with circular array is you can't detect whether a queue is empty or full easily, Consider the following two examples:

![image](https://github.com/HelanaNady/DataStructures/assets/84867341/083481cb-ffcf-48e6-9e74-243c137c756f)

In both cases: empty and full queue front can be ahead of back. There are multiple ways we can solve this problem: one way is to keep a count of the items or use a Boolean variable `isFull` .

Another solution would be to sacrifice one location of the array to always be empty and declare the array to be of `size + 1`

The new conditions become:
- for full queue: `front == (back +1) % (size + 1)`
- for empty queue: `front == back `

In order for this solution to work and be easy to implement we either change:
- The front index to point to the location before the first item 
- The back index to point to the location after the last item 

The difference between whether you consider the front to be location before and leave the back to point to last item or the opposite is how you will enqueue items and the implementation of `peekFront()`
- Incrementing the back index then adding item -> front points to location before first item 
- Adding item then incrementing the back -> back points to location after last item 

and we increment the indices using the following relations: 
- `front = (front + 1) % (size + 1)`
- `back = (back + 1) % (size + 1)`

Since they are both very similar we will explain only one case (the first case)

####  isEmpty

```cpp
template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
	return front == back;
}
```

#### enqueue() 

- First case: The front index points to the location before the first item 

![Pasted image 20240227002240](https://github.com/HelanaNady/DataStructures/assets/84867341/b6ec4a68-22c3-4184-b719-ae2b535a52cd)

```cpp
template <typename T>
bool ArrayQueue<T>::enqueue(const T& item) 
{
	if(front == (back + 1) % (size + 1)) 
		throw std::out_of_range("queue is full can not add more items");
		
	back = (back+1) % (size + 1);
	items[back] = item;
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

we increment the front index, note that "deleting" is advancing front and overwriting the old item when a new item is added to the same place.

