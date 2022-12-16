// CodigoEDA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "StackInt.h"

using namespace std;

int main()
{
     cout << endl;
     cout << "EJEMPLO DE PILA (STACK)" << endl
          << endl;

     cout << "Creando mi pila (stack)..." << endl;
     StackInt MiStack1 = StackInt();

     std::cout << "Insertando nodos 1, 2, 3, 4 y 5" << std::endl;
     MiStack1.pushNodo(1);
     MiStack1.pushNodo(2);
     MiStack1.pushNodo(3);
     MiStack1.pushNodo(4);
     MiStack1.pushNodo(5);

     cout << "Mostrando pila..." << endl;
     MiStack1.mostrar();
     cout << endl
          << "El top de la pila es: " << MiStack1.top() << endl;
     cout << "El tamano de la pila es: ";
     MiStack1.tamano();
     cout << endl;

     cout << "----------------------------------------------------" << endl;

     std::cout << "Insertando nodos 6 y 7" << std::endl;
     MiStack1.pushNodo(6);
     MiStack1.pushNodo(7);

     StackInt MiStack2 = MiStack1;

     cout << "Mostrando pila 1..." << endl;
     MiStack1.mostrar();

     cout << endl;

     cout << "Mostrando pila 2..." << endl;
     MiStack2.mostrar();

     cout << endl
          << "El top de la pila 1 es: " << MiStack1.top() << endl;
     cout << "El tamano de la pila 1 es: ";
     MiStack1.tamano();

     cout << endl;

     cout << endl
          << "El top de la pila 2 es: " << MiStack2.top() << endl;
     cout << "El tamano de la pila 2 es: ";
     MiStack2.tamano();

     cout << endl
          << endl
          << "Operaciones con la pila 1...";

     cout << endl
          << endl
          << "Eliminando ultimo nodo insertado..." << endl;
     MiStack1.popNodo();
     cout << "Mostrando pila..." << endl;
     MiStack1.mostrar();
     cout << endl
          << "El top de la pila es: " << MiStack1.top() << endl;
     cout << "El tamano de la pila es: ";
     MiStack1.tamano();
     cout << endl;

     cout
         << "----------------------------------------------------" << endl;

     std::cout << "Insertando nodos 8, 9 y 10" << std::endl;
     MiStack1.pushNodo(8);
     MiStack1.pushNodo(9);
     MiStack1.pushNodo(10);
     cout << "Mostrando pila..." << endl;
     MiStack1.mostrar();
     cout << endl
          << "El top de la pila es: " << MiStack1.top() << endl;
     cout << "El tamano de la pila es: ";
     MiStack1.tamano();
     cout << endl;
     cout << endl
          << "Eliminando ultimo elemento insertado (Top) y mostrandolo... ";
     cout << MiStack1.TopYPop() << endl;
     cout << endl
          << "El top de la pila es: " << MiStack1.top() << endl;
     cout << "El tamano de la pila es: ";
     MiStack1.tamano();
     cout << endl;

     cout
         << "----------------------------------------------------" << endl;

     cout << "Borrando toda la pila..." << endl;
     MiStack1.borrarPila();
     cout << "Mostrando pila..." << endl;
     MiStack1.mostrar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
