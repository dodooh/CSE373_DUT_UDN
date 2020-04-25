#include <iostream>
#include <time.h>
/*STRUCT Node
Implemented */

struct ListNode{
    private:
        int data;
        ListNode* next;
    public:
        ListNode(const int& e = 0,ListNode* p = NULL) : data(e),next(p){};
        int item() const{
            return data;
        }
        ListNode* &tail(){
            return next;
        }
};


/*Class NUMBERLINKEDLIST*/
const ListNode* emptyList = NULL;

class NumberLinkedList{
    private:
        ListNode* dummyHead;
    public:
        NumberLinkedList(){
            dummyHead = new ListNode();
        }
        ~NumberLinkedList(){

        };
        ListNode* zeroth(){
            return dummyHead;
        }
        ListNode*& first(){
            return dummyHead->tail();
        }
        bool isEmpty(){
            return (first() == emptyList);
        };
        ListNode* cons(int e = 0, ListNode* p = NULL){
            return new ListNode(e,p);
        }
        int size();
        void push_front(int item);
        void insertNumber(int );
        void insert(int ,ListNode*& );
};
void NumberLinkedList::insert(int item,ListNode*& p){
    if(p == NULL || item <= p->item())
    {
      p = cons(item, p);
    }
    else
    {
      insert(item, p->tail());
    }
}
void NumberLinkedList::insertNumber(int item){
    insert(item,first());
}

void NumberLinkedList::push_front(const int item){
    dummyHead->tail() = cons(item,first());
}
int NumberLinkedList::size() {
	 int count = 0;
	 ListNode* ptr = first();

	 while ( ptr != 0 ) {
	 	 ++count;
	 	 ptr = ptr->tail();
	 }
	 return count;
}
ListNode* merge(ListNode* A,ListNode* B)
{
    if(A == NULL)
    {
        return B;
    }
    else if(B == NULL)
    {
        return A;
    }
    else if(A->item() < B->item())
    {
        A->tail() = merge(A->tail(), B);
        return A;
    }
    else
    {
        B->tail() = merge(A, B->tail());
        return B;
    }
}

ListNode* mergeSort(ListNode*& L,int n){
    if(n == 0)
    {
        return NULL;
    }
    else if(n == 1)
    {
        ListNode* p = L;
        L = L->tail();
        p->tail() = NULL;
        return p;
    }
    else
    {
        int  m = n/2;
        ListNode* A = mergeSort(L, m);
        ListNode* B = mergeSort(L, n-m);
        return merge(A,B);
    }
}
void sortList(NumberLinkedList p){
    p.first() = mergeSort(p.first(),p.size());
}

void print(NumberLinkedList p){
    ListNode* cur = p.first();
    while (cur)
    {
        std::cout<< cur->item() <<" ";
        cur = cur->tail();
    }
    std::cout<<std::endl;
}
int main()
{
    srand(time(NULL));

    NumberLinkedList obj1;
    for (int i = 0 ; i < 15; ++i)
    {
        int num = rand() % 100 + 1;
        obj1.push_front(num);
    }
    std::cout << "The list before sorting: "<< std::endl;
    print(obj1);
    sortList(obj1);
    std::cout << "The list after sorting: "<< std::endl;
    print(obj1);
    std::cout << "Input the number you want to insert: "<< std::endl;
    int n;
    std::cin >> n;
    obj1.insertNumber(n);
    std::cout << "The list after add and sort: "<< std::endl;
    print(obj1);
    return 0;
}

bool equal(NumberLinkedList p1, NumberLinkedList p2)
{
    if (p1.size() != p2.size())
        return false;
    ListNode* cur1 = p1.first();
    ListNode* cur2 = p2.first();
    while (cur1)
    {
        if (cur1->item() != cur2->item())
            return false;
        cur1 = cur1->tail();
        cur2 = cur2->tail();
    }
    return true;
}
