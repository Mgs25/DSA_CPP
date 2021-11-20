#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include "performance.h"

using namespace std;

void find_nemo(const vector<string>& vs) {      // O(n)
    for (const auto& i: vs) {
        if (i == "nemo") {
            cout << "Found NEMO!" << endl;
            break;
        }
    }
}

void useless_function(const vector<int>& vec) { // O(1 + 1 + 1 + n/2 + 100) -> O(103 + n / 2) 
    cout << vec.at(0) << endl;                  // -> O(n)
    
    size_t mid {vec.size() / 2};
    size_t index {0};
    
    while (index < mid) {
        cout << vec.at(index) << ' ';
        index++;
    }
    
    for (int i {0}; i < 100; i++)
        cout << "hi" << endl;
}

void compress_function(const vector<int>& vec) { // O(n)
    for (const int& element: vec)
        cout << element << endl;
    for (const int& element: vec)
        cout << element << endl;
}

void compress_function(const vector<int>& a, const vector<int>& b) {
    for (const int& element: a)
        cout << element << endl;
    for (const int& element: b)
        cout << element << endl;
}   // note: unique terms for parameters, size(a) -> n, size(b) -> m
    // O(n + m)
void nested_function(const vector<int>& a) {
    for (const int& x: a) {
        for (const int& y: a) {
            cout << x << ' ' << y << endl;
        }
    }
}   // O(n^2)

void nested_function(const vector<int>& a, const vector<int>& b) {
    for (const int& i: a) {
        for (const int& j: b) {
            cout << i * j << endl;
        }
    }
}   // Nested loop -> O(n * m)

void print_all_pairs(const vector<int>& vec) {
    for (size_t i {0}; i < vec.size(); i++) {
        for (size_t j {0}; j < vec.size(); j++) {
            cout << vec.at(i) << ' ' << vec.at(j) << endl;
        }
    }
}

void print_pair_sum(const vector<int>& vec) {
    cout << "These are the numbers: " << endl;
    for (const int& element: vec)
        cout << element << endl;
        
    cout << "These are the sums of those numbers: " << endl;
    for (const int& x: vec) {
        for (const int& y: vec) {
            cout << x << " + " << y << " = " << x + y << endl;
        }
    }
}

// space complexity functions

void boooooo(int n) {
    for (int i = 0; i < n; i++)
        cout << "boooooooo!" << endl;
}

void boo2(int n) {
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        a.at(i) = "Booo!";
    }
    for (const auto& s: a)
        cout << s << endl;
}

int main() {
    const vector<int> a { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const vector<int> b { 1, 2, 3, 4, 5 };
    
    //First function
    cout << "Find_nemo function" << endl;
    const vector<string> vec (10000, "nemo");
    find_nemo(vec); // O(n) --> Linear time
    cout << "====================" << endl;

    //Second function
    cout << "Useless function O(n)" << endl;
    useless_function(a); // O(n)
    cout << "====================" << endl;
    
    //Third function
    cout << "Compress function O(n)" << endl;
    compress_function(a); // O(n)
    cout << "====================" << endl;

    //Fourth function
    cout << "Compress function(a, b) O(n + m)" << endl;
    compress_function(a, b);  // O(n + m)
    cout << "====================" << endl;
    
    //Fifth function 
    cout << "Nested function(a) O(n ^ 2)" << endl;
    nested_function(a); // O(n ^ 2)
    cout << "====================" << endl;
    
    // Sixth function
    cout << "Nested function(a, b) O(n * m)" << endl;
    nested_function(a, b); // O(n * m)
    cout << "====================" << endl;
    
    // Seventh function
    cout << "Print_all_pairs(a) O(n ^ 2)" << endl;
    print_all_pairs(b);
    cout << "====================" << endl;
    
    // Eighth function
    cout << "Print_pair_sum(a) O(n ^ 2)" << endl;
    print_pair_sum(b);
    cout << "====================" << endl;
    
    // Nineth function
    cout << "Factorial function(a) O(n!)" << endl; 
    cout << "====================" << endl;
    
    // space complexity
    cout << "Space complexity" << endl;
    boooooo(10);
    cout << "====================" << endl;
    
    boo2(10);
    cout << "====================" << endl;
    
    vector<int> av {234, 21, 432, 657, 7567};
    auto l = *min_element(av.begin(), av.end());
    auto h = *max_element(av.begin(), av.end());
    
    cout << "MIN: " << l << endl << "MAX: " << h;
    
    return 0;
}