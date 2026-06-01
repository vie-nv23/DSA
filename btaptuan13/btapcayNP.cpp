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

    return 0;
}