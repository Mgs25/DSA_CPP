#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* CreateNewNode(const int&);
Node* Insert(Node*, const int&, const size_t&);
void Delete(Node*&, const int& value);
void Display(Node* root);

Node* CreateNewNode(const int& value) {
    Node* new_node = new Node();
    new_node->data = value;
    new_node->next = nullptr;
    return new_node;
}

Node* Insert(Node* head, const int& value, const size_t& pos) {
    Node* new_node = CreateNewNode(value);
    if (pos < 0)
        return nullptr;
    else if (pos == 0) {
        new_node->next = head;
        return new_node;
    }
    else {
        size_t count { 0 };
        Node* T = head;
        while (T != nullptr && count < pos - 1) {
            T = T->next;
            count++;
        }
        if (T != nullptr && count == pos - 1) {
            if (T->next == nullptr) {
                T->next = new_node;
            }
            else {
                new_node->next = T->next;
                T->next = new_node;
            }
        }
    }
    return head;
}

void Delete(Node*& head, const int& value) {
    if (head == nullptr)
        return;
    else if (head->data == value) {
        Node* next = head->next;
        delete head;
        head = next;
    }
    else {
        Node* T = head;
        while (T->next != nullptr) {
            if (T->next->data == value) {
                Node* del = T->next;
                T->next = T->next->next;
                delete del;
                break;
            }
            T = T->next;
        }
        if (T->data == value) {
            delete T;
            T = nullptr;
        }
    }
}

void Display(Node* head) {
    Node* T = head;
    while (T != nullptr) {
        cout << T->data << ' ';
        T = T->next;
    }
}

int main() {
    Node* head = nullptr;
    head = Insert(head, 10, 0);
    head = Insert(head, 140, 0);
    head = Insert(head, 14, 1);
    
    Display(head); cout << endl;
    
    Delete(head, 140);
    
    Display(head);
    
    return 0;
}