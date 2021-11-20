#include <iostream>
#include <vector>
#include <string>
using namespace std;

void ReverseStringRecursive(string s, size_t current = 0) {
    if (current == s.size())
        return;
    ReverseStringRecursive(s, current + 1);
    cout << s[current];
}

int main() {
    ReverseStringRecursive("Methran");
    return 0;
}