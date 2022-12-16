#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool comrprobar(const vector<int> &mivec1, const vector<int> &mivec2)
{
    bool condicion = true;
    int valorDelArreglo = 0;
    int valorDelOtroArreglo = 0;
    int contador=0;

    if (mivec1.size() != mivec2.size())
    {
        cout << "Los arreglos no son iguales";
        return 0;
    }

    for (int i = 0; i < mivec1.size(); i++)
    {
        // Obtener elementos de ambos arreglos en misma posición o índice
        valorDelArreglo = mivec1[i];
        valorDelOtroArreglo = mivec2[i];

        if (valorDelArreglo != valorDelOtroArreglo)
        {
            // Los arreglos no son iguales
            condicion = false;
            contador++;
        }

        if (valorDelArreglo != valorDelOtroArreglo)
        {
            // Los arreglos no son iguales
            condicion = false;
        }
    }

    return condicion;
}

int main()
{

    /*(Ejercicio para 10, valor 1 punto)Implementar un método que nos indique si dos vectores son equivalentes. Para este ejercicio, dos vectores son equivalentes si tienen los mismo números y éstos aparecen el mismo número de veces en los vectores.

    (1,1,1,2) y (2,1,1,1) son equivalentes

    (1,2) y (1,1,2) no son equivalentes*/
    
    vector<int> mivec1 = {1, 2, 3, 4, 5};
    vector<int> mivec2 = {1, 2, 3, 4, 5};

    bool comprobar1 = comrprobar(mivec1, mivec2);
    cout << comprobar1;

    bool comprobar2 = mivec1 == mivec2;
    cout << comprobar2;

    return 0;
}