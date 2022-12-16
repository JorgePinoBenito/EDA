// CodigoEDA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "QueueLi.h"

using namespace std;

int main()
{
    cout << endl;
    cout << "EJEMPLO DE COLA (QUEUE)" << endl
         << endl;

    cout << "Creando mi cola (queue)..." << endl;
    Queue MiQueue1 = Queue();

    std::cout << "Insertando nodos 1, 2, 3, 4 y 5" << std::endl;
    MiQueue1.encolar(1);
    MiQueue1.encolar(2);
    MiQueue1.encolar(3);
    MiQueue1.encolar(4);
    MiQueue1.encolar(5);

    // cout << "Mostrando cola..." << endl;
    // MiQueue1.mostrar();
    cout << endl
         << "El front de la pila es: " << MiQueue1.getFront() << endl;
    // cout << "El tamano de la cola es: ";
    // MiQueue1.tamano();
    cout << endl;

    cout << "----------------------------------------------------" << endl;

    std::cout << "Insertando nodos 6 y 7" << std::endl;
    MiQueue1.encolar(6);
    MiQueue1.encolar(7);

    Queue MiQueue2 = MiQueue1;

    // cout << "Mostrando cola 1..." << endl;
    // MiQueue1.mostrar();

    cout << endl;

    // cout << "Mostrando cola 2..." << endl;
    // MiQueue2.mostrar();

    cout << endl
         << "El front de la cola 1 es: " << MiQueue1.getFront() << endl;
    // cout << "El tamano de la cola 1 es: ";
    // MiQueue1.tamano();

    cout << endl;

    cout << endl
         << "El front de la pila 2 es: " << MiQueue1.getFront() << endl;
    // cout << "El tamano de la pila 2 es: ";
    // MiQueue2.tamano();

    cout << endl
         << endl
         << "Operaciones con la cola 1...";

    cout << endl
         << endl
         << "Eliminando primer nodo insertado..." << endl;
    MiQueue1.desencolar();
    // cout << "Mostrando cola..." << endl;
    // MiQueue1.mostrar();
    cout << endl
         << "El front de la cola es: " << MiQueue1.getFront() << endl;
    // cout << "El tamano de la cola es: ";
    // MiQueue1.tamano();
    cout << endl;

    cout
        << "----------------------------------------------------" << endl;

    std::cout << "Insertando nodos 8, 9 y 10" << std::endl;
    MiQueue1.encolar(8);
    MiQueue1.encolar(9);
    MiQueue1.encolar(10);
    // cout << "Mostrando cola..." << endl;
    // MiQueue1.mostrar();
    cout << endl
         << "El front de la cola es: " << MiQueue1.getFront() << endl;
    // cout << "El tamano de la pila es: ";
    // MiQueue1.tamano();
    cout << endl;
    /*cout << endl
         << "Eliminando ultimo elemento insertado (Top) y mostrandolo... ";
    cout << MiQueue1.TopYPop() << endl;*/
    cout << endl
         << "El front de la cola es: " << MiQueue1.getFront() << endl;
    // cout << "El tamano de la pila es: ";
    // MiQueue1.tamano();
    cout << endl;

    cout
        << "----------------------------------------------------" << endl;

    cout << "Borrando toda la cola..." << endl;
    MiQueue1.borrarCola();
    // cout << "Mostrando pila..." << endl;
    // MiQueue1.mostrar();
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
