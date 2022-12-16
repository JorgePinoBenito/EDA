#include "StackInt.h"

using namespace std;

// Construct the stack.
StackInt::StackInt()
{
    topOfStack = nullptr;
}

// Copy constructor.
StackInt::StackInt(const StackInt &rhs)
{
    topOfStack = nullptr;
    *this = rhs;
}

// Destructor.
StackInt::~StackInt()
{
    borrarPila();
}

// Insert x into the stack.
void StackInt::pushNodo(const int &x)
{
    topOfStack = new Nodo(x, topOfStack);
}

// Remove the most recently inserted item from the stack.
// Throw Underflow if the stack is empty.
void StackInt::popNodo()
{
    if (vacio())
        throw UnderflowException();

    Nodo *oldTop = topOfStack;
    topOfStack = topOfStack->siguiente;
    delete oldTop;
}

// Return the most recently inserted item in the stack.
// or throw an UnderflowException if empty.
const int &StackInt::top() const
{
    if (vacio())
        throw UnderflowException();
    return topOfStack->elemento;
}

// Return and remove the most recently inserted item
// from the stack.
int StackInt::TopYPop()
{
    Nodo topItem = top();
    popNodo();
    return topItem.elemento;
}

// Show
void StackInt::mostrar()
{
    cout << "Mi pila actual es: " << endl;
    if (!vacio())
    {
        for (Nodo *rptr = topOfStack; rptr != nullptr; rptr = rptr->siguiente)
        {
            cout << "Id del nodo: " << rptr->elemento << " "
                 << "Siguiente nodo: " << rptr->siguiente << endl;
        }
    }
    else
    {
        cout << "La pila esta vacia." << endl;
    }
}

// Make the stack logically empty.
void StackInt::borrarPila()
{
    while (!vacio())
    {
        popNodo();
    }
}

// Size of Stack
void StackInt::tamano()
{
    int contador = 0;
    if (!vacio())
    {
        for (Nodo *rptr = topOfStack; rptr != nullptr; rptr = rptr->siguiente)
        {
            contador++;
        }
        cout << contador;
    }
    else
    {
        cout << "La pila esta vacia" << endl;
    }
}

// Test if the stack is logically empty.
// Return true if empty, false, otherwise.
bool StackInt::vacio() const
{
    if (topOfStack == nullptr)
    {
        return 1;
    }
    return 0;
}

// Deep copy.
const StackInt &StackInt::operator=(const StackInt &rhs)
{
    if (this != &rhs)
    {
        borrarPila();
        if (rhs.vacio())
            return *this;

        Nodo *rptr = rhs.topOfStack;
        Nodo *ptr = new Nodo(rptr->elemento);
        topOfStack = ptr;

        for (rptr = rptr->siguiente; rptr != nullptr; rptr = rptr->siguiente)
            ptr = ptr->siguiente = new Nodo(rptr->elemento);
    }
    return *this;
}
