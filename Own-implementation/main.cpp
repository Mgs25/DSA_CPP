#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* CreateNewNode(const int&);
void DestroyTree(Node*);
Node* Insert(Node*, const int&);
Node* Delete(Node*, const int&);
int FindMin(Node*);
int FindMax(Node*);
bool Search(Node*, const int&);
void InOrder(Node*);
void PreOrder(Node*);
void PostOrder(Node*);
int GetHeight(Node*);
bool IsEmpty(Node*);
void LevelOrder(Node*);


Node* CreateNewNode(const int& data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = nullptr;
    return new_node;
}

void DestroyTree(Node* root) {
    if (root == nullptr)
        return;
    DestroyTree(root->left);
    DestroyTree(root->right);
    delete root;
    root = nullptr;
}

Node* Insert(Node* root, const int& data) {
    if (root == nullptr)
        root = CreateNewNode(data);
    else if (root->data > data)
        root->left = Insert(root->left, data);
    else
        root->right = Insert(root->right, data);
    return root;
}

Node* Delete(Node* root, const int& data) {
    if (root == nullptr)
        return nullptr;
    else if (root->data > data)
        root->left = Delete(root->left, data);
    else if (root->data < data)
        root->right = Delete(root->right, data);
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }
        else if (root->left == nullptr) {
            Node* parent = root;
            root = root->right;
            delete parent;
        }
        else if (root->right == nullptr) {
            Node* parent = root;
            root = root->left;
            delete parent;
        }
        else {
            int minValue = FindMin(root->right);
            root->data = minValue;
            root->right = Delete(root->right, minValue);
        }
    }
    return root;
}

bool Search(Node* root, const int& data) {
    if (root == nullptr)
        return false;
    else if (root->data == data)
        return true;
    else if (root->data > data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int FindMin(Node* root) {
    if (root == nullptr)
        return -1;
    else if (root->left == nullptr)
        return root->data;
    return FindMin(root->left);
}

int FindMax(Node* root) {
    if (root == nullptr)
        return -1;
    else if (root->right == nullptr)
        return root->data;
    return FindMax(root->right);
}

void InOrder(Node* root) {
    if (root == nullptr)
        return;
    InOrder(root->left);
    cout << root->data << ' ';
    InOrder(root->right);
}

void PreOrder(Node* root) {
    if (root == nullptr)
        return;
    cout << root->data << ' ';
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Node* root) {
    if (root == nullptr)
        return;
    PreOrder(root->left);
    PreOrder(root->right);
    cout << root->data << ' ';
}

void LevelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> Q;
    Q.push(root);
    
    while (!Q.empty()) {
        Node* current = Q.front();
        cout << current->data << ' ';
        if (current->left != nullptr) Q.push(current->left);
        if (current->right != nullptr) Q.push(current->right);
        Q.pop();
    }
}

int GetHeight(Node* root) {
    if (root == nullptr)
        return -1;
    return max(GetHeight(root->left), GetHeight(root->right)) + 1;
}

bool IsEmpty(Node* root) {
    return root == nullptr;
}

bool IsBstUtil(Node* root, int minValue, int maxValue) {
    if (root == nullptr)
        return true;
    else if (root->data > minValue && root->data < maxValue 
            && IsBstUtil(root->left, minValue, root->data)
            && IsBstUtil(root->right, root->data, maxValue))
        return true;
    else
        return false;
}

bool IsBst(Node* root) {
    return IsBstUtil(root, INT_MIN, INT_MAX);
}

int main() {
Node* root = nullptr;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 8);
    root = Insert(root, -1);
    root = Insert(root, 99);
    root = Insert(root, 25);

    PreOrder(root); cout << endl;
    InOrder(root); cout << endl;
    PostOrder(root); cout << endl;
    LevelOrder(root); cout << endl;
    
    DestroyTree(root);
    return 0;
}