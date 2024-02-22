#include "Node.h"
#include <iostream>
#include <stdexcept>

using std::cout, std::endl;

/*
This implementation assumes:
 -  node class with a defualt next pointer = nullptr
 -  Node class have a copy constructor
*/

template <typename T>
class LinkedList
{
    // Note: You can have a size variable for getting the size directly
    //       without calculating it everytime but would take more memory
    // Note: You can have a tail pointer to point to the last Node to make it
    //       easier to add to the end of the list but would also take more memory

    Node<T> *headPtr;

  public:
    LinkedList()
        : headPtr(nullptr){};

    LinkedList(const LinkedList<T> &aList)
    {
        Node<T> *otherHead = aList.headPtr; // A tmp pointer for the head of the other list

        // This head will always be assigned to the other list's head
        headPtr = otherHead;
        if (otherHead == nullptr) // Check if the list finished
            return;

        headPtr = new Node<T>(otherHead->item); // Copy the first node
        otherHead = otherHead->next;            // Advance the pointer to start from the second node
        Node<T> tmpHead = headPtr;              // A tmp pointer for this head

        // Copying the remaining nodes
        while (otherHead)
        {
            // Creates and addes the new node
            tmpHead->next = new Node<T>(otherHead->item); // Node having a copy constructor

            // Advance both this tmp head and other list tmp head
            tmpHead = tmpHead->next;
            otherHead = otherHead->next;
        }
    };

    int getSize() const
    {
        int size = 0;
        Node<T> *tmpHead = headPtr;
        while (tmpHead)
        {
            tmpHead = tmpHead->next;
            ++size; // Prefix is better here as it takes less memory
        }
        return size;
    };

    bool isEmpty() const
    {
        return bool(headPtr);
    };

    bool insertFront(const T &item)
    {
        Node<T> *newItem = new Node<T>(item);
        newItem->next = headPtr;
        headPtr = newItem;
        return true;
    };

    bool insertEnd(const T &item)
    {
        // If the list is empty we can inseart in the beginning directly
        if (headPtr == nullptr)
        {
            insertFront(item);
            return true;
        }

        Node<T> *newItem = new Node<T>(item);
        Node<T> *tail = headPtr;
        while (tail->next)
            tail = tail->next;
        tail->next = newItem;
        return true;
    };

    bool remove(const T &item)
    {
        if (headPtr == nullptr)
            throw std::out_of_range("can not remove from an empty list");

        // Checks the first node
        if (headPtr->item == item)
        {
            Node<T> *newHead = headPtr->next;
            delete headPtr;
            headPtr = newHead;
            return true;
        }

        // Check if the list have only one node
        if (headPtr->next == nullptr)
            return false;

        Node<T> *prevPtr = headPtr;
        Node<T> *currentPtr = headPtr->next;

        while (currentPtr)
        {
            if (currentPtr->item == item)
            {
                prevPtr->next = currentPtr->next;
                delete currentPtr;
                return true;
            }
            prevPtr = prevPtr->next;
            currentPtr = currentPtr->next;
        }
        return false; // If item not found
    };

    bool removeByPos(int index)
    {
        if (headPtr == nullptr)
            throw std::out_of_range("can not remove from an empty list");

        if (index == 0)
        {
            Node<T> *newHead = headPtr->next;
            delete headPtr;
            headPtr = newHead;
            return true;
        }

        // Check if the list have only one node
        if (headPtr->next == nullptr)
            return false;

        int i = 1;
        Node<T> *prevPtr = headPtr;
        Node<T> *currentPtr = headPtr->next;
        while (i < index && currentPtr)
        {
            currentPtr = currentPtr->next;
            prevPtr = prevPtr->next;
            ++i;
        }
        // Check if the loop ended early
        if (i < index)
            return false;

        prevPtr->next = currentPtr->next;
        delete currentPtr;
        return true;
    };

    void reverse()
    {

        // This code acually handles the edge cases of empty list
        // and case of list with one item
        Node<T> *prevPtr = nullptr;
        Node<T> *currentPtr = headPtr;
        Node<T> *nextPtr;
        while (currentPtr)
        {
            nextPtr = currentPtr->next;
            currentPtr->next = prevPtr;
            prevPtr = currentPtr;
            currentPtr = nextPtr;
        }
        headPtr = prevPtr;
    };

    void printList()
    {
        cout << "\nPrinting List content:\n";
        Node<T> *currentPtr = headPtr;
        while (currentPtr)
        {
            cout << "[ " << currentPtr->item << " ]-->";
            currentPtr = currentPtr->next;
        }
        cout << "NULL\n";
    }
};