#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

// Hashtables, hashmaps, map, unordered_map, dictionaries are the same

/*
 * OPERATION TIME COMPLEXITY
 * lookup O(1) (sometines O(n), in case of collisions)
 * search O(1)
 * insert O(1)
 * delete O(1)
*/


int main() {
    map<int, string> m { {1, "Methran"}, {2, "Koushik"}, {3, "Sridevi"}, {4, "Gunasekaran"} };
    set<int> s {1, 2, 3, 4, 4, 5};
    
    for (auto i: m) {
        cout << m[i.first] << ' ';
    }
    
    for (auto i: s) {
        cout << i << ' ';
    }
    
    //for loop
    cout << endl;
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << ' ' << it->second << endl;
    }
    
    return 0;
}