#include<bits/stdc++.h>

using namespace std;

// Recursive
long long factorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {

    int n;
    cin >> n;

    // Iterative
    long long ans = 1;
    for (int i = 2; i <= n; ++i)
        ans *= i;

    cout << ans << endl;
    cout << factorial(n);

    return 0;
}