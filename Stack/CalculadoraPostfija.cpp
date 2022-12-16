#include <iostream>
#include <string.h>
#include "StackInt.h"

using namespace std;

// Funcion que pasa una cadena con numeros a entero.
int PasaCadenaAEntero(char cadena[20])
{
    /*
    Precondición:
    Se ha de recibir una cadena de caracteres terminada en fin de linea que contenga solo un numero entero de máximo 20 dígitos.
    Poscondición:
    Se pasa esa cadena al tipo entero y se devuelve el valor.
    */

    int longCadena = strlen(cadena), numero = 0;

    for (int i = 0; i < longCadena; i++)
    {
        numero *= 10;
        numero += cadena[i] - 48;
    };

    return numero;
}

int main()
{
    StackInt MiStack = StackInt();
    char cadena[20];
    int valor1 = 0, valor2 = 0;

    cout << "Las expresiones en notacion postfija son de la siguiente manera: 10, 2, +. Esto se correponde con la expresion infija: 10 + 2.\n";
    cout << "Las expresiones postfijas se introducen de la siguiente manera:\n";
    cout << "\n   2\n   5\n   *\n   8\n   +\n   1\n   9\n   /\n   -\n\n";
    cout << "Introduzca un valor u operador y pulse intro para introducir el siguiente, escriba = para calcular el resultado de la operacion:\n\n";

    do
    {
        // Se lee un valor o operador.
        cin >> cadena;

        /*Dependiendo de lo que se haya leido se hace una operacion u otra: en el caso de: '+', '-', '*' y '/', se sacan los dos valores numericos anteriores de la pila, se opera con ellos según el operador elegido y se guarda el resultado en la pila como Top Of Stack (ultimo elemento introducido en la pila).*/
        switch (cadena[0])
        {
        case '+':
            valor1 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            valor2 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            MiStack.pushNodo(valor1 + valor2); // pushNodo -> Inserta un valor entero en la pila.
            break;

        case '-':
            valor1 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            valor2 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            MiStack.pushNodo(valor1 - valor2); // pushNodo -> Inserta un valor entero en la pila.
            break;

        case '*':
            valor1 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            valor2 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            MiStack.pushNodo(valor1 * valor2); // pushNodo -> Inserta un valor entero en la pila.
            break;

        case '/':
            valor1 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            valor2 = MiStack.TopYPop();        // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            MiStack.pushNodo(valor1 / valor2); // pushNodo -> Inserta un valor entero en la pila.
            break;

        case '=':
            // Se imprime por pantalla el ultimo y único elemento de la pila.
            cout << "\nEl resultado es: " << MiStack.TopYPop(); // TopyPop -> Devuelve y elimina el elemento insertado mas recientemente de la pila.
            break;

        default:
            MiStack.pushNodo(PasaCadenaAEntero(cadena)); // pushNodo -> Inserta un valor entero en la pila.
            break;
        };

    } while (cadena[0] != '=');

    return 0;
}