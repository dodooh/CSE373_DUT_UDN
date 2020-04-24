#include <iostream>

template <class T>
class Node
{
public:
    T item;
    Node* next;
    Node(const T& e = T(), Node* n = nullptr)
        : item(e), next(n) {}
};

class StackException
{
private:
    const char* pMessage;
public:
    StackException(const char* pStr = "There's a problem") : pMessage(pStr) {}
    const char* what() const {return pMessage;}
    ~StackException( ) {}


};

template <class T>
class MathStack
{
public:
    MathStack();// default constructor
    MathStack(const MathStack& rhs); // copy constructor
    ~MathStack(); // destructor
    MathStack& operator=(const MathStack& rhs); // assignment operator
    bool isEmpty() const;
    void push(const T& newItem);
    void pop();
    void topAndPop(T& stackTop);
    void getTop(T& stackTop) const;
    void add();
    void sub();
    void mult();
    void div();
    void addAll();
    void multAll();

private:
    Node<T> *topPtr; // pointer to the first node in the stack
};
template <class T>
MathStack<T>::MathStack()
{
    topPtr = nullptr;
}
template <class T>
MathStack<T>::~MathStack()
{
    while (!isEmpty())
        pop();
}
template <class T>
bool MathStack<T>::isEmpty() const
{
    return nullptr == topPtr;
}
template <class T>
void MathStack<T>::push(const T& data)
{
    Node<T>* newNode = new Node<T>(data,topPtr);
    topPtr           = newNode;
}
template <class T>
void MathStack<T>::pop()
{
    if (isEmpty())
        throw StackException("StackException: stack empty on pop");
    else
    {
        Node<T>*tmp = topPtr;
        topPtr      = topPtr->next; // update the stack top
        delete tmp;
    }
}
template <class T>
void MathStack<T>::topAndPop(T& stackTop)
{
    if (isEmpty())
        throw StackException("StackException: stack empty on topAndPop");
    else
    {
        stackTop     = topPtr->item;
        Node<T> *tmp = topPtr;
        topPtr       = topPtr->next;
        delete tmp;
    }
}
template <class T>
void MathStack<T>::getTop(T& stackTop) const
{
    if (isEmpty())
        throw StackException("StackException: stack empty on getTop");
    else
        stackTop = topPtr->item;
}
template <class T>
MathStack<T>& MathStack<T>::operator=(const MathStack& rhs)
{
    if (this != &rhs)
    {
        if (!rhs.topPtr)
            topPtr = NULL;
        else
        {
            topPtr          = new Node<T>;
            topPtr->item    = rhs.topPtr->item;
            Node<T>* q = rhs.topPtr->next;
            Node<T>* p = topPtr;
            while (q)
            {
                p->next       = new Node<T>;
                p->next->item = q->item;
                p             = p->next;
                q             = q->next;
            }
            p->next = NULL;
        }
    }
    return *this;
}
template <class T>
MathStack<T>::MathStack(const MathStack& rhs)
{
    *this = rhs; // reuse assignment operator
}
template <class T>
void MathStack<T>::add()
{
    int v1,v2;
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v1);
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v2);
    push(v1+v2);

}
template <class T>
void MathStack<T>::sub()
{
    int v1,v2;
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v1);
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v2);
    push(v1-v2);
}
template <class T>
void MathStack<T>::mult()
{
    int v1,v2;
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v1);
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v2);
    push(v1*v2);
}
template <class T>
void MathStack<T>::div()
{
    int v1,v2;
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v1);
    if (isEmpty())
        throw StackException("StackException: sub() requires at least 2 values on stack.");
    else
        topAndPop(v2);
    if ( v2 == 0 )
        throw StackException("Exception: Divide by 0");
    else
        push(v1/v2);
}
template <class T>
void MathStack<T>::addAll()
{
    if (isEmpty())
        throw StackException("StackException: addAll() requires at least 1 value on stack.");
    else
        while (topPtr->next != NULL)
        {
            add();
        }
}
template <class T>
void MathStack<T>::multAll()
{
    if (isEmpty())
        throw StackException("StackException: multAll() requires at least 1 value on stack.");
    else
        while (topPtr->next != NULL)
        {
            mult();
        }
}

template<class T>
void print(MathStack<T>& );
//________________________________MAIN__________________________________
int main()
{
    MathStack<int> s;
    for (int i = 1; i < 10; i++)
        s.push(i);
    // Stack is 0->1->2->3->4->5->6->7->8->9 with 9 is stackTop.

    MathStack<int> s2 = s; // test copy constructor (also tests assignment)
    std::cout << "Print s2 " << std::endl;
    print(s2);
    // ADD() class function will sum 8 & 9 to 17 and push to the stack so it becomes 0->1->2->3->4->5->6->7->17
    std::cout << "Test add() : ";
    try{
        s2.add();
        int value;
        s2.getTop(value);
        std::cout << value << std::endl;
    }
    catch (const StackException& e)
    {
        std::cout << e.what() << std::endl;
    }
    print(s2);
    std::cout << "Test sub() : ";
    try{
        s2.sub();
        int value;
        s2.getTop(value);
        std::cout << value << std::endl;
    }
    catch (const StackException& e)
    {
        std::cout << e.what() << std::endl;
    }
    print(s2);
    std::cout << "Test mult() : ";
    try{
        s2.mult();
        int value;
        s2.getTop(value);
        std::cout << value << std::endl;
    }
    catch (const StackException& e)
    {
        std::cout << e.what() << std::endl;
    }
    print(s2);
    std::cout << "Test div() : ";
    try{
        s2.div();
        int value;
        s2.getTop(value);
        std::cout << value << std::endl;
    }
    catch (const StackException& e)
    {
        std::cout << e.what() << std::endl;
    }
    print(s2);
    //addAll()
    MathStack<int> s3 = s;
    std::cout << "Print s3 " << std::endl;
    print(s3);
    try{
        s3.addAll();
    }
    catch (const StackException& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test addAll() : ";
    print(s3);
    //multAll
    MathStack<int> s4 = s;
    std::cout << "Print s4 " << std::endl;
    print(s4);
    try{
        s4.multAll();
    }
    catch (const StackException& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "Test multAll() : ";
    print(s4);

    return 0;
}
template<class T>
void print(MathStack<T>& m)
{
    MathStack<T> temp = m;
    while (!temp.isEmpty())
    {
        int value;
        temp.topAndPop(value);
        std::cout << value << "<-";
    }
    std::cout <<"NULL"<< std::endl;
    temp.~MathStack();
}
