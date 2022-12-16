#ifndef QUEUELI_H_
#define QUEUELI_H_

#include <stdlib.h>
#include "Except.h"

// Queue class -- linked list implementation.
//
// CONSTRUCTION: with no parameters.
//
// ******************PUBLIC OPERATIONS*********************
// void enqueue( x )  --> Insert x
// void dequeue( )    --> Return and remove least recent item
// Object getFront( ) --> Return least recently inserted item
// bool isEmpty( )    --> Return true if empty; else false
// void makeEmpty( )  --> Remove all items
// ******************ERRORS********************************
// UnderflowException thrown as needed.

class Queue
{
private:
    struct Nodo
    {
        int elemento;
        Nodo *siguiente;

        Nodo(const int &elemento, Nodo *siguiente = nullptr)
        {
            this->elemento = elemento;
            this->siguiente = siguiente;
        }
    };

    Nodo *front;
    Nodo *back;

public:
    Queue();
    Queue(const Queue &rhs);
    ~Queue();

    void encolar(const int &x);
    int desencolar();
    const int &getFront() const;
    void borrarCola();
    bool vacio() const;
    const Queue &operator=(const Queue &rhs);
};

#include "QueueLi.cpp"
#endif
