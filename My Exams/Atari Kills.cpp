#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumBeauty(int n, int m, int maxTime, vector<int>& beauty, vector<int>& u, vector<int>& v, vector<int>& t) {
    vector<vector<int>> dp(n + 1, vector<int>(maxTime + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= maxTime; j++) {
            if (t[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], beauty[i - 1] + dp[i - 1][j - t[i - 1]]);
            }
        }
    }

    return dp[n][maxTime];
}

int main() {
    int n = 4; // Number of squares
    int m = 3; // Number of roads
    int maxTime = 50; // Maximum time

    vector<int> beauty = { 5, 10, 15, 20 }; // Beauty values for each square
    vector<int> u = { 0, 1, 0 }; // Starting squares of each road
    vector<int> v = { 1, 2, 3 }; // Ending squares of each road
    vector<int> t = { 10, 10, 10 }; // Time to travel each road

    int maxBeauty = maximumBeauty(n, m, maxTime, beauty, u, v, t);
    cout << "Maximum Beauty Value: " << maxBeauty << endl;

    return 0;
}