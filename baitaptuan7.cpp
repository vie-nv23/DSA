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
DaThuc congDaThuc(DaThuc p, DaThuc q)
{
    DaThuc r;
    r.n = 0;

    int i = 0;
    int j = 0;

    while (i < p.n && j < q.n)
    {
        // Cung so mu
        if (p.a[i].SoMu == q.a[j].SoMu)
        {
            r.a[r.n].HeSo =
                p.a[i].HeSo + q.a[j].HeSo;

            r.a[r.n].SoMu =
                p.a[i].SoMu;

            r.n++;
            i++;
            j++;
        }

        // P co so mu lon hon
        else if (p.a[i].SoMu >
                 q.a[j].SoMu)
        {
            r.a[r.n] = p.a[i];

            r.n++;
            i++;
        }

        // Q co so mu lon hon
        else
        {
            r.a[r.n] = q.a[j];

            r.n++;
            j++;
        }
    }

    // Them phan con lai cua P
    while (i < p.n)
    {
        r.a[r.n] = p.a[i];

        r.n++;
        i++;
    }

    // Them phan con lai cua Q
    while (j < q.n)
    {
        r.a[r.n] = q.a[j];

        r.n++;
        j++;
    }

    return r;
}
int main()
{
    DaThuc p;
    DaThuc q;
    DaThuc r;

    cout << "Nhap da thuc P:" << endl;
    nhapDaThuc(p);

    cout << "Nhap da thuc Q:" << endl;
    nhapDaThuc(q);

    cout << "Da thuc P: ";
    hienThiDaThuc(p);

    cout << "Da thuc Q: ";
    hienThiDaThuc(q);

    r = congDaThuc(p, q);

    cout << "Tong hai da thuc: ";
    hienThiDaThuc(r);

    return 0;
}