#include <iostream>
#include <map>
#include <vector>

using namespace std;

int first_repeating_element(const vector<int>& v) { // O(n)
    map<int, int> m;
    for (const int& x: v) {
        if (m[x])
            return x;
        m[x]++;
    }
    return -1;
}

int challenge(const vector<int>& v) {
    int n = v.size();
    int result = -1;
    int idx = v.size();
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] == v[j] && j < idx) {
                result = v[i]; 
                idx = j;
            }
        }
    }
    
    return result;
}

int main() {
    auto result = challenge( vector<int> { 12, 4, 3, 1, 4, 5 } );
    cout << result << endl;
    
    return 0;
}