#include <iostream>
#include <vector>

using namespace std;

void printArray(const vector<int> &vec, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void insertionsort(vector<int> &a)
{
    for (int p = 1; p < a.size(); ++p)
    {
        int tmp = std::move(a[p]);
        int j;
        for (j = p; j > 0 && tmp < a[j - 1]; --j)
        {
            a[j] = std::move(a[j - 1]);
        }
        a[j] = std::move(tmp);
    }
}

int main()
{

    vector<int> vec = {9, 5, 1, 4, 3};
    int size = vec.size();
    insertionsort(vec);
    cout << "Sorted array in ascending order:\n";
    printArray(vec, size);
}
