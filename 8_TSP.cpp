#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int tsp(const vector<vector<int>>& graph, vector<bool>& visited, int n, int current_pos, int cost, int count, int ans) {
    if (count == n && graph[current_pos][0] > 0) {
        ans = min(ans, cost + graph[current_pos][0]);
        return ans;
    }

    for (int i = 0; i < n; ++i) {
        if (!visited[i] && graph[current_pos][i] > 0) {
            visited[i] = true;
            ans = tsp(graph, visited, n, i, cost + graph[current_pos][i], count + 1, ans);
            visited[i] = false;
        }
    }

    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    vector<bool> visited(n, false);
    int ans = INT_MAX;

    visited[0] = true;
    ans = tsp(graph, visited, n, 0, 0, 1, ans);

    cout << "Minimum cost of completing the tour: " << ans << endl;

    return 0;
}
