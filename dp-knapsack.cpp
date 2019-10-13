#include <bits/stdc++.h>

using namespace std;

int main() {

    vector<int> weight = {0, 5, 3, 4, 2};
    vector<int> value = {0, 60, 50, 70, 30};
    int capacity = 5;

//    vector<vector<int> > V(weights.size(), vector<int>(capacity + 1));
    int V[weight.size()][capacity + 1];
    for (int i = 0; i <= capacity; ++i)
        V[0][i] = 0;


    for (int item = 1; item <= weight.size(); ++item) { // for each item i
        for (int current_capacity = 0; current_capacity <= capacity; ++current_capacity) {

            if (weight[item] <= current_capacity) {
                V[item][current_capacity] = max(
                        V[item - 1][current_capacity],
                        V[item - 1][current_capacity - weight[item]] + value[item]
                );
            } else {
                V[item][current_capacity] = V[item - 1][current_capacity];
            }
        }
    }

    for (int i = 0; i < weight.size(); ++i) {
        for (int j = 0; j <= capacity; ++j)
            cout << V[i][j] << "\t";
        cout << "\n";
    }

    cout << "\nKnapsack: ";

    int knapsack[weight.size()] = {0};
    int w = capacity;
    for (int item = weight.size() - 1; item > 0; --item) {
        if (V[item][w] != V[item - 1][w]) {
            knapsack[item] = 1;
            w = w - weight[item];
        } else {
            knapsack[item] = 0;
        }
    }

    for (auto i: knapsack)
        cout << i << ", ";


    return 0;
}