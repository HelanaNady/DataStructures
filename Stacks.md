# Stacks 

![image](https://github.com/HelanaNady/DataStructure/assets/84867341/b15339be-bd6d-465d-872a-edf323812141)

A stack has the property that the last item placed on the stack will be the first item removed. This property is commonly referred to as last in, first out
or simply **LIFO** </br> 
**Axioms for the ADT stack:**
- (new Stack()).isEmpty() = true
- (new Stack()).pop() = false
- (new Stack()).peek() = error
- (aStack.push(item)).isEmpty() = false
- (aStack.push(item)).peek() = item
- (aStack.push(item)).pop() = true

## Contents
- [Implementations](#Implementation)
- [ArrayStack vs LinkedStack](#ArrayStack-vs-LinkedStack)
- [Applications using Stack ADT](#Applications-using-Stack-ADT) 
- [Useful videos](#Useful-videos)
- [Useful articles](#Useful-articles)
- [For practice](#For-practice) 
-----
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
};


```
-----
![stack-operations-in-c](https://github.com/HelanaNady/DataStructures/assets/137416623/5cf031f3-b22e-4fbd-b399-4235d3517e0f)

-----


## Implementation
 - A) using [Linked Lists](#LinkedStack)
-  B) using [Arrays](#ArrayStack) 

----
## LinkedStack

Check this if you can't seem to figure the need for a copy constructor: </br>
[Shallow copying vs deep copying](https://www.geeksforgeeks.org/shallow-copy-and-deep-copy-in-c/) </br>


## class:

```cpp
#include "StackInterface.h"
using namespace std;
template <typename T>

class LinkedStack:public StackInterface 
{
	Node<T>* topPtr; 
public:
	LinkedStack() :topPtr(nullptr) {} //constructor
	LinkedStack(const LinkedStack<T>& aStack); //copy constructor
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
inline LinkedStack<T>::~LinkedStack()
{
	while (!isEmpty())
		pop();
}

```

## Functions implemented :
- [push()](#push())
- [pop()](#pop())
- [peek()](#peek())
- [isEmpty()](#isEmpty())
- [display()](#display())
- [count()](#count())
### push()

```cpp
template<typename T>
inline bool LinkedStack<T>::push(const T &val)
{
	Node<T>* newNode = newNode(val);
	newNode->Next = topPtr;
	topPtr = newNode;
	return true;
}
```
### pop()

```cpp
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
```
### peek()

```cpp
template<typename T>
inline T LinkedStack<T>::peek() const
{
	if (!isEmpty())
	{
		return topPtr->value;
	}
	return 0;
}
```
### isEmpty()

```cpp
template<typename T>
inline bool LinkedStack<T>::isEmpty() const
{
    return topPtr == nullptr;
}
```
### display()

```cpp
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
```
### count()

```cpp
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
```




-----

## ArrayStack

## class:

```cpp
#pragma once
#include "StackInterface.h"
#include <cassert> 
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

```

## Functions implemented :
- [push()](#push())
- [pop()](#pop())
- [peek()](#peek())
- [isEmpty()](#isEmpty())
- [display()](#display())
- [count()](#count())

### push()

```cpp
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
```
### pop()

```cpp
template<typename T>
inline bool ArrayStack<T>::pop()
{
	if (top == -1)
	{
		throw out_of_range("\n can not pop an empty stack\n");
	}
	else
	{
		top--;
		return true;
	}
}

```
### peek()

```cpp
template<typename T>
inline T ArrayStack<T>::peek() const
{
	assert (!isEmpty()) //enforces the precondition
    //If the stack is empty, assert will issue an error message and halt execution.
	return items[top];
}
```
### isEmpty()

```cpp
template<typename T>
inline bool ArrayStack<T>::isEmpty() const
{
	return top < 0;
}

```
### display()

```cpp
template<typename T>
inline void ArrayStack<T>::display()
{
	for (int i = 0; i <= top; i++)
	{
		cout << items[i] << endl;
	}
}
```
### count()
```cpp
template<typename T>
inline int ArrayStack<T>::count()
{
	return (top + 1);
}
```

-----
## ArrayStack vs LinkedStack
- The array-based implementation is a reasonable choice if the number of items in the stack does not exceed the fi xed size of
the array. For example, when we read and correct an input line, if the system allows a
line length of only 80 characters, you reasonably could use a statically allocated array
to represent the stack. For stacks that might be large, but often are not, the array-based
implementation will waste storage. In that case, the link-based implementation is a better choice.

-----

## Applications using Stack ADT
- [Converting decimal to binary](#Converting-decimal-to-binary)
- [Evaluating postfix expressions](#Evaluating-postfix-expressions)
- [Parsing](#Parsing)
- [Backtracking](#Backtracking) </br>

## Converting decimal to binary

```cpp
void Decimal2Binary(int num)
{
	stack<int> s;
	do
	{
		s.push(num % 2);
		s /= 2;
	}
        while (num);
	while (!s.isEmpty())
	{
		s.pop();
	}
}
```

## Evaluating postfix expressions
In infix notation, operations require parentheses to enforce precedence:
```
(3 + 4) * 5
```
In postfix notation, the same expression is written as:
```
3 4 + 5 *
```

### **Step-by-Step Evaluation**
Given the postfix expression: `3 4 + 5 *`
1. **Push** `3` onto the stack.
2. **Push** `4` onto the stack.
3. **Encounter `+`**, pop `3` and `4`, compute `3 + 4 = 7`, and push `7`.
4. **Push** `5` onto the stack.
5. **Encounter `*`**, pop `7` and `5`, compute `7 * 5 = 35`, and push `35`.
6. The final result in the stack is `35`.

### Evaluating postfix expressions

```cpp
int evaluatePostfix(const string &expression) {
    stack<int> st;

    for (char ch : expression) {
        if (isdigit(ch)) {
            st.push(ch - '0'); // Convert char to int and push
        } else if (ch == ' ') {
            continue; // Ignore spaces
        } else {
            // Pop two operands
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            // Perform operation
            switch (ch) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
            }
        }
    }

    return st.top(); // Final result
}
```
## Parsing
You can check whether a string contains balanced braces by traversing it from left to
right. As you move from left to right, you match each successive close brace “}” with the most
recently encountered unmatched open brace “{”; that is, the “{” must be to the left of the current “}”.
The braces are balanced if: </br>
- 1. Each time you encounter a “}”, it matches an already encountered “{”.
- 2. When you reach the end of the string, you have matched each “{”. 

```cpp
bool checkBraces(string s)
{
	bool isBalanced = true;
	int length = s.length();
	stack<char> Astack; 
	for (int i = 0; i < length; i++)
	{
		if (s[i] == '{')
			Astack.push('{');
		else if (s[i] == '}')
		{
			if (!Astack.isEmpty())
				Astack.pop();
			else
				isBalanced = false;
		}

		return isBalanced && Astack.isEmpty();
	}
}
```

## Backtracking

-----

## Useful videos
- [Stacks - Neso Academy](https://youtube.com/playlist?list=PLBlnK6fEyqRgWh1emltdMOz8O2m5X3YYn&si=kyy7kaNoGDbh42l-)

-----
## Useful Articles
- [Introduction to Stack – Data Structure and Algorithm GeeksForGeeks Tutorials](https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/?ref=header_search)
- [Stack in C++ STL](https://www.geeksforgeeks.org/stack-in-cpp-stl/)

-----
## For practice
- [LeetCode problems](https://leetcode.com/tag/stack/)
- [Top 50 Problems on Stack Data Structure asked in SDE Interviews](https://www.geeksforgeeks.org/top-50-problems-on-stack-data-structure-asked-in-interviews/?ref=header_search)


----










