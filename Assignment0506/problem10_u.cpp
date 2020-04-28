#include <iostream>

template <class T>
struct Node
{
public:
    Node(const T& e = T(), Node* n = NULL)
        : item(e), next(n) {}
    T item;
    Node<T>* next;
};

class QueueException
{
private:
    const char* pMessage;
public:
    QueueException(const char* pStr = "There's a problem") : pMessage(pStr) {}
    const char* what() const
    {
        return pMessage;
    }
    ~QueueException( ) {}
};

template <class T>
class Queue
{
public:
    Queue() : backPtr(NULL), frontPtr(NULL) {} // default constructor
    Queue(const Queue& rhs); // copy constructor
    ~Queue()   // destructor
    {
        while (!isEmpty())
            dequeue();
        // backPtr and frontPtr are NULL at this point
    }
    Queue& operator=(const Queue& ); //assignment operator
    bool isEmpty() const; // Determines whether the queue is empty
    void enqueue(const T& newItem); // Inserts an item at the back of a queue
    void dequeue() throw(QueueException); // Dequeues the front of a queue
    // Retrieves and deletes the front of a queue.
    void dequeue(T& queueFront) throw(QueueException);
    // Retrieves the item at the front of a queue.
    void getFront(T& queueFront) const throw(QueueException);
private:
    Node<T> *backPtr;
    Node<T> *frontPtr;
};

template <class T>
Queue<T>::Queue(const Queue<T>& rhs)
{
    Node<T>* rhs_cur = rhs.frontPtr;
    Node<T>* this_cur = frontPtr;
    if ( rhs_cur != NULL )
    {
        frontPtr = new Node<T>(rhs_cur->item);
        this_cur = frontPtr;
        rhs_cur  = rhs_cur->next;
    }
    while ( rhs_cur)
    {
        this_cur = this_cur->next = new Node<T>(rhs_cur->item);
        if (rhs_cur->next == NULL)
        {
            backPtr = this_cur;
        }
        rhs_cur  = rhs_cur->next;
    }

}
template <class T>
Queue<T>& Queue<T>::operator=(const Queue& rhs)
{
    Queue<T> temp(rhs);
    std::swap(temp.frontPtr,frontPtr);
    std::swap(temp.backPtr,backPtr);
    return *this;
}
template<class T>
bool Queue<T>::isEmpty() const
{
    return backPtr == NULL;
}
template<class T>
void Queue<T>::enqueue(const T& newItem)
{
    // create a new node
    Node<T> *newPtr = new Node<T>;
    // set data portion of new node
    newPtr->item = newItem;
    newPtr->next = NULL;
    // insert the new node
    if (isEmpty()) // insertion into empty queue
        frontPtr = newPtr;
    else // insertion into nonempty queue
        backPtr->next = newPtr;
    backPtr = newPtr; // new node is at back
}
template<class T>
void Queue<T>::dequeue() throw(QueueException)
{
    if (isEmpty())
        throw QueueException("QueueException: empty queue, cannot dequeue");
    else   // queue is not empty; remove front
    {
        Node<T> *tempPtr = frontPtr;
        if (frontPtr == backPtr)   // one node in queue
        {
            frontPtr = NULL;
            backPtr = NULL;
        }
        else
            frontPtr = frontPtr->next;
        tempPtr->next = NULL; // defensive strategy
        delete tempPtr;
    }
}
template<class T>
void Queue<T>::dequeue(T& queueFront) throw(QueueException)
{
    if (isEmpty())
        throw QueueException("QueueException: empty queue, cannot dequeue");
    else   // queue is not empty; retrieve front
    {
        queueFront = frontPtr->item;
        dequeue(); // delete front
    }
}
template<class T>
void Queue<T>::getFront(T& queueFront) const throw(QueueException)
{
    if (isEmpty())
        throw QueueException("QueueException: empty queue, cannot getFront");
    else // queue is not empty; retrieve front
        queueFront = frontPtr->item;
}
template<class T>
void print(Queue<T>& );

int main()
{
    Queue<std::string> stringQueue;
    stringQueue.enqueue("12abc6");
    stringQueue.enqueue("ahgd67");
    stringQueue.enqueue("qtgab0");
    stringQueue.enqueue("ghab45");
    stringQueue.enqueue("aaba90");
    std::string inputString;
    std::cin >> inputString;
    Queue<std::string> resultQueue;
    std::string candidate;
    while ( !stringQueue.isEmpty())
    {
        stringQueue.dequeue(candidate);
        if (candidate.find(inputString) != std::string::npos)
        {
            resultQueue.enqueue(candidate);
        }
    }
    if ( resultQueue.isEmpty())
        std:: cout <<"Not found!" ;
    else
        while( !resultQueue.isEmpty())
        {
            resultQueue.dequeue(candidate);
            std::cout<< candidate << " ";
        }

    return 0;
}

template<class T>
void print(Queue<T>& q)
{
    Queue<T> tmp = q;
    while ( !tmp.isEmpty())
    {
        T value;
        tmp.dequeue(value);
        std::cout<< value << "->";
    }
    std::cout << "/" << std::endl;
}
