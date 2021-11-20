#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
    int* data;
    int capacity, top;
    
    void allocate_memory() {
        capacity *= 2;
        int* T = new int[capacity];
        
        for (int i = 0; i < top; i++) {
            T[i] = data[i];
        }
        
        delete data;
        data = T;
    }
public:
    Stack(int capacity = 64) : capacity { capacity }, top { -1 } {
        data = new int[capacity];
    }
    
    void push(const int& value) {
        if (top + 1 > capacity)
            allocate_memory();
        data[++top] = value;
    }
    
    void pop() {
        if (top < 0) {
            cout << "Stack underflow." << endl;
        }
        else {
            --top;
        }
    }
    
    bool isEmpty() const {
        return top == -1;
    }
    
    int peek() const {
        if (top >= 0)
            return data[top];
        return -1;
    }
    
    ~Stack() {
        delete data;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << s.peek();
    
    return 0;
}