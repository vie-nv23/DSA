#include <iostream>
#include <cstring>

using namespace std;

struct Ngay
{
    int ngay;
    int thang;
    int nam;
};

struct SinhVien
{
    char maSV[20];
    char hoTen[50];
    int gioiTinh;
    Ngay ngaySinh;
    char diaChi[100];
    char lop[12];
    char khoa[20];
};

struct Node
{
    SinhVien data;
    Node* link;
};

struct List
{
    Node* first;
    Node* last;
};

void khoiTao(List& l)
{
    l.first = NULL;
    l.last = NULL;
}
Node* taoNode(SinhVien x)
{
    Node* p = new Node;

    if (p == NULL)
    {
        return NULL;
    }

    p->data = x;
    p->link = NULL;

    return p;
}

void themCuoi(List& l, SinhVien x)
{
    Node* p = taoNode(x);

    if (l.first == NULL)
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        l.last->link = p;
        l.last = p;
    }
}

void chenTheoMaSV(List& l, SinhVien x)
{
    Node* p = taoNode(x);

    // Danh sach rong
    if (l.first == NULL)
    {
        l.first = p;
        l.last = p;
    }

    // Chen vao dau
    else if (strcmp(x.maSV,
                    l.first->data.maSV) < 0)
    {
        p->link = l.first;
        l.first = p;
    }

    // Chen vao giua hoac cuoi
    else
    {
        Node* q = l.first;

        while (q->link != NULL &&
               strcmp(q->link->data.maSV,
                      x.maSV) < 0)
        {
            q = q->link;
        }

        p->link = q->link;
        q->link = p;

        if (p->link == NULL)
        {
            l.last = p;
        }
    }
}
void nhap1SinhVien(SinhVien& sv)
{
    cout << "Nhap ma sinh vien: ";
    cin.getline(sv.maSV, 20);

    cout << "Nhap ho ten: ";
    cin.getline(sv.hoTen, 50);

    cout << "Nhap gioi tinh (0-Nu, 1-Nam): ";
    cin >> sv.gioiTinh;

    cout << "Nhap ngay sinh: ";
    cin >> sv.ngaySinh.ngay;

    cout << "Nhap thang sinh: ";
    cin >> sv.ngaySinh.thang;

    cout << "Nhap nam sinh: ";
    cin >> sv.ngaySinh.nam;

    cin.ignore();

    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, 100);

    cout << "Nhap lop: ";
    cin.getline(sv.lop, 12);

    cout << "Nhap khoa: ";
    cin.getline(sv.khoa, 20);
}

void hienThiDanhSach(List l)
{
    Node* p = l.first;

    while (p != NULL)
    {
        cout << "Ma SV: "
             << p->data.maSV
             << endl;

        cout << "Ho ten: "
             << p->data.hoTen
             << endl;

        cout << "Ngay sinh: "
             << p->data.ngaySinh.ngay
             << "/"
             << p->data.ngaySinh.thang
             << "/"
             << p->data.ngaySinh.nam
             << endl;

        cout << "----------------"
             << endl;

        p = p->link;
    }
}
int main()
{
    List ListSV;

    khoiTao(ListSV);

    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        SinhVien sv;

        cout << endl;
        cout << "Nhap sinh vien thu "
             << i + 1
             << endl;

        nhap1SinhVien(sv);

        chenTheoMaSV(ListSV, sv);
    }

    cout << endl;
    cout << "Danh sach sau sap xep:"
         << endl;

    hienThiDanhSach(ListSV);

    return 0;
}