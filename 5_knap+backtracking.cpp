#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack_helper(const vector<int>& weights, const vector<int>& values, int capacity, int i) {
    if (i == weights.size()) return 0;
    if (weights[i] > capacity) return knapsack_helper(weights, values, capacity, i + 1);
    return max(values[i] + knapsack_helper(weights, values, capacity - weights[i], i + 1), 
               knapsack_helper(weights, values, capacity, i + 1));
}

int knapsack(const vector<int>& weights, const vector<int>& values, int capacity) {
    return knapsack_helper(weights, values, capacity, 0);
}

int main() {
    vector<int> weights = {1, 2, 3, 5};
    vector<int> values = {1, 6, 10, 16};
    int capacity = 7;

    cout << "Maximum value using Backtracking: " << knapsack(weights, values, capacity) << endl;
    return 0;
}
