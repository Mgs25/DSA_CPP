#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
    
    Node(int x) {
        data = x;
        link = NULL;
    }
};

class Linked_List {
    Node* head;
    Node* tail;
public:
    Linked_List() {
        head = NULL;
        tail = NULL;
    }
    
    void prepend(const int& x) {        
        if (head == NULL) {
            head = new Node(x);
            tail = head;
        }
        else {
            Node* new_node = new Node(x);
            new_node->link = head;
            head = new_node;
        }
    }
    
    void append(const int& x) {
        if (head == NULL) {
            head = new Node(x);
            tail = head;
        }
        else {
            Node* new_node = new Node(x);
            tail->link = new_node;
            tail = tail->link;
        }
    }
    
    void insert(const size_t& index, const int& value) {
        if (head == NULL) {
            return;
        }
        else if (index == 0) {
            prepend(value);
        }
        else {
            size_t current {0};
            Node* new_node = new Node(value);
            Node* T = head;
            
            while (T != NULL && current < index - 1) {
                T = T->link;
                current++;
            }

            if (T != NULL) {
                new_node->link = T->link;
                T->link = new_node;
            }
        }
    }
    
    void remove(const size_t& index) {
        Node* T = head;
        if (T == NULL) {
            return;
        }
        else if (index == 0) {
            head = head->link;
            delete T;
        }
        else {
            size_t current {0};
            
            while (T != NULL && current < index - 1) {
                T = T->link;
                current++;
            }
            
            if (T != NULL && T->link != NULL) {
                Node* del = T->link;
                T->link = T->link->link;
                delete del;
            }
        }
    }
    
    void reverse() {
        Node *n, *p, *c;
        c = head;
        p = NULL;

        while (c != NULL) {
            n = c->link;
            c->link = p;
            p = c;
            c = n;
        }
        
        head = tail;
    }
    
    void display() const {
        Node* current = head;
        
        while (current != NULL) {
            cout << current->data << ' ';
            current = current->link;
        }
        
        cout << endl;
    }
    
    ~Linked_List() {
        Node* current = head;
        
        while (current != NULL) {
            Node* next = current->link;
            delete current;
            current = next;
        }
    }
};

typedef Linked_List LL;

int main() {
    LL my_list;
    
    my_list.append(1);
    my_list.append(3);
    my_list.append(4);
    my_list.display();
    my_list.reverse();
    my_list.display();
    
    
    return 0;
}