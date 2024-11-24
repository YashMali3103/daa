#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_dp(const vector<int>& weights, const vector<int>& values, int capacity) {
    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    vector<int> weights = {1, 2, 3, 5};
    vector<int> values = {1, 6, 10, 16};
    int capacity = 7;

    cout << "Maximum value using Dynamic Programming: " << knapsack_dp(weights, values, capacity) << endl;

    return 0;
}
