#include <iostream>

using namespace std;

struct Node
{
    int data;

    Node* left;
    Node* right;

    int height;
};

Node* taoNode(int x)
{
    Node* p = new Node;

    p->data = x;

    p->left = NULL;
    p->right = NULL;

    p->height = 1;

    return p;
}
int chieuCao(Node* p)
{
    if (p == NULL)
    {
        return 0;
    }

    return p->height;
}
int canBang(Node* p)
{
    if (p == NULL)
    {
        return 0;
    }

    int trai =
        chieuCao(p->left);

    int phai =
        chieuCao(p->right);

    return trai - phai;
}
int main()
{
    Node* root = NULL;

    root = taoNode(32);

    cout
        << "Gia tri node:" ;

    cout
        << root->data
        << endl;

    cout
        << "Chieu cao:" ;

    cout
        << chieuCao(root)
        << endl;

    cout
        << "Can bang:" ;

    cout
        << canBang(root)
        << endl;

    return 0;
}