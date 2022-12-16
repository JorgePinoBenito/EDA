#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

string maslargo(const vector<string> &values)
{
    string maslargo = values.at(0);

    for (int i = 0; i < values.size(); i++)
    {
        if (values[i].length() > maslargo.length())
        {
            maslargo = values[i];
        }
    }

    return maslargo;
}

string mascorto(const vector<string> &values)
{
    string mascorto = values.at(0);

    for (int i = 0; i < values.size(); i++)
    {
        if (values[i].length() < mascorto.length())
        {
            mascorto = values[i];
        }
    }

    return mascorto;
}

int main()
{
    vector<string> values = {"hola", "adioss", "quetal", "vales", "perfecto"};
    string resultado1 = maslargo(values);
    cout << resultado1;
    cout << endl;
    string resultado2 = mascorto(values);
    cout << resultado2;
}