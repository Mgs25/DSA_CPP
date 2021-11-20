#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

BstNode* createNewNode(const int& data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

BstNode* Insert(BstNode* root, const int& data) {
    if (root == nullptr)
        root = createNewNode(data);
    else if (root->data > data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

void InOrderTraversal(BstNode* root) {
    if (root == nullptr)
        return;
    InOrderTraversal(root->left);
    cout << root->data << ' ';
    InOrderTraversal(root->right);
}



int main() {
    BstNode* root;
    for (int i = 1; i <= 10; i++) {
        Insert(root, i);
    }
    InOrderTraversal(root);
    return 0;
}