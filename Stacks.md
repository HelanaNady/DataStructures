# Stacks 

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/b15339be-bd6d-465d-872a-edf323812141)

 A stack has the property that the last item placed on the stack will be the first item removed. This property is commonly referred to as last in, first out
or simply **LIFO** </br>

## Contents
- [Implementations](#Implementation)
- [Useful videos](#Useful-videos)
- [Useful articles](#Useful-articles)
- [For practice](#For-practice)

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
-----
![stack-operations-in-c](https://github.com/HelanaNady/DataStructures/assets/137416623/5cf031f3-b22e-4fbd-b399-4235d3517e0f)

-----


## Implementation
 - A) using [Linked Lists](#LinkedStack)
-  B) using [Arrays](#ArrayStack) 

----
## LinkedStack

check this if you can't seem to figure the need for a copy constructor: </br>
[Shallow copying vs deep copying](https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/) </br>

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

```cpp
#pragma once
#include "StackInterface.h"
using namespace std;
template <typename T>
#define MAX_STACK 100; //any arbitary number for now

class ArrayStack
{
	int top;
	T items[MAX_STACK];
public:
	ArrayStack() : top(-1) {}           // Default constructor
	bool push(const T& val);
	bool pop(); 
	T peek() const; 
	bool isEmpty() const;
	void display();
	int count(); 
};

template<typename T>
inline bool ArrayStack<T>::push(const T& val) 
{
	if (top != MAX_STACK - 1)
	{
		items[++top] = val;
		return true;
	}
	return false;
}

template<typename T>
inline bool ArrayStack<T>::pop()
{
	if (top == -1)
	{
		throw out_of_range("\ncan not pop an empty stack\n");
	}
	else
	{
		top--;
		return true;
	}
}

template<typename T>
inline T ArrayStack<T>::peek() const
{
	assert (!isEmpty())
	return items[top];
}

template<typename T>
inline bool ArrayStack<T>::isEmpty() const
{
	return top < 0;
}

template<typename T>
inline void ArrayStack<T>::display()
{
	for (int i = 0; i <= top; i++)
	{
		cout << items[i] << endl;
	}
}

template<typename T>
inline int ArrayStack<T>::count()
{
	return (top + 1);
}

```

-----
## Useful videos
- [Stacks - Neso Academy](https://youtube.com/playlist?list=PLBlnK6fEyqRgWh1emltdMOz8O2m5X3YYn&si=kyy7kaNoGDbh42l-)

-----
## Useful Articles
- [Introduction to Stack – Data Structure and Algorithm GeeksForGeeks Tutorials](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/?ref=header_search)
- [Top 50 Problems on Stack Data Structure asked in SDE Interviews](https://www.geeksforgeeks.org/top-50-problems-on-stack-data-structure-asked-in-interviews/?ref=header_search)

-----
## For practice
- [LeetCode problems](https://leetcode.com/tag/stack/) 

----










