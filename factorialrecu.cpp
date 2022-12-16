#include <iostream>

using namespace std;

int factorial(int valor)
{
    if (valor == 0)
    {
        return 1;
    }
    else
    {
        return valor * factorial(valor - 1);
    }
}

int main()
{
    int n;
    cout << "Introduzca numero: ";
    cin >> n;
    cout << "factorial: " << factorial(n) << endl;
}
