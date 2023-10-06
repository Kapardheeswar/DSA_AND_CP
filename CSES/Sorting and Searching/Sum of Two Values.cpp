//
// Created by kapar on 24-09-2023.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> temp = arr;
    sort(arr.begin(), arr.end());
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int currSum = arr[start] + arr[end];
        if (currSum == target) {
            int startIdx = find(temp.begin(), temp.end(), arr[start]) - temp.begin();
            int endIdx = find(temp.begin(), temp.end(), arr[end]) - temp.begin();
            if (startIdx == endIdx) {
                endIdx = find(temp.begin() + endIdx + 1, temp.end(), arr[end]) - temp.begin();
            }
            cout << startIdx + 1 << " " << endIdx + 1 << endl;
            return 0;
        } else if (currSum < target) {
            start++;
        } else if (currSum > target) {
            end--;
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}