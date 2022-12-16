#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int fibonacci(int n)
{
    if (n < 2)
    {             // Condición de salida
        return n; // Los dos primeros términos de la serie son 0 1
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2); // Aplico recursividad
    }
}

int main()
{
    // Serie de Fibonacci -> 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144,…
    int n;
    vector<int> vec;
    unsigned t0, t1; // Tiempos

    cout << "Introduzca numero elementos: ";
    cin >> n;

    cout << "La serie de Fibonacci hasta tu numero es: ";
    t0 = clock();
    for (int i = 0; i < n; i++)
    {
        vec.push_back(fibonacci(i)); // Inserto en el vector el valor del numero de la serie de Fibonacci
        cout << vec.at(i) << "_";    // Muestro valor del vector en posicion
    }
    t1 = clock();

    double time = (double(t1 - t0) / CLOCKS_PER_SEC); // Hago la resta de tiempos para ver el tiempo final en ciclos por segundo
    std::cout << std::endl;
    std::cout << "Tiempo ejecucion: " << time << std::endl; // Muestro el tiempo de ejecucion

    return 0;
}