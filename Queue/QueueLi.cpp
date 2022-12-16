#include "QueueLi.h"

// Construct the queue.
Queue::Queue()
{
    front = back = nullptr;
}

// Copy constructor.
Queue::Queue(const Queue &rhs)
{
    front = back = nullptr;
    *this = rhs;
}

// Destructor.
Queue::~Queue()
{
    borrarCola();
}

// Insert x into the queue.
void Queue::encolar(const int &x)
{
    if (vacio())
        back = front = new Nodo(x);
    else
        back = back->siguiente = new Nodo(x);
}

// Return and remove the least recently inserted item from
// the queue. Throw UnderflowException if empty.
int Queue::desencolar()
{
    int frontItem = getFront();

    Nodo *old = front;
    front = front->siguiente;
    delete old;

    return frontItem;
}

// Return the least recently inserted item in the queue
// or throw UnderflowException if empty.
const int &Queue::getFront() const
{
    if (vacio())
        throw UnderflowException();
    return front->elemento;
}

// Make the queue logically empty.
void Queue::borrarCola()
{
    while (!vacio())
        desencolar();
}

// Test if the queue is logically empty.
// Return true if
bool Queue::vacio() const
{
    return front == nullptr;
}

// Deep copy.
const Queue &Queue::operator=(const Queue &rhs)
{
    if (this != &rhs)
    {
        borrarCola();
        Nodo *rptr;
        for (rptr = rhs.front; rptr != nullptr; rptr = rptr->siguiente)
            encolar(rptr->elemento);
    }
    return *this;
}
