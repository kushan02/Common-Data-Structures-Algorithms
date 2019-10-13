#include<bits/stdc++.h>

using namespace std;

long long power(int a, int n) {
    if (a == 1 || n == 0) return 1;
    if (a == 0) return 0;

    long long R = power(a, n / 2);

    if (n % 2 == 0)
        return R * R;
    else
        return R * a * R;
}


int main() {

    long long a = pow(32,5); // pow() is the library function
    long long b = power(32, 5);

    cout << (bool)(a==b); // verify correctness of our implementation

    // pro tip: switch to python if you think answer will overflow
    /*
    def power(a,n):
    if a == 1 or n == 0:
        return 1
    r = power(a, n//2)
    if n%2 == 0:
        return r*r
    else:
        return r*a*r

print( power(5,34) )

     */

    return 0;
}