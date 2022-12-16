#include <iostream>
#include <vector>

using namespace std;

int buscarmax(vector<int> vec)
{
    int max = vec.at(0);

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) > max)
        {
            max = vec.at(i);
        }
    }
    return max;
}

int buscarmin(vector<int> vec)
{
    int min = vec.at(0);

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) < min)
        {
            min = vec.at(i);
        }
    }
    return min;
}

int sumavec(std::vector<int> const &v, int n)
{
    if (n == 0)
    {
        return v.at(n);
    }
    else
    {
        return sumavec(v, n - 1) + v.at(n);
    }
}

int main()
{
    vector<int> mivec = {1, 2, 3, 4, 5, 11};

    cout << "El minimo del vector es: " << buscarmin(mivec) << endl;
    cout << "El maximo del vector es: " << buscarmax(mivec) << endl;
    cout << "La suma de los elementos del vector es: " << sumavec(mivec, mivec.size() - 1) << endl;
}