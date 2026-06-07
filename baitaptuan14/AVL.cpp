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

int main()
{
    Node* root = NULL;

    root = taoNode(32);

    cout
        << root->data
        << endl;

    return 0;
}