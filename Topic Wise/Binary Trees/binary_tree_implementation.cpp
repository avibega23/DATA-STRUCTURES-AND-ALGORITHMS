#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data)
        {
            this->data = data;
            left = right = NULL;
        }

};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(7);

    root->left->left = new Node(8);
    root->left->right = new Node(9);
    root->left->left->left  = NULL;
    root->left->left->right = NULL;
    root->right->left = NULL;
    root->right->right = NULL;

    cout << root->right->data;
    return 0;
}