#include<bits/stdc++.h>

using namespace std;

void permutation(const string str, string builder, map<int, bool> included_positions) {

    if (builder.length() == str.length()) {
        cout << builder << "\n";
        return;
    }

    // choose
    // explore
    // unchoose

    for (int i = 0; i < str.length(); ++i) {

        // choose
        if (included_positions[i]) continue;
        included_positions[i] = true;
        builder += str[i];

        // explore
        permutation(str, builder, included_positions);

        // unchoose
        included_positions[i] = false;
        builder.pop_back();
    }


}


int main() {

    permutation("NOTE", "", map<int, bool>());

    return 0;
}