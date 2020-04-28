#include <iostream>
#include <fstream>
#include <sstream>
#define INPUT_FILE_PATH "C:\\Users\\King\\OneDrive - Danang University of Technology\\CSE373\\Assignment0506\\input.txt"
#define OUTPUT_FILE_PATH "C:\\Users\\King\\OneDrive - Danang University of Technology\\CSE373\\Assignment0506\\output.txt"
template <class T>
struct QNode
{
public:
    QNode(const T& e = T(), QNode* n = NULL)
        : item(e), next(n) {}
    T item;
    QNode<T>* next;
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
    Queue& operator=(const Queue & rhs); //assignment operator
    bool isEmpty() const; // Determines whether the queue is empty
    void enqueue(const T& newItem); // Inserts an item at the back of a queue
    void dequeue() throw(QueueException); // Dequeues the front of a queue
    // Retrieves and deletes the front of a queue.
    void dequeue(T& queueFront) throw(QueueException);
    // Retrieves the item at the front of a queue.
    void getFront(T& queueFront) const throw(QueueException);
private:
    QNode<T> *backPtr;
    QNode<T> *frontPtr;
};

template<class T>
bool Queue<T>::isEmpty() const
{
    return backPtr == NULL;
}
template<class T>
void Queue<T>::enqueue(const T& newItem)
{
    // create a new node
    QNode<T> *newPtr = new QNode<T>;
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
        QNode<T> *tempPtr = frontPtr;
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

int main()
{
    std::ifstream inFile(INPUT_FILE_PATH);
    std::stringstream buffer;
    std::string s;
    if (!inFile)
    {
        throw QueueException("Unable to open file");
        exit(1);   // call system to stop
    }
    else
    {
        std::getline(inFile,s);
        inFile.close();
    }
    //Push input to the stack of characters

    Queue<char> inputString;
    for (char& c: s)
    {
        inputString.enqueue(c);
    }
    //Pop to the output file
    std::ofstream outFile(OUTPUT_FILE_PATH);
    char c;
    while (!inputString.isEmpty())
    {
        inputString.dequeue(c);
        if ( c >= 97 && c <= 122 )
            c -= 32;
        outFile << c;
    }
    outFile.close();
    //Announcement
    std::cout << "Success! " << std:: endl;
    return  0;
}

