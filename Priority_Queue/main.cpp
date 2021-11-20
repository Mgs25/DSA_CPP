#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue<int> pq) {
    while (!pq.empty()) {
        cout << '\t' << pq.top();
        pq.pop();
    }
    cout << '\n';
}

int main() {
    priority_queue<int> q;
    
    q.push(1310);
    q.push(1610);
    q.push(1308);
    q.push(61880);
    q.push(14530);
    q.push(41130);
    
    showpq(q);
    
    return 0;
}