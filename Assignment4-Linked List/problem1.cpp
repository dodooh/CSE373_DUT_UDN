#include <iostream>

using namespace std;
class NumberLinkedList {
    private:
    // Declare a structure for the list
        struct ListNode
        {
        int value; // The value in this node
        struct ListNode *next; // To point to the next node
        };
        ListNode *head; // List head pointer
    public:
        // Constructor
        NumberLinkedList();
        // Destructor
        ~NumberLinkedList();
        // Linked list operations
        void insertFirst(int);
        void insertLast(int);
        void deleteFirst();
        void deleteLast();
        int length();
        void deleteNode(int);
        void displayList() const;
};
NumberLinkedList::NumberLinkedList()
{   head = nullptr;}
NumberLinkedList::~NumberLinkedList()
{
    ListNode* current = head;
    ListNode* next;
    while (current)
    {
        next = current->next;
        delete current;
        current = next;
    }
}
void NumberLinkedList::insertFirst(int item)
{
    ListNode *newNode = new ListNode;
    newNode->value    = item;
    newNode->next     = head;
    head              = newNode;
}
void NumberLinkedList::insertLast(int item)
{
    ListNode *newNode = new ListNode;
    newNode->value    = item;
    newNode->next     = nullptr;
    ListNode *current = head;
    if (current == nullptr)
    {
        head = newNode;
        return;
    }
    while (current->next)
        current = current->next;
    current->next = newNode;
}
void NumberLinkedList::deleteFirst()
{
    if (head == nullptr)
        return;
    ListNode *temp = head;
    head     = temp->next;
}
void NumberLinkedList::deleteLast()
{
    if (head == nullptr)
        return;
    if (head->next == nullptr)
    {
        free(head->next);
        return;
    }
    ListNode *temp = head;
    while (temp->next->next)
        temp = temp->next;
    temp->next = nullptr;
}
int NumberLinkedList::length()
{
    int c = 0;
    ListNode *current = head;
    while (current)
    {
        c++;
        current = current->next;
    }
    return c;
}
void NumberLinkedList::deleteNode(int pos)
{
    if (pos == 0)
    {
        deleteFirst();
        return;
    }
    ListNode *current = head;
    for (int i = 0; i < pos-1 && current != nullptr ; ++i)
    {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr)
    {
        cout << "There is no node at position " << pos << endl;
        return;
    }
    ListNode *posNext = current->next->next;
    current->next = posNext;
}
void NumberLinkedList::displayList() const
{
    ListNode *current = head;
    while (current)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}
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
