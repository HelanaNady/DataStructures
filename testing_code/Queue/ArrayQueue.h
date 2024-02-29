#pragma once
#include <iostream>
#include "QueueInterface.h"

// circular array based implementation 
// back index here points to the location after the last item added  

template <typename T>
class ArrayQueue : public QueueInterface<T>
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
    void printQueue() const;
    ~ArrayQueue();
};


template<typename T>
ArrayQueue<T>::ArrayQueue(int size) : front(0), back(0), size(size)
{
    items = new T[size + 1];
}


template<typename T>
bool ArrayQueue<T>::isEmpty() const
{
    return front == back;
}

template<typename T>
bool ArrayQueue<T>::enqueue(const T& item)
{

    if (front == (back + 1) % (size + 1))
        throw std::out_of_range("queue is full can not add more items");

    items[back] = item;
    back = (back + 1) % (size + 1);

    return true;
}

// 0 1 2 3    4 

template <typename T>
bool ArrayQueue<T>::dequeue()
{
    if (isEmpty())
        throw std::out_of_range("can not dequeue from an empty queue");

    front = (front + 1) % (size + 1);

    return true;
}

template <typename T>
T ArrayQueue<T> ::peekFront()
{
    if (isEmpty())
        throw std::out_of_range("can not dequeue from an empty queue");

    return items[front];
}

template<typename T>
void ArrayQueue<T>::printQueue() const
{
    std::cout << "\nPrinting Queue Content \n";
    int i = front;
    while (i != back)
    {
        std::cout << items[i] << " ";
        i = (i + 1) % (size + 1);
    }

    std::cout << "\n";
}


template<typename T>
ArrayQueue<T>::~ArrayQueue()
{
    delete[] items;
}

