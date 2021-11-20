#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll sum(ll N, ll M) {
    ll div = gcd(N, M);
    return (N / div) + (M / div);
}

int main() {
    cout << sum(3, 3);
    return 0;
}