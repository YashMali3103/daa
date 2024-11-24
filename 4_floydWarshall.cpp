#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void floyds_algorithm(vector<vector<int>>& a) {
    int n = a.size();

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][k] != INT_MAX && a[k][j] != INT_MAX) {
                    a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                }
            }
        }
    }

    cout << "Shortest path matrix:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] == INT_MAX) {
                cout << "INF" << "\t";
            } else {
                cout << a[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> a = {
        {0, 3, INT_MAX, 7},
        {8, 0, 2, INT_MAX},
        {5, INT_MAX, 0, 1},
        {2, INT_MAX, INT_MAX, 0}
    };

    floyds_algorithm(a);

    return 0;
}
