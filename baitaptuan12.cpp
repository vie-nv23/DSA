#include <iostream>

using namespace std;

void xuatMang(int a[],
               int n)
{
    for (int i = 0;
         i < n;
         i++)
    {
        cout << a[i]
             << " ";
    }

    cout << endl;
}

int main()
{
    int a[] =
    {
        203, 106, 78, 84,
        39, 15, 32, 16,
        10, 17, 38, 11
    };

    int n =
        sizeof(a)
        / sizeof(a[0]);

    cout
        << "Mảng bd:"
        << endl;

    xuatMang(a, n);

    return 0;
}