#include <iostream>

using namespace std;

struct DonThuc
{
    float HeSo;
    int SoMu;
};

struct DaThuc
{
    DonThuc a[100];
    int n;
};

void nhapDaThuc(DaThuc& p)
{
    cout << "Nhap so luong don thuc: ";
    cin >> p.n;

    for (int i = 0; i < p.n; i++)
    {
        cout << "Don thuc thu "
             << i + 1
             << endl;

        cout << "He so: ";
        cin >> p.a[i].HeSo;

        cout << "So mu: ";
        cin >> p.a[i].SoMu;
    }
}

void hienThiDaThuc(DaThuc p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.a[i].HeSo
             << "x^"
             << p.a[i].SoMu;

        if (i < p.n - 1)
        {
            cout << " + ";
        }
    }

    cout << endl;
}

int main()
{
    DaThuc p;

    nhapDaThuc(p);

    cout << "Da thuc vua nhap: ";
    hienThiDaThuc(p);

    return 0;
}