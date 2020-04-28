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
class Stack
{
public:
    Stack();// default constructor
    Stack(const Stack& rhs); // copy constructor
    ~Stack(); // destructor
    Stack& operator=(const Stack& rhs); // assignment operator
    bool isEmpty() const;
    void push(const T& newItem);
    void pop();
    void topAndPop(T& stackTop);
    void getTop(T& stackTop) const;
private:
    Node<T> *topPtr; // pointer to the first node in the stack
};
template <class T>
Stack<T>::Stack()
{
    topPtr = nullptr;
}
template <class T>
Stack<T>::~Stack()
{
    while (!isEmpty())
        pop();
}
template <class T>
bool Stack<T>::isEmpty() const
{
    return nullptr == topPtr;
}
template <class T>
void Stack<T>::push(const T& data)
{
    Node<T>* newNode = new Node<T>(data,topPtr);
    topPtr           = newNode;
}
template <class T>
void Stack<T>::pop()
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
void Stack<T>::topAndPop(T& stackTop)
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
void Stack<T>::getTop(T& stackTop) const
{
    if (isEmpty())
        throw StackException("StackException: stack empty on getTop");
    else
        stackTop = topPtr->item;
}
template <class T>
Stack<T>& Stack<T>::operator=(const Stack& rhs)
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
Stack<T>::Stack(const Stack& rhs)
{
    *this = rhs; // reuse assignment operator
}

template<class T>
void print(Stack<T>& );
//________________________________MAIN__________________________________
int main()
{
    Stack<int> numStack;
    Stack<int> holdOddNumber;
    for(int i = 0; i < 20; ++i)
    {
        numStack.push(i);
    }
    std::cout<<"The stack is: ";
    print(numStack);
    int cnt = 0;
    while (!numStack.isEmpty())
    {
        int value;
        numStack.topAndPop(value);
        if (value % 2 != 0)
        {
            holdOddNumber.push(value);
        }
        else
            cnt++;
    }
    while (!holdOddNumber.isEmpty())
    {
        int value;
        holdOddNumber.topAndPop(value);
        numStack.push(value);
    }
    std::cout<<"The stack after remove even number is: ";
    print(numStack);
    std::cout <<"The number of removed numbers is "<< cnt << std::endl;
    return 0;
}

template<class T>
void print(Stack<T>& m)
{
    Stack<T> temp = m;
    while (!temp.isEmpty())
    {
        T value;
        temp.topAndPop(value);
        std::cout << value << "->";
    }
    std::cout <<"NULL"<< std::endl;
    temp.~Stack();
}
