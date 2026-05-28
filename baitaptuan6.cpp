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
};

Node* taoNode(File x)
{
    Node* p = new Node;

    if (p == NULL)
        return NULL;

    p->data = x;
    p->next = NULL;

    return p;
}

void chenTheoThoiGian(Node*& head, File x)
{
    Node* p = taoNode(x);

    // Danh sach rong
    if (head == NULL)
    {
        head = p;
        return;
    }

    // Chen vao dau
    if (x.thoiGian < head->data.thoiGian)
    {
        p->next = head;
        head = p;
        return;
    }

    // Tim vi tri chen
    Node* temp = head;

    while (temp->next != NULL &&
           temp->next->data.thoiGian < x.thoiGian)
    {
        temp = temp->next;
    }

    // Chen vao giua hoac cuoi
    p->next = temp->next;
    temp->next = p;
}

double tinhTongKichThuoc(Node* head)
{
    double tong = 0;

    Node* p = head;

    while (p != NULL)
    {
        tong += p->data.kichThuoc;
        p = p->next;
    }

    return tong;
}

Node* timFileNhoNhat(Node* head)
{
    if (head == NULL)
        return NULL;

    Node* minNode = head;
    Node* p = head->next;

    while (p != NULL)
    {
        if (p->data.kichThuoc <
            minNode->data.kichThuoc)
        {
            minNode = p;
        }

        p = p->next;
    }

    return minNode;
}

void hienThi(Node* head)
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
}

int main()
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

    File f3 =
    {
        "Video.mp4",
        200,
        "2026-05-28 10:45"
    };

    chenTheoThoiGian(head, f1);
    chenTheoThoiGian(head, f2);
    chenTheoThoiGian(head, f3);

    hienThi(head);

    cout << "Tong kich thuoc: "
         << tinhTongKichThuoc(head)
         << " MB"
         << endl;

    Node* minFile = timFileNhoNhat(head);

    cout << "File nho nhat: "
         << minFile->data.tenFile
         << endl;

    return 0;
}