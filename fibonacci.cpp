#include <iostream>
#include <ctime>

using namespace std;

int fibonacci_iterativo(int n)
{
    int penultimo = 0;
    int ultimo = 1;
    int actual = 0;

    for (int i = 1; i < n; i++)
    {
        actual = penultimo + ultimo;
        penultimo = ultimo;
        ultimo = actual;
    }

    return actual;
}

int main()
{
    // Serie de Fibonacci -> 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,…
    int numero{0};
    unsigned t0, t1; // Tiempos

    cout << "Que posicion de la serie de Fibonacci quieres visualizar (empezamos en la posicion 0)? ";
    cin >> numero;

    t0 = clock();
    cout << "El numero que corresponde a la serie de Fibonacci en esa posicion es: " << fibonacci_iterativo(numero);
    t1 = clock();

    double tiempo = (double(t1 - t0) / CLOCKS_PER_SEC); // Hago la resta de tiempos para ver el tiempo final en ciclos por segundo
    cout << endl
         << "Tiempo de ejecucion: " << tiempo << " segundos" << endl; // Muestro el tiempo de ejecucion

    return 0;
}
