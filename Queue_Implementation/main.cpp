#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* link;
};

class Queue {
    Node *first, *last;
    size_t size;
public:
    Queue() {
        first = last = NULL;
        size = 0;
    }
    
    void enqueue(const int& value) {
        Node* new_node = new Node();
        new_node->data = value;
        new_node->link = NULL;
        
        if (first == NULL) {
            first = last = new_node;
        }
        else {
            last->link = new_node;
            last = new_node;
        }
        ++size;
    }
    
    void dequeue() {
        if (first == NULL) {
            cout << "Queue underflow." << endl;
        }
        else {
            Node* T = first;
            first = first->link;
            delete T;
            --size;
        }
    }
    
    bool isEmpty() const {
        return (first == NULL);
    }
    
    size_t getSize() const {
        return size;
    }
    
    int peek() const {
        if (!isEmpty()) {
            return first->data;
        }
        return -1;
    }
    
    void display() const {
        Node* T = first;
        cout << "Front -> ";
        
        while (T != NULL) {
            cout << T->data << ' ';
            T = T->link;
        }
        
        cout << "<- Rear" << endl;
    }
    
    ~Queue() {
        delete first;
        if (!last)
            delete last;
    }
};

int main() {
    Queue q;
    
//    cout << "Insertion: \n";
//    for (int i = 1; i <= 5; i++) {
//        q.enqueue(i * 10);
//        q.display();
//    }
//    
//    cout << "Deletion: \n";
//    while (!q.isEmpty()) {
//        q.display();
//        q.dequeue();
//    }

    q.enqueue(10);
    q.display();
    q.dequeue();
    
    
    return 0;
}