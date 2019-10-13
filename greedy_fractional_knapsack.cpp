#include<bits/stdc++.h>

using namespace std;

struct ITEM {
    int weight;
    int profit;
    double ratio; // value per weight ratio
};

bool sort_by_ratio(const ITEM &A, const ITEM &B) {
    return A.ratio > B.ratio;
}

int main() {

    int capacity = 50;
    vector<int> profit = {60, 100, 120};
    vector<int> weight = {10, 20, 30};

    vector<ITEM> ar(profit.size());

    for (int i = 0; i < profit.size(); ++i) {
        ar[i].profit = profit[i];
        ar[i].weight = weight[i];
        ar[i].ratio = (double) profit[i] / weight[i];
    }

    sort(ar.begin(), ar.end(), sort_by_ratio);

    double total_profit = 0;
    int filled_weight = 0;

    for (int i = 0; i < ar.size(); ++i) {
        if (filled_weight >= capacity) break;

        if (ar[i].weight + filled_weight <= capacity) {
            // take full item
            filled_weight += ar[i].weight;
            total_profit += ar[i].profit;
        } else {
            // take only fraction of it
            int remaining_weight_allowed = capacity - filled_weight;
            filled_weight = capacity;
            total_profit += remaining_weight_allowed * ar[i].ratio;
        }

    }

    cout << total_profit;


    return 0;
}