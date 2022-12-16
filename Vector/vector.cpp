#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comprobar(const vector<string> &mivec, const string &nombre)
{
    bool condicion = false;

    for (auto elem : mivec)
    {
        if (elem == nombre)
        {
            condicion = true;
        }
    }

    return condicion;
}

int main()
{
    vector<string> listavips;
    string nombre = "";
    bool contiene = false;

    listavips.push_back("Jorge");
    listavips.push_back("Victor");

    cout << "Los nombres que contiene el vector listavips son: " << endl;

    for (auto elem : listavips)
    {
        cout << elem << endl;
    }

    cout << "Introduce nombre a buscar: ";
    getline(cin, nombre);

    contiene = comprobar(listavips, nombre);
    cout << contiene;

    return 0;
}
