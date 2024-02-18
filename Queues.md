# Queues

<div align="center">
  <img src="https://github.com/HelanaNady/DataStructure/assets/84867341/d89eb698-df26-44ac-9dea-f3eaec1f10ec" alt="Queue" width="65%">
</div>


Queues are FIFO structure first in-first out. 

- Linked list implemenation
- Array implementation

## Types 
- priority queues
- DEqueues

-----
## QueueInterface Class

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

## A linked-based implementation 

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

![Pasted image 20240218003514](https://github.com/HelanaNady/DataStructures/assets/84867341/bba43364-cd99-4457-9415-077af772cad5)

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
## An array-based implementation 

Using a linear array isn't the most efficient way, every time we dequeue an item we have to shift all items to the left so we don't run out of space, a better approach is to use a circular array, basically when you reach the end you go back to the beginning in a cycle 

There is just one small problem with circular array is you can't detect whether a queue is empty or full easily, Consider the following two examples
![Pasted image 20240218023040](https://github.com/HelanaNady/DataStructures/assets/84867341/d794e1dc-7a51-430a-85b4-c6a1df3c319b)

In both cases: empty and full queue front can be ahead of back. There are multiple ways we can solve this problem: one way is to keep a count of the items or use a boolean variable `isFull` however a faster and better solution would be to sacrifice one location instead and instead add only `MAX_QUEUE-1` items 

![Pasted image 20240218023452](https://github.com/HelanaNady/DataStructures/assets/84867341/696466e1-a6ee-4708-8130-8caac13d4e4d)

The condition for full queue becomes front = (back + 1) % (MAX_QUEUE + 1)
and for empty it remains if front equals back.

####  isEmpty

```cpp
template <typename T>
bool ArrayQueue<T>::isEmpty() const
{
	if(front == back)
	    return true;
	return false;
}
```

#### enqueue() 

```cpp
template <typename T>
bool ArrayQueue(const T& newEntry) 
{
	if(front == (back + 1) % (MAX_QUEUE + 1)) //if list is full
		return false;
		
	back = (back+1) % MAX_QUUEUE;
	items[back] = newEntry;
	return true;
}
```

#### dequeue

```cpp
template <typename T>
bool dequeue() 
{
	if(isEmpty())
		return false;
	front = (front+1) % MAX_QUEQUE;
	return true;
}
```

#### peekFront

```cpp
template< typname T> T ArrayQueue::peekFront() const
	throw(PrecondViolatedExcep) 
{ 
	if (isEmpty()) 
		throw PrecondViolatedExcep("peekFront() called with empty queue"); 
	return items[front]; 
} 
```






