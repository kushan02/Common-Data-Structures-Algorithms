#include <bits/stdc++.h>

using namespace std;

map<pair<long long, long long>, long long> dp;

long long binomial(long long n, long long r) {
    if (r == 0) return 1;
    if (n == r) return 1;

    if (dp[make_pair(n, r)]) return dp[make_pair(n, r)];
    else {
        long long ans = binomial(n - 1, r) + binomial(n - 1, r - 1);
        dp[make_pair(n, r)] = ans;
        return ans;
    }
}


int main() {

    cout << binomial(6, 3);

    return 0;
}