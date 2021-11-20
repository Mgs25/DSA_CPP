#include <iostream>
#include <vector>
#include <stack>
#define N 64

using namespace std;

class Queue {
    int s1[N], s2[N];
    int top1, top2;
    int count;
public:
    Queue() {
        top1 = top2 = -1;
        count = 0;
    }
    
    void push1(const int& x) {
        s1[++top1] = x;
    }
    
    void push2(const int& x) {
        s2[++top2] = x;
    }
    
    int pop1() {
        return s1[top1--];
    }
    
    int pop2() {
        return s2[top2--];
    }
    
    void enqueue(const int& x) {
        if (top1 == N - 1) {
            cout << "Queue overflow." << endl;
        }
        else {
            push1(x);
            count++;
        }
    }
    
    void dequeue() {
        if (top1 == -1) {
            cout << "Queue underflow." << endl;
        }
        else {
            for (int i = 0; i < count; i++) {
                int x = pop1();
                push2(x);
            }
            
            pop2();
            count--;
            
            for (int i = 0; i < count; i++) {
                int x = pop2();
                push1(x);
            }
        }
    }
    
    void display() const {
        cout << "Front -> ";
        for (int i = 0; i < count; i++) {
            cout << s1[i] << ' ';
        }
        cout << "<- Rear" << endl;
    }
};

int main() {
    Queue q;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.display();
    
    return 0;
}