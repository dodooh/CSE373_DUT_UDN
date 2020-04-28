#include <iostream>
#include <math.h>
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

bool isPrime(int );
template<class T>
void print(Stack<T>& );
//________________________________MAIN__________________________________
int main()
{
    Stack<int> inputStack;
    int n;
    std::cout <<"Give size of stack: ";
    std::cin >> n;
    while ( n )
    {
        int x;
        std::cout <<"Enter number [" << n <<"]: ";
        std::cin >> x;
        inputStack.push(x);
        n--;
    }
    std::cout <<"The input stack is: " << std::endl;
    print(inputStack);
    Stack<int> tempStack = inputStack;
    Stack<int> primeNumStack;
    int cnt = 0;
    while(!tempStack.isEmpty())
    {
        int value;
        tempStack.topAndPop(value);
        if (isPrime(value))
        {
            primeNumStack.push(value);
            cnt++;
        }
    }
    std::cout <<"The prime stack is: " << std::endl;
    print(primeNumStack);
    std::cout <<"Number of prime numbers: " << cnt << std::endl;
    std::cout <<"The input stack is: " << std::endl;
    print(inputStack);
    return 0;
}
bool isPrime(int x)
{
    if (x < 2)
        return false;
    for(int i = 2; i <= sqrt(x); ++i)
    {
        if (x % i  == 0)
            return false;
    }
    return true;
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
