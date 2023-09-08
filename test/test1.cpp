//
// Created by kapar on 08-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

int findLastIndex(vector<int> nums, int num) {
    int currIdx = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == num) {
            currIdx = i;
        }
    }
    if (currIdx == -1) {
        return -1;
    } else return currIdx;
}

int getMaxIdxInBinarySearch(vector<int> nums, int num) {
    int low = 0;
    int high = nums.size() - 1;
    int ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == num) {
            ans = mid;
            low = mid + 1;
//            high = mid -1;
        } else if (nums[mid] < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 8, 8, 8, 9, 9, 10};
    int num;
    cin >> num;
    cout << findLastIndex(nums, num) << endl;
    cout << getMaxIdxInBinarySearch(nums, num) << endl;
}