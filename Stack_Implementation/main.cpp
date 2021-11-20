#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Stack implementation using linked list

struct Node {
    int data;
    Node* link;
};

class Stack {
    Node *top, *bottom;
    size_t size;
public:
    Stack() {
        top = bottom = NULL;
        size = 0;
    }
    
    void push(const int& data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->link = top;
        size = size + 1;
        
        if (top == NULL) {
            top = bottom = new_node;
        }
        else {
            new_node->link = top;
            top = new_node;
        }
    }
    
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow." << endl;
            return;
        }
        
        if (top == bottom)
            bottom = NULL;
        
        size = size - 1;
        Node* temp;
        temp = top;
        top = top->link;
        delete temp;
    }
    
    int peek() const {
        if (!isEmpty())
            return top->data;
        else
            return -1;
    }
    
    bool isEmpty() const {
        return top == NULL;
    }
    
    size_t getSize() const {
        return size;
    }
    
    ~Stack() {
        delete top;
        delete bottom;
    }
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    
    while (!s.isEmpty()) {
        cout << "SIZE: " << s.getSize() << endl;
        cout << s.peek() << endl;
        s.pop();
    }
    
    return 0;
}