#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Circular_Linked_List {
    Node* head;
    Node* CreateNewNode(const int& value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->next = head;
        return new_node;
    }
public:
    Circular_Linked_List() {
        head = nullptr;
    }
    
    void Insert(const int& value) {
        if (head == nullptr) {
            head = CreateNewNode(value);
            head->next = head;
        }
        else {
            Node* T = head;
            while (T->next != head) {
                T = T->next;
            }
            T->next = CreateNewNode(value);
        }
    }
    
    void Delete(const int& value) {
        if (head == nullptr) return;
        else if (head->data == value) {
            if (head->data != head->next->data) {
                Node* T = head->next;
                while (T->next != head) {
                    T = T->next;
                }
                Node* del = head;
                head = head->next;
                delete del;
                T->next = head;
            }
            else {
                delete head;
                head = nullptr;
            }
        }
        else {
            Node* T = head;
            while (T != nullptr) {
                if (T->next->data == value) {
                    Node* del = T->next;
                    T->next = del->next;
                    delete del;
                    break;
                }
                T = T->next;
            }
        }
    }
    
    int GetNext(const int& value) {
        if (head == nullptr) return -1;
        else if (head->data == value) {
            return head->next->data;
        }
        Node* T = head->next;
        while (T != head) {
            if (T->data == value)
                return T->next->data;
            T = T->next;
        }
        return -1;
    }
    
    void Display() const {
        if (head == nullptr) return;
        Node* T = head;
        while (T->next != head) {
            cout << T->data << ' ';
            T = T->next;
        }
        cout << T->data;
    }
    
    ~Circular_Linked_List() {
        if (head != nullptr) {
            Node* T = head->next;
            while (T != head) {
                Node* next = T->next;
                delete T;
                T = next;
            }
            delete head;
        }
    }
};

typedef Circular_Linked_List CLL;

int main() {
    CLL MyList;
    
    for (const int& i: { 1, 2, 3, 4, 5 } ) {
        MyList.Insert(i);
    }
    
    //MyList.Display();
    MyList.Delete(1);
    MyList.Display();
    
    cout << endl << MyList.GetNext(5) << endl;
    
    return 0;
}