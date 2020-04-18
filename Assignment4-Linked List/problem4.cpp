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
        NumberLinkedList& operator=( NumberLinkedList );
        int size();
        void push_front(int item);
        void makeEmpty();
        bool is_a_set();
        bool is_already_existen(int ,Node ,Node);
        bool is_subset_of(NumberLinkedList );
        NumberLinkedList intersection(NumberLinkedList , NumberLinkedList );
        NumberLinkedList union_of_two_sets( NumberLinkedList , NumberLinkedList );
};
NumberLinkedList& NumberLinkedList::operator=(NumberLinkedList rhs)
{
    if (this != &rhs){
        makeEmpty();
        Node this_cur = zeroth();
        Node rhs_cur  = rhs.first();
        while  (rhs_cur)
        {
            this_cur = this_cur->tail() = cons(rhs_cur->item(), NULL);
            rhs_cur  = rhs_cur->tail();
        }
    }
    return *this;
}
void NumberLinkedList::makeEmpty(){
    while(!isEmpty()){
        Node tmp = first()->tail();
        delete first();
        dummyHead->tail() = tmp;
    }
}

void NumberLinkedList::push_front(const int item){
    dummyHead->tail() = cons(item, first());
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
bool NumberLinkedList::is_subset_of( NumberLinkedList fatherSet)
{
    Node cur = first();
    while( cur)
    {
        if (!is_already_existen( cur->item(), fatherSet.first(), NULL))
            return false;
        cur = cur->tail();
    }
    return true;
}

bool NumberLinkedList::is_already_existen(int candi, Node from, Node to)
{
    Node cur = from;
    while ( cur != to)
    {
        if( cur->item() == candi)
            return true;
        cur = cur->tail();
    }
    return false;
}

bool NumberLinkedList::is_a_set()
{
    Node cur = first();
    while( cur)
    {
        if (is_already_existen( cur->item(), first(),cur))
            return false;
        cur = cur->tail();
    }
    return true;

}

NumberLinkedList NumberLinkedList::union_of_two_sets( NumberLinkedList p1, NumberLinkedList p2)
{
    makeEmpty();
    if ( p1.isEmpty() )
        return p2;
    if ( p2.isEmpty() )
        return p1;
    NumberLinkedList intersection_of_two_set = intersection(p1,p2);
    Node cur = p1.first();
    Node this_cur = zeroth();
    while (cur)
    {
        this_cur = this_cur->tail() = cons(cur->item());
        cur = cur->tail();
    }
    cur = p2.first();
    while (cur)
    {
        if (!is_already_existen(cur->item(),intersection_of_two_set.first(),NULL))
                this_cur = this_cur->tail() = cons(cur->item());
        cur = cur->tail();
    }
    return *this;
}

NumberLinkedList NumberLinkedList::intersection( NumberLinkedList p1, NumberLinkedList p2)
{
    makeEmpty();
    if ( p1.isEmpty() || p2.isEmpty())
        return *this;
    Node p1_cur   = p1.first();
    Node this_cur = zeroth();
    while (p1_cur)
    {
        int candi = p1_cur->item();
        if (is_already_existen(candi, p2.first(), NULL))
            this_cur = this_cur->tail() = cons(candi);
        p1_cur = p1_cur->tail();
    }
    return *this;
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
    std::cout << "Print the linked list p1: "<< std::endl;
    print(p1);
    NumberLinkedList p2;
    for (int i = 5 ; i >= 1; --i)
    {
        p2.push_front(i*2);
    }
    p2.push_front(5);
    std::cout << "Print the linked list p2: "<< std::endl;
    print(p2);
    NumberLinkedList p3;
    p3.push_front(7);
    p3.push_front(9);
    p3.push_front(11);
    std::cout << "Print the linked list p3: "<< std::endl;
    print(p3);
    //Check if a linked list is a set
    std::cout <<"-------Check if a linked list is a set------" << std::endl;
    if (p1.is_a_set())
        std::cout << "p1 is a set."<< std::endl;
    else
        std::cout << "p1 is not a set."<< std::endl;
    //Check if a set is a subset of another set
    std::cout <<"-------Check if a set is a subset of another set------" << std::endl;
    if (p2.is_subset_of(p1))
        std::cout << "p2 is a subset of p1."<< std::endl;
    else
        std::cout << "p2 is not a subset of p1."<< std::endl;
    //Intersection of two sets
    std::cout <<"-------Intersection of two sets------" << std::endl;
    NumberLinkedList pIntersection;
    pIntersection.intersection(p1,p2);
    std::cout << "Print the intersection of 2 sets p1,p2: "<< std::endl;
    print(pIntersection);
    pIntersection.intersection(p1,p3);
    std::cout << "Print the intersection of 2 sets p1,p3: "<< std::endl;
    print(pIntersection);
    //Union of two sets
    std::cout <<"-------Union of two sets------" << std::endl;
    NumberLinkedList pUnion;
    pUnion.union_of_two_sets(p1,p2);
    std::cout << "Print the Union of 2 sets p1,p2: "<< std::endl;
    print(pUnion);
    pUnion.union_of_two_sets(p1,p3);
    std::cout << "Print the Union of 2 sets p1,p3: "<< std::endl;
    print(pUnion);
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
