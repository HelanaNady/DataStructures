# Stacks 

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/b15339be-bd6d-465d-872a-edf323812141)

 A stack has the property that the last item placed on the stack will be the first item removed. This property is commonly referred to as last in, first out
or simply **LIFO** </br>

## StackInterface Class

```cpp
#pragma once
template<class T>


class StackInterface
{
public:
	/** Sees whether this stack is empty.
	@return True if the stack is empty, or false if not. */
	virtual bool isEmpty() const = 0;
	/** Adds a new entry to the top of this stack.
	@post If the operation was successful, newEntry is at the top of the stack.
	@param newEntry The object to be added as a new entry.
	@return True if the addition is successful or false if not. */
	virtual bool push(const T &val) = 0;
	/** Removes the top of this stack.
	@post If the operation was successful, the top of the stack
	has been removed.
	@return True if the removal is successful or false if not. */
	virtual bool pop() = 0;
	/** Returns the top of this stack.
	@pre The stack is not empty.
	@post The top of the stack has been returned, and
	the stack is unchanged.
	@return The top of the stack. */
	virtual T peek() const = 0;
}; // end StackInterface


```

## Implementation
 A) using [Linked Lists](#LinkedStack)
 B) using [Arrays](#ArrayStack)

----
## LinkedStack

```cpp
#pragma once
#include "Node.h"
#include "StackInterface.h"
using namespace std;
template <typename T>

class LinkedStack:public StackInterface 
{
	Node<T>* topPtr; 
public:
	LinkedStack() :topPtr(nullptr) {} //constructor
	LinkedStack(const LinkedStack<T>& aStack); //default constructor
	bool push(const T &val);
	T pop();
	T peek() const;
	bool isEmpty() const; 
	void display();
	int count();

	virtual ~LinkedStack();

};

template<typename T>
inline LinkedStack<T>::LinkedStack(const LinkedStack<T>& aStack)
{
	//Point to nodes in the original chain
	Node<T>* OrigChainPtr = aStack.topPtr; 
	if (!OrigChainPtr)
	{
		topPtr = nullptr; //chain is empty
	}
	else
	{
		while (OrigChainPtr)
		{
			push(OrigChainPtr->getItem());
			OrigChainPtr = OrigChainPtr->getNext();
		}

	}
}

template<typename T>
inline bool LinkedStack<T>::push(const T &val)
{
	Node<T>* newNode = newNode(val);
	newNode->Next = topPtr;
	topPtr = newNode;
	return true;
}

template<typename T>
inline T LinkedStack<T>::pop()
{
	if (!topPtr)
	{
		throw out_of_range("can not pop an empty stack");
	}
	T val = topPtr->value;
	Node<T>* temp = topPtr;
	topPtr = topPtr->Next;
	delete temp;
	temp = nullptr;
	return val;

}

template<typename T>
inline T LinkedStack<T>::peek() const
{
	if (!isEmpty())
	{
		return topPtr->value;
	}
	return 0;
}

template<typename T>
inline bool LinkedStack<T>::isEmpty() const
{
	if (topPtr)
		return false;
	return true;
}

template<typename T>
inline void LinkedStack<T>::display()
{
	Node<T>* currentPtr = topPtr;
	while (currentPtr) 
	{
		cout << currentPtr->value << endl;
		currentPtr = currentPtr->Next;
	}
}

template<typename T>
inline int LinkedStack<T>::count()
{
	int cnt = 0;
	Node<T>* currentPtr = topPtr;
	while (currentPtr)
	{
		cnt++;
		currentPtr = currentPtr->Next;
	}
}

template<typename T>
inline LinkedStack<T>::~LinkedStack()
{
	while (!isEmpty())
		pop();
}

```

-----

## ArrayStack















