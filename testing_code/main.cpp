#include "LinkedList.h"
#include <iostream>
using std::cout, std::endl;

int main()
{
    LinkedList<int> List1;

    for (int i = 0; i < 5; ++i)
        List1.insertEnd(2*i);

    List1.printList();

    cout << "\n\n-------- Insert 20 at the front --------\n";
    int x = 20;
    List1.insertFront(x);
    List1.printList();

    cout << "\n\n-------- Insert 30 at the end --------\n";
    x = 30;
    List1.insertEnd(x);
    List1.printList();

    cout << "\n\n-------- Size of the list --------\n";
    cout << "\nSize = " << List1.getSize() << endl;

    cout << "\n\n-------- Remove number 4 from the list --------\n";
    x = 4;
    List1.remove(x);
    List1.printList();

    cout << "\n\n-------- Remove item at index 3 from the list --------\n";
    x = 3;
    List1.removeByPos(x);
    List1.printList();

    cout << "\n\n-------- Reversing the list --------\n";
    List1.reverse();
    List1.printList();

    return 0;
}