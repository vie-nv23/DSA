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
Node* xoayPhai(Node* y)
{
    Node* x =
        y->left;

    Node* t2 =
        x->right;

    x->right = y;

    y->left = t2;

    return x;
}

Node* xoayTrai(Node* x)
{
    Node* y =
        x->right;

    Node* t2 =
        y->left;

    y->left = x;

    x->right = t2;

    return y;
}
int lonHon(int a,
           int b)
{
    if (a > b)
    {
        return a;
    }

    return b;
}
Node* chenAVL(Node* root,
              int x)
{
    if (root == NULL)
    {
        return taoNode(x);
    }

    if (x < root->data)
    {
        root->left =
            chenAVL(root->left,
                    x);
    }
    else
    {
        root->right =
            chenAVL(root->right,
                    x);
    }

    root->height =
        1 +
        lonHon(chieuCao(root->left),
               chieuCao(root->right));

    return root;
}
int main()
{
    Node* root = NULL;

    root = chenAVL(root, 32);
    root = chenAVL(root, 51);
    root = chenAVL(root, 27);

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
    cout
    << "test xoay:";
    cout
    << endl;
cout
    << "Gia tri goc: "
    << root->data
    << endl;

cout
    << "Chieu cao moi: "
    << chieuCao(root)
    << endl;

    return 0;
}