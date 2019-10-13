#include<bits/stdc++.h>

using namespace std;

// https://riptutorial.com/algorithm/example/24653/introduction-to-rabin-karp-algorithm

long long hash_str(string str, string pattern, long long prime) {

    cout << "string = " << str << endl;
    long long ans = 0;
    for (int i = 0; i < pattern.length(); ++i) {

        cout << str[i] << "*" << prime << "^" << i << endl;
        ans += (str[i] * pow(prime, i));

    }
    return ans;
}


int main() {

    string str = "2359023141526739921";
    string pattern = "31415";
    int prime = 13;

    // str[i]*prime^0 + str[i+1]*prime^1 + str[i+2]*prime^2 + str[i+3]*prime^3 = K
    // Next Hash = str[i+1]*prime^0 + str[i+2]*prime^1 + str[i+3]*prime^2 + str[i+4]*prime^3 = K'
    //  (K - str[i])/prime + str[i+4]*prime^3 is the rolling hash
    long long pattern_hash = hash_str(pattern, pattern, prime); // hash of the pattern itself
    cout << "Pattern hash = " << pattern_hash << endl;
    long long hash = 0;

    for (int i = 0; i < str.length() - pattern.length() + 1; ++i) {

        if (i == 0) {
            hash = hash_str(str, pattern, prime);
        } else {
            hash = hash - str[i - 1];
            hash = hash / prime;
            hash = hash + str[i + pattern.length() - 1] * pow(prime, pattern.length() - 1) - 1;
            // Debug statements
//            cout << "rolling hash = " << hash << endl;
//            hash = hash_str(string(str.begin() + i, str.end()), pattern, prime);
        }

        if (hash == pattern_hash) {
            bool flag = true;
            for (int x = 0; x < pattern.length(); ++x) {
                if (str[i + x] != pattern[x]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                cout << i << endl;
        }

    }


    return 0;
}