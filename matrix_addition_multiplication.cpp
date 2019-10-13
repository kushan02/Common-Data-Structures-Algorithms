#include<bits/stdc++.h>

using namespace std;

void print_matrix(vector<vector<int> > ar) {
    cout << "\n";
    for (int i = 0; i < ar.size(); ++i) {
        for (int j = 0; j < ar[i].size(); ++j) {
            cout << ar[i][j] << "  ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void matrix_addition() {
    cout << "Matrix Addition:\n";
    int m, n;
    cin >> m >> n;

    // int A[m][n], B[m][n], Sum[m][n];
    vector<vector<int> > A(m, vector<int>(n)), B(m, vector<int>(n)), Sum(m, vector<int>(n));

    // Take Matrix Input
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> B[i][j];
        }
    }

    // Sum of matrix logic
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            Sum[i][j] = A[i][j] + B[i][j];
        }
    }

    print_matrix(Sum);
}

void matrix_multiplication() {

    cout << "Matrix Multiplication:\n";

    int a, n, b;
    cin >> a >> n >> b; // (a x n) * (n x b) = (a x b)

    vector<vector<int> > A(a, vector<int>(n)), B(n, vector<int>(b)), Product(a, vector<int>(b));

    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < b; ++j) {
            for (int k = 0; k < n; ++k) {
                Product[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }

    print_matrix(Product);

}


int main() {

    matrix_addition();

    return 0;
}