#include <iostream>

using namespace std;

struct Node
{
    int namSinh;

    Node* left;
    Node* right;
};

Node* taoNode(int x)
{
    Node* p = new Node;

    p->namSinh = x;

    p->left = NULL;
    p->right = NULL;

    return p;
}
void chenNode(Node*& root,
              int x)
{
    if (root == NULL)
    {
        root = taoNode(x);
    }
    else
    {
        if (x <= root->namSinh)
        {
            chenNode(root->left,
                     x);
        }
        else
        {
            chenNode(root->right,
                     x);
        }
    }
}
void NLR(Node* root)
{
    if (root != NULL)
    {
        cout
            << root->namSinh
            << " ";

        NLR(root->left);

        NLR(root->right);
    }
}
Node* timKiem(Node* root,
              int x)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->namSinh == x)
    {
        return root;
    }

    Node* p;

    if (x < root->namSinh)
    {
        p = timKiem(root->left,
                    x);

        return p;
    }

    if (x > root->namSinh)
    {
        p = timKiem(root->right,
                    x);

        return p;
    }

    return NULL;
}
int main()
{
    Node* root = NULL;

    chenNode(root, 2001);
    chenNode(root, 2002);
    chenNode(root, 2006);
    chenNode(root, 2007);
    chenNode(root, 2003);
    chenNode(root, 2004);
    chenNode(root, 2005);
    chenNode(root, 2001);
    chenNode(root, 1999);
    chenNode(root, 2004);

    cout
        << "duyet cay theo NLR: " << endl;
    NLR(root);
    cout << endl;

Node* p;

p = timKiem(root, 2004);

if (p != NULL)
{
    cout
        << "Tim thay sinh vien 2004"
        << endl;
}
else
{
    cout
        << "Khong tim thay sinh vien 2004"
        << endl;
}

    return 0;
}