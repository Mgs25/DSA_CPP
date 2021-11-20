#include <iostream>
#include <algorithm>
#include <array>
#include <string>

using namespace std;

/*
 * OPERATION TIME COMPLEXITY
 * lookup O(1)
 * push   O(1)
 * search O(n)
 * insert O(n)
 * delete O(n)
*/

int main() {
    array<int, 5> a { 1, 2, 3, 4, 5 }; // static array
    
    cout << a.at(2) << endl; // lookup O(1)
    
    for (const int& x: a)   // traverse O(n)
        cout << x << ' ';
    
    return 0;
}