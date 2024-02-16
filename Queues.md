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

### linked list queue

### isEmpty

```cpp
template <typename ItemType>
bool LinkedQueue<ItemType>::isEmpty() const
{
    if (frontPtr == nullptr && backPtr == nullptr)
        return true;
    return false;
}
```

### enqueue

```cpp
template <typename ItemType>
bool LinkedQueue<ItemType>::enqueue(ItemType newEntry)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

    //if node inserted is the first one
    if (frontPtr == nullptr)
    {
        frontPtr = newNodePtr;
        backPtr = frontPtr;
        frontPtr->setNext(nullptr);
    }

    else
    {
        backPtr->setNext(newNodePtr);
        backPtr = newNodePtr;
    }
    return true;
}
```

### dequeue

```cpp
template <typename ItemType>
bool LinkedQueue<ItemType>::dequeue()
{
    if (frontPtr == nullptr)
        return false;

    Node<ItemType>* temp = frontPtr->getNext();
    delete frontPtr;
    frontPtr = temp;

    if (frontPtr == nullptr) 
        backPtr = nullptr;

    return true;
}
```


----

<div align="center">
  <img src="https://github.com/HelanaNady/DataStructure/assets/84867341/9c7e87d4-50fc-4f7c-b24e-12e4618782f3" alt="Queue" width="80%">
</div>


![image](https://github.com/HelanaNady/DataStructure/assets/84867341/1931798a-c0cd-4963-98d6-0ea2fe88c726)
