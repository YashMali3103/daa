#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;
    int index;
    double ratio;

    Item(int w, int v, int i) : weight(w), value(v), index(i), ratio((double)v / w) {}
};

struct Node {
    int level;
    int value;
    int weight;
    double bound;

    Node(int lvl, int val, int w, double b) : level(lvl), value(val), weight(w), bound(b) {}

    bool operator<(const Node &other) const {
        return bound < other.bound;
    }
};

double calculateBound(const Node &node, const vector<Item> &items, int capacity) {
    if (node.weight >= capacity) return 0;

    double profit_bound = node.value;
    int j = node.level + 1;
    int tot_weight = node.weight;

    while (j < items.size() && tot_weight + items[j].weight <= capacity) {
        tot_weight += items[j].weight;
        profit_bound += items[j].value;
        ++j;
    }

    if (j < items.size()) {
        profit_bound += (capacity - tot_weight) * items[j].ratio;
    }

    return profit_bound;
}

int knapsackBranchAndBound(const vector<int> &weights, const vector<int> &values, int capacity) {
    int n = weights.size();
    vector<Item> items;

    for (int i = 0; i < n; ++i) {
        items.emplace_back(weights[i], values[i], i);
    }

    sort(items.begin(), items.end(), [](const Item &a, const Item &b) {
        return a.ratio > b.ratio;
    });

    priority_queue<Node> pq;
    Node root(-1, 0, 0, 0);
    root.bound = calculateBound(root, items, capacity);
    pq.push(root);

    int max_profit = 0;

    while (!pq.empty()) {
        Node v = pq.top();
        pq.pop();

        if (v.bound > max_profit && v.level < n - 1) {
            Node u(v.level + 1, v.value + items[v.level + 1].value, v.weight + items[v.level + 1].weight, 0);

            if (u.weight <= capacity && u.value > max_profit) {
                max_profit = u.value;
            }

            u.bound = calculateBound(u, items, capacity);
            if (u.bound > max_profit) {
                pq.push(u);
            }

            u = Node(v.level + 1, v.value, v.weight, 0);
            u.bound = calculateBound(u, items, capacity);
            if (u.bound > max_profit) {
                pq.push(u);
            }
        }
    }

    return max_profit;
}

int main() {
    vector<int> weights = {1, 2, 3, 5};
    vector<int> values = {1, 6, 10, 16};
    int capacity = 7;

    cout << "Maximum value using Branch and Bound: " 
         << knapsackBranchAndBound(weights, values, capacity) << endl;

    return 0;
}
