#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

class Doubly_Linked_List {
    Node* head;
    Node* tail;
public:
    Doubly_Linked_List() {
        head = tail = NULL;
    }
    
    void prepend(const int& data) {
        Node* T = new Node(data);
        if (head == NULL) {
            head = tail = T;
        }
        else {
            head->prev = T;
            T->next = head;
            head = T;
        }
    }
    
    void append(const int& data) {
        Node* T = new Node(data);
        if (head == NULL) {
            head = tail = T;
        }
        else {
            tail->next = T;
            T->prev = tail;
            tail = tail->next;
        }
    }
    
    void insert(const int& data, const size_t& pos) {
        if (head == NULL || pos < 0) {
            return;
        }
        else if (pos == 0) {
            prepend(data);
        }
        else {
            Node* T = head;
            size_t current {0};
            
            while (T->next != NULL && current < pos - 1) {
                T = T->next;
                current++;
            }
            
            if (T->next == NULL) {
                append(data);
            }
            else if (T != NULL) {
                Node* new_node = new Node(data);
                new_node->prev = T;
                new_node->next = T->next;
                T->next->prev = new_node;
                T->next = new_node;
            }
        }
    }
    
    void remove(const int& data) {
        if (head == NULL)
            return;
        
        Node* T = head;
        
        while (T != NULL) {
            if (T->data == data)
                break;
            T = T->next;
        }
        
        if (T != NULL) {
            Node* current = T;
            if (T->prev == NULL) {
                head  = head->next;
            }
            else if (T->next == NULL) {
                T->prev->next = NULL;
            }            
            else {
                T->next->prev = T->prev;
                T->prev->next = T->next;
            }
            delete current;
        }
    }
    
    void reverse() {
        Node *n, *c;
        c = head;
        
        while (c != NULL) {
            n = c->next;
            c->next = c->prev;
            c->prev = n;
            c = n;
        }
        
        head = tail;
    }
    
    void display() const {
        for (Node* T = head; T != NULL; T = T->next) {
            cout << T->data << ' ';
        }
        cout << endl;
    }
    
    void get_neighbours(const int& value) const {
        for (Node* T = head; T != NULL; T = T->next) {
            if (T->data == value) {
                Node *prev_node = T->prev, *next_node = T->next;
                cout << "Previous : " << (prev_node != NULL ? to_string(prev_node->data) : "NULL") << endl;
                cout << "Next     : " << (next_node != NULL ? to_string(next_node->data) : "NULL") << endl;
            }
        }
    }
    
    ~Doubly_Linked_List() {
        Node* T = head;
        while (T != NULL) {
            Node* next_node = T->next;
            delete T;
            T = next_node;
        }
    }
};

int main() {
    Doubly_Linked_List D;
    
    D.prepend(10);
    D.prepend(40);
    D.prepend(50);
    D.display();
    //D.get_neighbours(50);
    D.reverse();
    D.display();
    
    return 0;
}