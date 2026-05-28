#include <iostream>
#include <string>

using namespace std;
struct File
{
    string tenFile;
    double kichThuoc;
    string thoiGian;
};
struct Node
{
    File data;
    Node* next;
};Node* taoNode(File x)
{
    Node* p = new Node;

    if (p == NULL)
        return NULL;

    p->data = x;
    p->next = NULL;

    return p;
}void chenCuoi(Node*& head, File x)
{
    Node* p = taoNode(x);

    if (head == NULL)
    {
        head = p;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = p;
}void hienThi(Node* head)
{
    Node* p = head;

    while (p != NULL)
    {
        cout << "Ten file: "
             << p->data.tenFile
             << endl;

        cout << "Kich thuoc: "
             << p->data.kichThuoc
             << " MB"
             << endl;

        cout << "Thoi gian: "
             << p->data.thoiGian
             << endl;

        cout << "----------------"
             << endl;

        p = p->next;
    }
}int main()
{
    Node* head = NULL;

    File f1 =
    {
        "TaiLieu.pdf",
        120,
        "2026-05-28 10:30"
    };

    File f2 =
    {
        "Anh.png",
        50,
        "2026-05-28 11:00"
    };

    chenCuoi(head, f1);
    chenCuoi(head, f2);

    hienThi(head);

    return 0;
}