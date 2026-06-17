#include <iostream>

using namespace std;
int q[100];

int dau = 0;
int cuoi = -1;
struct Node
{
    int data;

    Node* next;
};

Node* taoNode(int x)
{
    Node* p = new Node;

    p->data = x;

    p->next = NULL;

    return p;
}

void themCuoi(Node*& head,
              int x)
{
    Node* p =
        taoNode(x);

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        Node* t =
            head;

        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = p;
    }
}
void BFS(int ke[][11],
         string ten[])
{
    int daTham[11];

    for (int i = 0;
         i < 11;
         i++)
    {
        daTham[i] = 0;
    }

    cuoi++;

    q[cuoi] = 0;

    daTham[0] = 1;

    while (dau <= cuoi)
    {
        int u =
            q[dau];

        dau++;

        cout
            << ten[u]
            << endl;

        for (int v = 0;
             v < 11;
             v++)
        {
            if (ke[u][v] == 1 &&
                daTham[v] == 0)
            {
                cuoi++;

                q[cuoi] = v;

                daTham[v] = 1;
            }
        }
    }
}

int main()
{
    string ten[11] =
        {
            "Ha Noi",
            "Hai Duong",
            "Phu Ly",
            "Hung Yen",
            "Hai Phong",
            "Uong Bi",
            "Bac Giang",
            "Bac Ninh",
            "Thai Nguyen",
            "Son Tay",
            "Hoa Binh"};

    int ke[11][11];
    Node* dsKe[11];

for (int i = 0;
     i < 11;
     i++)
{
    dsKe[i] = NULL;
}

    for (int i = 0;
         i < 11;
         i++)
    {
        for (int j = 0;
             j < 11;
             j++)
        {
            ke[i][j] = 0;
        }
    }

    ke[0][1] = 1;
    ke[1][0] = 1;

    ke[0][2] = 1;
    ke[2][0] = 1;

    ke[0][10] = 1;
    ke[10][0] = 1;

    ke[0][9] = 1;
    ke[9][0] = 1;

    ke[0][8] = 1;
    ke[8][0] = 1;

    ke[0][7] = 1;
    ke[7][0] = 1;

    ke[2][3] = 1;
    ke[3][2] = 1;

    ke[3][1] = 1;
    ke[1][3] = 1;

    ke[1][4] = 1;
    ke[4][1] = 1;

    ke[7][6] = 1;
    ke[6][7] = 1;

    ke[6][5] = 1;
    ke[5][6] = 1;

    ke[7][5] = 1;
    ke[5][7] = 1;

    ke[5][4] = 1;
    ke[4][5] = 1;


    themCuoi(dsKe[0], 1);
    themCuoi(dsKe[1], 0);

    themCuoi(dsKe[0], 2);
    themCuoi(dsKe[2], 0);

    themCuoi(dsKe[0], 10);
    themCuoi(dsKe[10], 0);

    themCuoi(dsKe[0], 9);
    themCuoi(dsKe[9], 0);

    themCuoi(dsKe[0], 8);
    themCuoi(dsKe[8], 0);

    themCuoi(dsKe[0], 7);
    themCuoi(dsKe[7], 0);

    themCuoi(dsKe[2], 3);
    themCuoi(dsKe[3], 2);

    themCuoi(dsKe[3], 1);
    themCuoi(dsKe[1], 3);

    themCuoi(dsKe[1], 4);
    themCuoi(dsKe[4], 1);

    themCuoi(dsKe[7], 6);
    themCuoi(dsKe[6], 7);

    themCuoi(dsKe[6], 5);
    themCuoi(dsKe[5], 6);

    themCuoi(dsKe[7], 5);
    themCuoi(dsKe[5], 7);

    themCuoi(dsKe[5], 4);
    themCuoi(dsKe[4], 5);
    cout
        << "Danh sach tp:"
        << endl;

    for (int i = 0;
         i < 11;
         i++)
    {
        cout
            << i
            << " "
            << ten[i]
            << endl;
    }
    cout << "BFS: " << endl;
    BFS(ke, ten);
    cout
    << endl;

cout
    << "Danh sach lien ket:"
    << endl;

for (int i = 0;
     i < 11;
     i++)
{
    cout
        << ten[i]
        << ": ";

    Node* p =
        dsKe[i];

    while (p != NULL)
    {
        cout
            << ten[p->data]
            << " ";

        p = p->next;
    }

    cout
        << endl;
}
    return 0;
}