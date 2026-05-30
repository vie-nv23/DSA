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
void doiCho(int& a,
            int& b)
{
    int t = a;
    a = b;
    b = t;
}

void vunDong(int a[],
             int n,
             int i)
{
    int max = i;

    int left =
        2 * i + 1;

    int right =
        2 * i + 2;

    if (left < n &&
        a[left] > a[max])
    {
        max = left;
    }

    if (right < n &&
        a[right] > a[max])
    {
        max = right;
    }

    if (max != i)
    {
        doiCho(a[i],
               a[max]);

        vunDong(a,
                n,
                max);
    }
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
for (int i =
     n / 2 - 1;
     i >= 0;
     i--)
{
    vunDong(a,
            n,
            i);

    cout
        << "Vun dong "
        << i
        << ": "
        << endl;

    xuatMang(a,
             n);
}
for (int i =
     n - 1;
     i > 0;
     i--)
{
    doiCho(a[0],
           a[i]);

    cout
        << "doi cho ptu:"
        << endl;

    xuatMang(a,
             n);

    vunDong(a,
            i,
            0);

    cout
        << "Vun dong again:"
        << endl;

    xuatMang(a,
             n);
}

cout
    << "Mang sap xep:"
    << endl;

xuatMang(a,
         n);
    return 0;
}
