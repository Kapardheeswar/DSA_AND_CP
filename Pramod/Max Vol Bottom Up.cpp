//
// Created by kapar on 02-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int dp[1005][1005]; // Using a 2D memoization table

int solutionMemoization(vector<int>& start, vector<int>& duration, vector<int>& volume, int currTime, int index) {
    if (index == start.size())
        return 0;

    if (dp[index][currTime] != -1)
        return dp[index][currTime];

    int ans = solutionMemoization(start, duration, volume, currTime, index + 1);

    if (currTime + duration[index] <= start[index]) {
        int subProblem = solutionMemoization(start, duration, volume, currTime + duration[index], index + 1);
        ans = max(ans, subProblem + volume[index]);
    }

    return dp[index][currTime] = ans;
}

int main() {
    memset(dp, -1, sizeof(dp)); // Initialize the memoization table with -1

    vector<int> start = {3, 1, 2, 4};
    vector<int> duration = {3, 2, 2, 1};
    vector<int> volume = {3, 1, 2, 3};
    int currTime = 0;

    cout << solutionMemoization(start, duration, volume, currTime, 0) << endl;
}
