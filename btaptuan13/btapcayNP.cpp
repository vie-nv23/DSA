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

int main()
{
    Node* root;

    root = taoNode(2001);

    cout
        << root->namSinh
        << endl;

    return 0;
}