#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long FactorialRecursive(long long n) {
    if (n <= 1)
        return 1;
    return n * FactorialRecursive(n - 1);
}

long long FibonacciRecursive(long long n) {
    if (n == 0)
        return 0;
    else if (n <= 2)
        return 1;
    return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

int main() {
    cout << FactorialRecursive(3) << endl;
    cout << FibonacciRecursive(6) << endl;
    return 0;
}