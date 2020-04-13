/***************************************************
        Problem 2:MERGE,CONCATENATE & EQUAL
    @author: NGUYEN_TRAN_THANH_NGHIA-15ECE2
****************************************************/
#include <iostream>
/*STRUCT Node*/
template<class T> struct Node{
    T data;
    Node *next;
    Node(const T& e = T(), Node *p = NULL) : data(e),next(p){};
    //{std::cout<< std::endl << "Destructor Node ";};
};

/*Class NUMBERLINKEDLIST*/

template<class T> class NumberLinkedList{
private:
    Node<T> *dummyHead;
public:
    NumberLinkedList(){
    dummyHead = new Node<T>(T(), NULL);
    }
    ~NumberLinkedList(){
//        makeEmpty();
//        delete dummyHead;
    //std::cout<< std::endl << "Destrutor LL" ;
    };
    void insert(const T&, Node<T>* );
    bool isEmpty();
    Node<T> *zeroth();
    Node<T> *first() ;
    void remove(const T&);
    Node<T> *findPrevious(const T&);
    void makeEmpty();
    void printList();
    NumberLinkedList merge(NumberLinkedList &,NumberLinkedList &);
    NumberLinkedList concatenate2Lists(NumberLinkedList &,NumberLinkedList &);
    int length() ;
    bool equal(NumberLinkedList &);
};
template<class T>
bool NumberLinkedList<T>::equal(NumberLinkedList &that){
    if (length() != that.length())
        return false;
    Node<T> *this_cur = first();
    Node<T> *that_cur = that.first();
    while (this_cur)
    {
        if (this_cur->data != that_cur->data)
            return false;
        this_cur = this_cur->next;
        that_cur = that_cur->next;
    }
    return true;
}
template<class T>
int NumberLinkedList<T>::length(){
    Node<T>* cur = zeroth();
    int c = 0;
    while (cur)
    {
        c++;
        cur = cur->next;
    }
    return c;
}
template<class T>
void NumberLinkedList<T>::remove(const T& val){
    Node<T> *prev_ptr = findPrevious(val);
    if (prev_ptr)
    {
        Node<T> *tmp = prev_ptr->next;
        prev_ptr->next = prev_ptr->next->next;
        delete (tmp);
    }
}
template<class T>
Node<T>* NumberLinkedList<T>::findPrevious(const T& val){
    Node<T>* cur = zeroth();
    while (cur->next)
    {
        if (cur->next->data == val)
            return cur;
        cur = cur->next;
    }
    return NULL;
}
template<class T>
NumberLinkedList<T> NumberLinkedList<T>::concatenate2Lists(NumberLinkedList &p1,NumberLinkedList &p2)\
{
    makeEmpty();
    Node<T>* cur1     = p1.first();
    Node<T>* cur2     = p2.first();
    Node<T>* this_cur = zeroth();
    while (cur1)
    {
        insert(cur1->data,this_cur);
        cur1     = cur1->next;
        this_cur = this_cur->next;
    }
    while (cur2)
    {
        insert(cur2->data,this_cur);
        cur2     = cur2->next;
        this_cur = this_cur->next;
    }
    return *this;
}
template<class T>
NumberLinkedList<T> NumberLinkedList<T>::merge(NumberLinkedList &p1,NumberLinkedList &p2)
{

    makeEmpty();
    Node<T>* cur1     = p1.first();
    Node<T>* cur2     = p2.first();
    Node<T>* this_cur = zeroth();
    while (cur1 != NULL || cur2 != NULL){
        if (cur2 == NULL){
            insert(cur1->data,this_cur);
            cur1 = cur1->next;
        }
        else if(cur1 == NULL){
            insert(cur2->data,this_cur);
            cur2 = cur2->next;
        }
        else if(cur1->data >= cur2->data){
            insert(cur2->data,this_cur);
            cur2 = cur2->next;
        }
        else if(cur1->data <= cur2->data){
            insert(cur1->data,this_cur);
            cur1 = cur1->next;
        }
        this_cur = this_cur->next;
    }
    return *this;
}

template<class T>
void NumberLinkedList<T>::printList(){
    Node<T>* current = first();
    while (current)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}
template<class T>
bool NumberLinkedList<T>::isEmpty(){
    return (first() == NULL);
}
template<class T>
Node<T>* NumberLinkedList<T>::zeroth(){
    return dummyHead;
}
template<class T>
Node<T>* NumberLinkedList<T>::first(){
    return dummyHead->next;
}
template<class T>
void NumberLinkedList<T>::insert(const T& data, Node<T>* p) {
    Node<T>* newNode = new Node<T>(data,p->next);
    p->next = newNode;
}
template<class T>
void NumberLinkedList<T>::makeEmpty(){
    while (!isEmpty())
        remove(first()->data);
}

int main()
{
    NumberLinkedList<int> p1;
    Node<int>* temp = p1.zeroth();
    for (int i = 1 ; i <= 10; ++i)
    {
        p1.insert(i*2,temp);
        temp = temp->next;
    }
    std::cout << "Printing the list p1: "<< std::endl;
    p1.printList();
    std::cout << std::endl;
    NumberLinkedList<int> p2;
    temp = p2.zeroth();
    for (int i = 1 ; i <= 20; i+=2)
    {
        p2.insert(i,temp);
        temp = temp->next;
    }
    std::cout << "Printing the list p2: "<< std::endl;
    p2.printList();
    NumberLinkedList<int> p3;
    temp = p3.zeroth();
    for (int i = 1 ; i <= 10; ++i)
    {
        p3.insert(i*2,temp);
        temp = temp->next;
    }
    std::cout << std::endl;
    std::cout << "Printing the list p3: "<< std::endl;
    p3.printList();

    if (p1.equal(p2))
        std::cout <<"p1 is equal p2" << std::endl;
    else
        std::cout <<"p1 is not equal p2" << std::endl;
    if (p1.equal(p3))
        std::cout <<"p1 is equal p3" << std::endl;
    else
        std::cout <<"p1 is not equal p3" << std::endl;

    NumberLinkedList<int> p4;
    p4.merge(p1,p2);
    std::cout << "Printing the list p4:(merge p1 & p2) "<< std::endl;
    p4.printList();

    NumberLinkedList<int> p5;
    p5.concatenate2Lists(p1,p2);
    std::cout << "Printing the list p5:(concatenate p1->p2) "<< std::endl;
    p5.printList();

    return 0;
}
