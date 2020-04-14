#include <iostream>
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
        Node& tail(){
            return next;
        }
};
/*Class NUMBERLINKEDLIST*/

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
        Node first(){
            return dummyHead->tail();
        }
        bool isEmpty(){
            return (first() == NULL);
        };
        Node cons(int e = 0, Node p = NULL){
            return new ListNode(e,p);
        }
        int size();
        void push_front(int item);
        void empty();
        NumberLinkedList merge(NumberLinkedList p1,NumberLinkedList p2);
        NumberLinkedList concatenate(NumberLinkedList p1,NumberLinkedList p2);
};
void NumberLinkedList::empty(){
    while(!isEmpty()){
        Node tmp = first()->tail();
        delete first();
        dummyHead->tail() = tmp;
    }
}
NumberLinkedList NumberLinkedList::concatenate(NumberLinkedList p1,NumberLinkedList p2)
{
    empty();
    Node cur1 = p1.first();
    Node cur2 = p2.first();
    Node this_cur = zeroth();
    while (cur1)
    {
        this_cur = this_cur->tail() = cons(cur1->item());
        cur1 = cur1->tail();
    }
    while (cur2)
    {
        this_cur = this_cur->tail() = cons(cur2->item());
        cur2 = cur2->tail();
    }
    return *this;
}
NumberLinkedList NumberLinkedList::merge(NumberLinkedList p1, NumberLinkedList p2){
    empty();
    Node cur1 = p1.first();
    Node cur2 = p2.first();
    Node this_cur = zeroth();
    while (cur1 || cur2){
        if (!cur1)
        {
            this_cur = this_cur->tail() = cons(cur2->item());
            cur2 = cur2->tail();
        }else
        if (!cur2)
        {
            this_cur = this_cur->tail() = cons(cur1->item());
            cur1 = cur1->tail();
        }else
        if (cur1->item() > cur2->item())
        {
            this_cur = this_cur->tail() = cons(cur2->item());
            cur2 = cur2->tail();
        }else
        {
            this_cur = this_cur->tail() = cons(cur1->item());
            cur1 = cur1->tail();
        }
    }
    return *this;
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

bool equal(NumberLinkedList , NumberLinkedList );
void print(NumberLinkedList );

int main()
{
    std::cout <<"------------------INITIALIZE------------------" << std::endl;
    NumberLinkedList p1;
    for (int i = 10 ; i >= 1; --i)
    {
        p1.push_front(i*2);
    }
    std::cout << "Print the list p1: "<< std::endl;
    print(p1);
    std::cout << std::endl;
    NumberLinkedList p2;
    for (int i = 19 ; i >= 1; i-=2)
    {
        p2.push_front(i);
    }
    std::cout << "Print the list p2: "<< std::endl;
    print(p2);
    NumberLinkedList p3;
    for (int i = 10 ; i >= 1; --i)
    {
        p3.push_front(i*2);
    }
    std::cout << std::endl;
    std::cout << "Print the list p3: "<< std::endl;
    print(p3);
    //MERGE
    std::cout <<"------------------MERGE-FUNCTION-----------------" << std::endl;
    NumberLinkedList p4;
    p4.merge(p1,p2);
    std::cout << "Print the list p4:(merge p1 & p2) "<< std::endl;
    print(p4);
    std::cout << std::endl;
    std::cout << "Print the list p1: "<< std::endl;
    print(p1);
    std::cout << std::endl;
    std::cout << "Print the list p2: "<< std::endl;
    print(p2);
    //CONCATENATE
    std::cout <<"-----------------CONCATENATE-FUNCTION------------" << std::endl;
    NumberLinkedList p5;
    p5.concatenate(p1,p2);
    std::cout << "Print the list p5:(concatenate p1->p2) "<< std::endl;
    print(p5);
    p5.concatenate(p2,p1);
    std::cout << std::endl;
    std::cout << "Print the list p5:(concatenate p2->p1) "<< std::endl;
    print(p5);
      //EQUAL
    std::cout <<"------------------EQUAL-FUNCTION------------------" << std::endl;
    if (equal(p1,p2))
     std::cout <<"p1 is equal p2" << std::endl;
    else
     std::cout <<"p1 is not equal p2" << std::endl;
    if (equal(p1,p3))
     std::cout <<"p1 is equal p3" << std::endl;
    else
     std::cout <<"p1 is not equal p3" << std::endl;

    return 0;
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
