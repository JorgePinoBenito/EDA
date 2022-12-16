#ifndef STACKLI_H_
#define STACKLI_H_

#include <stdlib.h>
#include "Except.h"

// Stack class -- linked list implementation.
//
// CONSTRUCTION: with no parameters.
//
// ******************PUBLIC OPERATIONS*********************
// void push( x )        --> Insert x
// void pop( )           --> Remove most recently inserted item
// Object top( )         --> Return most recently inserted item
// Object topAndPop( )   --> Return and remove most recently inserted item
// bool isEmpty( )       --> Return true if empty; else false
// void makeEmpty( )     --> Remove all items
// ******************ERRORS********************************
// UnderflowException thrown as needed.

class StackInt
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

  Nodo *topOfStack;

public:
  StackInt();
  StackInt(const StackInt &rhs);
  ~StackInt();

  void pushNodo(const int &x);
  void popNodo();
  const int &top() const;
  int TopYPop();
  void mostrar(); // Fin docente (en la pila solo podemos "ver" el TOS), hecho por mi.
  void borrarPila();
  void tamano(); // Tamaño de la pila, hecho por mi.
  bool vacio() const;
  const StackInt &operator=(const StackInt &rhs);
};

#include "StackInt.cpp"
#endif
