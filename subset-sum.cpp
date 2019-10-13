#include <bits/stdc++.h>

using namespace std;

void generate_subset(const vector<int> ar, const int sum, int current_sum, vector<int> subset, map<int, bool> visited,
                     int last_index) {

    if (current_sum == sum) {

        for (auto i: subset)
            cout << i << " ";
        cout << "\n";
        return;
    } else if (current_sum > sum) return;

    for (int i = last_index + 1; i < ar.size(); ++i) {

        if (visited[i]) continue;

        visited[i] = true;
        subset.push_back(ar[i]);

        generate_subset(ar, sum, current_sum + ar[i], subset, visited, i);

        visited[i] = false;
        subset.pop_back();

    }

}

int main() {

    vector<int> ar = {1, 2, 5, 6, 8};
    int sum = 9;

    generate_subset(ar, sum, 0, vector<int>(), map<int, bool>(), -1);

    return 0;
}