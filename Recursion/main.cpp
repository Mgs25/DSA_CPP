#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long factorial(long long n) {
    if (n <= 1)
        return n;
    return n * factorial(n - 1);
}

long long fibonacci(long long n) {
    if (n == 0)
        return 0;
    else if (n <= 2)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

//long long fibonacci(long long n) { 
//    if (n <= 1)
//        return n;
//        
//    long long a, b, c;
//    a = 0;
//    b = 1;
//    
//    for (int i { 2 }; i <= n; i++) {
//        c = a + b;
//        a = b;
//        b = c;
//    }
//    
//    return c;
//}

//long long factorial(long long n) {
//    if (n <= 2)
//        return n;
//    long long result = 1;
//    for (int i { 2 }; i <= n; i++)
//        result *= i;
//    return result;
//}

int main() {
    cout << factorial(5) << endl;
    return 0;
}