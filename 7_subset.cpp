#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void helper(const vector<int> &nums, int target, int index, int current_sum, vector<int> &current_subset) {
    if (current_sum == target) {
        for (int num : current_subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    int prev_element = -1;

    for (int i = index; i < nums.size(); i++) {
        if (nums[i] != prev_element) {
            if (nums[i] + current_sum > target) {
                break;
            }

            current_subset.push_back(nums[i]);

            prev_element = nums[i];

            helper(nums, target, i + 1, current_sum + nums[i], current_subset);

            current_subset.pop_back();
        }
    }
}

void findSubset(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());

    vector<int> current_subset;

    helper(nums, target, 0, 0, current_subset);
}

int main() {
    vector<int> nums = {1, 2, 5, 6, 8};
    int target = 9;

    findSubset(nums, target);

    return 0;
}
