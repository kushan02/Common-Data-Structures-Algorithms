#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;

    if (a < b) return gcd(b, a); // handle case where a < b

    return gcd(b, a % b);

}

int main() {

    int a, b;
    cin >> a >> b;

    cout << gcd(a, b);

    // trick: __gcd(a,b) is the library function

    return 0;
}