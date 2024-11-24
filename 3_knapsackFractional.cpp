#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;

    Item(int value, int weight) {
        this->value = value;
        this->weight = weight;
    }
};

bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, struct Item arr[], int N) {
    sort(arr, arr + N, cmp);
    double finalValue = 0.0;

    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        } else {
            finalValue += arr[i].value * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 20;
    Item arr[] = {{10, 3}, {20, 5}, {21, 5}, {30, 8}, {16, 4}};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, N) << endl;
    return 0;
}
