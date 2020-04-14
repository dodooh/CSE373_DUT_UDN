#include <iostream>
#include <time.h>
/*STRUCT Node
Implemented */
typedef struct ListNode* Node;
struct ListNode{
    private:
        int data;
        Node next;
    public:
        ListNode(const int& e = 0,Node p = NULL) : data(e),next(p){};
        int item() const{
            return data;
        }
        Node &tail(){
            return next;
        }
};

typedef ListNode* Node;
/*Class NUMBERLINKEDLIST*/
const Node emptyList = NULL;

class NumberLinkedList{
    private:
        Node dummyHead;
    public:
        NumberLinkedList(){
            dummyHead = new ListNode();
        }
        ~NumberLinkedList(){

        };
        Node zeroth(){
            return dummyHead;
        }
        Node& first(){
            return dummyHead->tail();
        }
        bool isEmpty(){
            return (first() == emptyList);
        };
        Node cons(int e = 0, Node p = NULL){
            return new ListNode(e,p);
        }
        int size();
        void push_front(int item);
        void insertNumber(int );
        void insert(int ,Node& );
};
void NumberLinkedList::insert(int item,Node& p){
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
	 Node ptr = first();

	 while ( ptr != 0 ) {
	 	 ++count;
	 	 ptr = ptr->tail();
	 }
	 return count;
}

void print(NumberLinkedList );
void sortList(NumberLinkedList );
Node mergeSort(Node& ,int );
Node merge(Node ,Node);

int main()
{
    srand(time(NULL));
    std::cout <<"------------------INITIALIZE------------------" << std::endl;
    //Create linked list which holds ten random integers disorderly.
    NumberLinkedList p1;
    for (int i = 0 ; i < 10; ++i)
    {
        int num = rand() % 1000 + 1;
        p1.push_front(num);
    }
    std::cout << "Print the list p1 before sorting: "<< std::endl;
    print(p1);
    std::cout << "Size: "<< p1.size() << std::endl;
    sortList(p1);
    std::cout << "Print the list p1 after sorting: "<< std::endl;
    print(p1);
    std::cout << "Size: "<< p1.size() << std::endl;
    std::cout << "Input the number you want to insert: "<< std::endl;
    int n;
    std::cin >> n;
    p1.insertNumber(n);
    std::cout << "Print the list p1 after insert ("<< n << "): "<< std::endl;
    print(p1);
    std::cout << "Size: "<< p1.size() << std::endl;

    return 0;
}

void sortList(NumberLinkedList p){
    p.first() = mergeSort(p.first(),p.size());
}
Node mergeSort(Node& L,int n){
    if(n == 0)
    {
        return NULL;
    }
    else if(n == 1)
    {
        Node p = L;
        L = L->tail();
        p->tail() = NULL;
        return p;
    }
    else
    {
        int  m = n/2;
        Node A = mergeSort(L, m);
        Node B = mergeSort(L, n-m);
        return merge(A,B);
    }
}
Node merge(Node A,Node B)
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
void print(NumberLinkedList p){
    Node cur = p.first();
    while (cur)
    {
        std::cout<< cur->item() <<"->";
        cur = cur->tail();
    }
    std::cout<<"NULL"<<std::endl;
}
bool equal(NumberLinkedList p1, NumberLinkedList p2)
{
    if (p1.size() != p2.size())
        return false;
    Node cur1 = p1.first();
    Node cur2 = p2.first();
    while (cur1)
    {
        if (cur1->item() != cur2->item())
            return false;
        cur1 = cur1->tail();
        cur2 = cur2->tail();
    }
    return true;
}
