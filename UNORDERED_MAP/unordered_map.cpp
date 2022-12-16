#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool consultartf(const unordered_map<string, string> &listintf)
{
    // Pregunto telefono a buscar
    string tf = "";
    cout << "Telefono a buscar? ";
    getline(cin, tf);

    // Itero el listintf con un iterador que a su vez es un unordered_map<string, string>
    for (unordered_map<string, string>::const_iterator iterador = listintf.begin(); iterador != listintf.end(); ++iterador)
    {
        // Compruebo si el telefono se encuentra como valor dentro del listintf, muestro true si está y false en el caso contrario
        if (iterador->second == tf)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

int main()
{
    // Creo un unordered_map de dos strings llamado listintf (key y value, es decir clave y valor se asignan a cadenas)
    unordered_map<string, string> listintf = {};

    // Agrego dos nuevas entradas a listin con key, value
    listintf.insert({"Paco", "678594876"});
    listintf.insert({"Jorge", "632654987"});
    listintf.insert({"Maria", "606654987"});

    // Función auxiliar lambda para imprimir pares key, value
    auto imprimir_key_value = [](string const &key, string const &value)
    {
        cout << "Key:[" << key << "] Value:[" << value << "]" << endl;
    };

    // Imprimo listintf por key, value
    for (const auto &n : listintf)
    {
        imprimir_key_value(n.first, n.second);
    }
    cout << endl;

    // Consulto telefono, es decir consulto un valor.
    cout << consultartf(listintf);

    return 0;
}
