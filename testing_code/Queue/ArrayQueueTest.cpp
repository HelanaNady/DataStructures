#include <iostream>
#include "ArrayQueue.h"

int main()
{

    ArrayQueue <int> q(5);
    for (int i = 0; i < 4; i++)
        q.enqueue(i);

    q.printQueue();

    std::cout << "\n\n-------- enqueue 10 --------\n";
    int x = 10;
    q.enqueue(x);
    q.printQueue();

    std::cout << "\n\n-------- peekFront ---------\n";
    std::cout << q.peekFront() << std::endl;

    std::cout << "\n\n-------- is Empty? --------\n";
    if (q.isEmpty())
        std::cout << "queue is empty \n";
    else
        std::cout << "queue is not empty \n";

    std::cout << "\n\n---- dequeue 2 items ------\n";
    q.dequeue();
    q.dequeue();
    q.printQueue();

    std::cout << "\n\n-------- peekFront ---------\n";
    std::cout << q.peekFront() << std::endl;

    q.dequeue();
    q.enqueue(99);
    q.enqueue(44);
    q.enqueue(33);
    q.printQueue();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    std::cout << "\n\n-------- is Empty? --------\n";
    if (q.isEmpty())
        std::cout << "queue is empty \n";
    else
        std::cout << "queue is not empty \n";
    return 0;
}
