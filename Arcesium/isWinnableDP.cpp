//
// Created by kapar on 20-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

// DP table to store the results of subproblems
vector<vector<int>> dp;

int countSubsets(vector<int> &balls, int sum, int index) {
    // Base case: if sum is 0, there's only one subset (empty subset)
    if (sum == 0) return 1;

    // If we have processed all the balls or the sum becomes negative, no subset possible
    if (index >= balls.size() || sum < 0) return 0;

    // If the result for this state is already calculated, return it
    if (dp[index][sum] != -1) return dp[index][sum];

    // Count subsets including the current ball and excluding the current ball
    int inc = countSubsets(balls, sum - balls[index], index + 1);
    int exc = countSubsets(balls, sum, index + 1);

    // Save the result in DP table and return
    return dp[index][sum] = inc + exc;
}

bool isWinnable(vector<int> balls) {
    int sum = 0;
    for (auto k: balls) sum += k;

    if (sum % 2 != 0) return false;

    // Initialize the DP table with -1
    dp.assign(balls.size(), vector<int>(sum / 2 + 1, -1));
    for(auto v:dp){
        for(auto k:v){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    int count = countSubsets(balls, sum / 2, 0);
    if (count > 0) return true;
    return false;
}

int main() {
    bool isPossible = isWinnable({1,1,2,2});
    if (isPossible) cout << "YES" << endl;
    else cout << "NO" << endl;
}
