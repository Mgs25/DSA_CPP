#include <iostream>
using namespace std;

auto header {
    []() {
        cout << "=======================================================" << endl;
    }
};

struct Node {
    int data;
    Node* link;
};

class Linked_List {
    Node* head;
    unsigned count;
    
    void create_node(const int& x) {
        head = new Node();
        head->data = x;
        head->link = NULL;
        count = 1;
    }
    
public:
    Linked_List() {
        head = NULL;
        count = 0;
    }
    
    void insert(const size_t& pos, const int& x) {
        if (pos > count || count == 0) {
            return;
        }
        
        if (pos == 0) {
            prepend(x);
            return;
        }
        
        size_t current_pos {0};
        Node* current = head;
        
        while (current_pos != pos - 1) {
            current = current->link;
            current_pos++;
        }
        
        Node* T = new Node();
        T->data = x;
        T->link = current->link;
        current->link = T;
    }
    
    void prepend(const int& x) {
        if (head == NULL) {
            create_node(x);
        }
        else {
            Node* T = new Node();
            T->data = x;
            T->link = head;
            head = T;
            count++;
        }
    }
    
    void append(const int& x) {
        if (head == NULL) {
            create_node(x);
        }
        else {
            Node* T = new Node();
            T->data = x;
            T->link = NULL;
            
            Node* current = head;
            
            while (current->link != NULL) {
                current = current->link;
            }
            
            current->link = T;
        }
        count++;
    }
    
    void remove(const int& x) {
        Node* current = head;
        
        if (head->data == x) {
            Node* T = head->link;
            delete head;
            head = T;
            count--;
        }
        else {
            while (current != NULL) {
                if (current->link != NULL && (current->link)->data == x) {
                    Node* T;
                    T = current->link;
                    current->link = T->link;
                    delete T;
                    count--;
                    break;
                }
                current = current->link;
            }
        }
    }
    
    void display() const {
        Node* current = head;
        
        cout << "HEAD -> ";
        
        while (current != NULL) {
            cout << current->data << " -> ";
            current = current->link;
        }
        
        cout << "NULL" << endl;
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
    
    int value {}, ch {};
    size_t idx {};
    
    do {
        system("cls");
        header();
        my_list.display();
        header();
        cout << "1. Prepend element to LL" << endl;
        cout << "2. Append element to LL" << endl;
        cout << "3. Remove element from LL" << endl;
        cout << "4. Insert element to LL" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        
        if (ch == 1) {
            cout << "Enter element to prepend: ";
            cin >> value;
            my_list.prepend(value);
        }
        else if (ch == 2) {
            cout << "Enter element to append: ";
            cin >> value;
            my_list.append(value);
        }
        else if (ch == 3) {
            cout << "Enter element to remove: ";
            cin >> value;
            my_list.remove(value);
        }
        else if (ch == 4) {
            cout << "Enter insertion index: ";
            cin >> idx;
            cout << "Enter element to insert: ";
            cin >> value;
            my_list.insert(idx, value);
        }
        system("pause");
    } while (ch != 5);
    
    // display
    // prepend
    // append
    // remove
    // insert
    
    return 0;
}