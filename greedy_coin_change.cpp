#include<bits/stdc++.h>

using namespace std;

int main() {

    vector<int> coins = {18, 17, 5, 1};
    int amount = 22;

    sort(coins.begin(), coins.end(), greater<>());

    int number_of_coins = 0;

    while (amount > 0) {

        int largest_valid_coin = 0;

        for (int i = 0; i < coins.size(); ++i) {
            if (coins[i] <= amount) {
                largest_valid_coin = coins[i];
                break;
            }
        }

        amount = amount - largest_valid_coin;
        number_of_coins++;
    }

    cout << number_of_coins;

    return 0;
}