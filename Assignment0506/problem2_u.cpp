#include <iostream>
#include <fstream>
#include <sstream>
#define INPUT_FILE_PATH "C:\\Users\\King\\OneDrive - Danang University of Technology\\CSE373\\Assignment0506\\input.txt"
#define OUTPUT_FILE_PATH "C:\\Users\\King\\OneDrive - Danang University of Technology\\CSE373\\Assignment0506\\output.txt"
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
    const char* what() const
    {
        return pMessage;
    }
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


//________________________________MAIN__________________________________
int main()
{   //Read from file
    std::ifstream inFile(INPUT_FILE_PATH);
    std::stringstream buffer;
    std::string s;
    if (!inFile)
    {
        throw StackException("Unable to open file");
        exit(1);   // call system to stop
    }
    else
    {
        std::getline(inFile,s);
        inFile.close();
    }
    //Push input to the stack of characters
    Stack<char> reverseString;
    for(char& c: s)
    {
        reverseString.push(c);
    }
    //Pop to the output file
    std::ofstream outFile(OUTPUT_FILE_PATH);
    char c;
    while (!reverseString.isEmpty())
    {
        reverseString.topAndPop(c);
        outFile << c;
    }
    outFile.close();
    //Announcement
    std::cout << "Success! " << std:: endl;
    return 0;
}

