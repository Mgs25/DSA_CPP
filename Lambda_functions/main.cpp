#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) : data { value }, next { NULL } { }
};

class Linked_List {
    Node *head, *tail;
public:
    Linked_List() {
        head = tail = NULL;
    }
    
    void prepend(const int& value) {
        if (head == NULL) {
            head = new Node(value);
            tail = head;
        }
        else {
            Node* T = new Node(value);
            T->next = head;
            head = T;
        }
    }
    
    void append(const int& value) {
        if (head == NULL) {
            head = new Node(value);
            tail = head;
        }
        else {
            Node* T = new Node(value);
            tail->next = T;
            tail = T;
        }
    }
    
    void display() const {
        Node* T = head;
        
        while (T != NULL) {
            cout << T->data << ' ';
            T = T->next;
        }
    }
    
    ~Linked_List() {
        Node* T = head;
        
        while (T != NULL) {
            Node* next_node = T->next;
            delete T;
            T = next_node;
        }
    }
};

typedef Linked_List LL;

int main() {
    LL obj;
    
    obj.prepend(10);
    obj.prepend(5);
    obj.append(15);
    
    obj.display();
    
    return 0;
}