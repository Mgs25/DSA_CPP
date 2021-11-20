#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> mergeSortedArray(const vector<int>& a, const vector<int>& b) {
    vector<int> result {};
    size_t i {0}, j {0};
    
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            result.push_back(a[i]);
            result.push_back(b[j]);
            i++; j++;
        }
        else if (a[i] < b[j]) {
            result.push_back(a[i]);
            i++;
        }
        else {
            result.push_back(b[j]);
            j++;
        }
    }
    
    while (i < a.size()) {
        result.push_back(a[i]);
        i++;
    }
    
    while (j < b.size()) {
        result.push_back(b[j]);
        j++;
    }

    return result;
}

int main() {
    auto res = mergeSortedArray(vector<int> {1, 2, 3, 6, 12, 32, 67, 125, 169}, 
                                vector<int> {2, 5, 6, 14, 18, 65, 123, 434});
    
    for (int x: res)
        cout << x << ' ';
    
    return 0;
}