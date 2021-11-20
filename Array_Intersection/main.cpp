#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

vector<int> get_intersection(const vector<int>& a, const vector<int>& b) {
    map<int, int> m;
    vector<int> result;
    
    for (const int& x: a)
        m[x] = 1;
    for (const int& x: b)
        if (m[x])
            m[x] = 2;
    for (const auto& p: m)
        if (p.second == 2)
            result.push_back(p.first);
    
    return result;
}

int main() {
    vector<int> a { 1, 2, 3, 4, 5 };
    vector<int> b { 6, 3, 6, 8, 12, 123, 12343, 123 };
    
    for (auto x: get_intersection(a, b)) {
        cout << x << ' ';
    }
    
    return 0;
}