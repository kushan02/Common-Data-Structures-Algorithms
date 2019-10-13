#include<bits/stdc++.h>

using namespace std;

bool linear_search_recursive(const vector<int> ar, const int x, int index = 0) {
    if (index >= ar.size()) return false;

    if (ar[index] == x) return true;
    else
        return linear_search_recursive(ar, x, index + 1);

}

bool linear_search(const vector<int> ar, const int x) {
    for (int i = 0; i < ar.size(); ++i) {
        if (ar[i] == x)
            return true;
    }

    return false;
}

bool binary_search(const vector<int> ar, const int x, int low = -1, int high = -1) {
    if (low == -1) {
        low = 0;
        high = ar.size();
    }

    if (low > high) return false;

    int mid = (low + high) / 2;
    if (ar[mid] == x) return true;
    else if (ar[mid] > x) return binary_search(ar, x, low, mid - 1);
    else return binary_search(ar, x, mid + 1, high);
}

int main() {
    vector<int> ar = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Linear Search: " << linear_search_recursive(ar, 6) << " " << linear_search_recursive(ar, 15) << endl;
    cout << "Binary Search: " << binary_search(ar, 6) << " " << binary_search(ar, 15) << endl;
}