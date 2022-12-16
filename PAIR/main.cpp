#include <iostream>
#include <utility> //std::pair
#include <string>
#include <vector>

using namespace std;

string aminuscula(string cadena) // Convierto string a minusculas para evitar errores
{
    for (int i = 0; i < cadena.length(); i++)
    {
        cadena[i] = tolower(cadena[i]);
    }
    return cadena;
}

void igualnombreyapellido(const vector<pair<string, string>> &nya)
{

    for (auto elem : nya)
    {
        elem.first = aminuscula(elem.first);
        elem.second = aminuscula(elem.second);

        if (elem.first == elem.second) // Compruebo nombre(first) y apellido (second)
        {
            // Devuelve el nombre y el apellido de las personas que tengan igual nombre y apellido.
            cout << "Nombre: " << elem.first << " Apellido: " << elem.second << '\n';
        }
    }
}

int main()
{
    // Creo el vector de pair<string,string> para almacenar nombres y apellidos
    vector<pair<string, string>> nya = {};

    // Declaro los pares
    pair<string, string> nya1;
    pair<string, string> nya2;
    pair<string, string> nya3;
    pair<string, string> nya4;

    // Instancio los pares
    nya1 = make_pair("Martin", "Martin");
    nya2 = make_pair("Jorge", "Pino");
    nya3 = make_pair("Carlos", "Garcia");
    nya4 = make_pair("Steven", "steven");

    // Meto pares en el vector
    nya.push_back(nya1);
    nya.push_back(nya2);
    nya.push_back(nya3);
    nya.push_back(nya4);

    // Compruebo personas con mismo nombre y apellido
    igualnombreyapellido(nya);

    return 0;
}
