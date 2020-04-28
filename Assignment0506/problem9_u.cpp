#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Node.h"
#include "Exception.h"



template<class T>
void printQueue(Queue<T>& );
template<class T>
void printStack(Stack<T>& );
template<class T>
void iterator_Stack_to_Queue(Stack<T>& , Queue<T>&);
template<class T>
void recursive_Stack_to_Queue(Stack<T>& , Queue<T>&);
int main()
{
    Stack<int> _stack;
    Queue<int> _queue_by_iter;
    Queue<int> _queue_by_recur;
    for ( int i = 0 ; i < 10 ; ++i)
        _stack.push(i);
    iterator_Stack_to_Queue(_stack,_queue_by_iter);
    std::cout<<"By iterator: " << std::endl;
    printStack(_stack);
    printQueue(_queue_by_iter);
    recursive_Stack_to_Queue(_stack,_queue_by_recur);
    std::cout<<"By recursive: " << std::endl;
    printStack(_stack);
    printQueue(_queue_by_recur);
    return 0;
}
template<class T>
void recursive_Stack_to_Queue(Stack<T>& inputStack, Queue<T>& finalQueue)
{
    if (inputStack.isEmpty())
        return;
    else{
        T value;
        inputStack.topAndPop(value);
        finalQueue.enqueue(value);
        recursive_Stack_to_Queue(inputStack,finalQueue);
        inputStack.push(value);
        return;
    }
}
template<class T>
void iterator_Stack_to_Queue(Stack<T>& inputStack, Queue<T>& finalQueue)
{
    Stack<int> copy_stack = inputStack;
    while (!copy_stack.isEmpty())
    {
        T value;
        copy_stack.topAndPop(value);
        finalQueue.enqueue(value);
    }
}
template<class T>
void printQueue(Queue<T>& q)
{
    std::cout<< "frontPtr--->";
    Queue<T> tmp = q;
    while ( !tmp.isEmpty())
    {
        T value;
        tmp.dequeue(value);
        std::cout<< value;
        if (!tmp.isEmpty())
            std::cout << "->";
    }
    std::cout << "(<----backPtr)->/" << std::endl;
}
template<class T>
void printStack(Stack<T>& q)
{
    std::cout<< "topPtr--->";
    Stack<T> tmp = q;
    while ( !tmp.isEmpty())
    {
        T value;
        tmp.topAndPop(value);
        std::cout<< value << "->";
    }
    std::cout << "/" << std::endl;
}
