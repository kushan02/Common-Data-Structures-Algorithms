#include<bits/stdc++.h>

using namespace std;

int main() {

    string str, pattern;
    str = "ababbab";
    pattern = "ab*";

    int M = pattern.length();

    for (int i = 0; i < str.length() - M + 1; ++i) {

        bool flag = true;

        for (int j = 0; j < M; ++j) {
            if (pattern[j] == '*') continue;
            else if (str[i + j] != pattern[j]) {
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "(" << i << "," << i + M - 1 << ")\n";

    }


    return 0;
}