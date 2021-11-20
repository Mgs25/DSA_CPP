#include <iostream>
#include <string>

template <typename T>
void swap(T& a, T& b) {
    int t { a };
    a = b;
    b = t;
}

void reverse(std::string& s) {
    for (size_t i {0}; i < s.size() / 2; i++) {
        swap(s[i], s[s.size() - i - 1]);
    }
}

int main() {
    std::string s { "AB" };
    std::cout << s << std::endl;
    reverse(s);
    std::cout << s << std::endl;
    return 0;
}