#pragma once
#include <iostream>
#include "QueueInterface.h"

template <typename T>
class Node
{
public:
    T item;
    Node<T>* next;

    Node() : item(0), next(nullptr) { }
    Node(T value) : item(value), next(nullptr) { }
};

template <typename T>
class LinkedQueue : public QueueInterface<T>
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
    void printQueue() const;
    ~LinkedQueue();
};

template<typename T>
LinkedQueue<T>::LinkedQueue() : frontPtr(nullptr), backPtr(nullptr)
{ }

template<typename T>
bool LinkedQueue<T>::isEmpty() const
{
    return (!frontPtr && !backPtr);
}

template <typename T>
bool LinkedQueue<T>::enqueue(const T& item)
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

template <typename T>
bool LinkedQueue<T>::dequeue()
{
    if (isEmpty())
        throw std::out_of_range("can not dequeue from an empty queue");

    Node<T>* nodeToDeletePtr = frontPtr;
    frontPtr = frontPtr->next;
    delete nodeToDeletePtr;

    // if list becomes empty set back pointer to null
    if (frontPtr == nullptr)
        backPtr = nullptr;

    return true;
}

template <typename T>
T LinkedQueue<T>::peekFront()
{
    // Enforce precondition 
    if (isEmpty())
        throw std::out_of_range("peekFront() called with empty queue");
    return frontPtr->item;
}

template<typename T>
void LinkedQueue<T>::printQueue() const
{
    std::cout << "\nPrinting Queue Content \n";
    Node<T>* ptr = frontPtr;
    while (ptr)
    {
        std::cout << ptr->item << " ";
        ptr = ptr->next;
    }
        
}

template<typename T>
LinkedQueue<T>::~LinkedQueue()
{
    Node<T>* ptr = frontPtr;
    while (frontPtr)
        dequeue();
}

