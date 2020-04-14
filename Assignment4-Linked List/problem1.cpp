#include <iostream>
#include <NumberLinkedList.h>
using namespace std;

int main()
{
    NumberLinkedList ll;
    ll.insertFirst(5);
    ll.insertFirst(4);
    ll.insertFirst(3);
    ll.insertFirst(2);
    ll.insertFirst(1);
    ll.displayList();
    ll.insertLast(6);
    ll.insertLast(7);
    ll.displayList();
    ll.deleteFirst();
    ll.deleteLast();
    ll.displayList();
    cout << ll.length() << endl;
    ll.deleteNode(5);
    ll.displayList();
    cout << ll.length();
    return 0;
}
