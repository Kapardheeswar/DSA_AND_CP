#include <vector>
#include <bits/stdc++.h>
using namespace std;
int findMaxLength(const std::vector<int>& skills, int k) {
    int n = skills.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; ++i) {
        int maxLen = 1;  // Maximum length of subsequence found so far within the window
        for (int j = i - 1; j >= std::max(i - k, 0); --j) {
            if (skills[i] != skills[j]) {
                maxLen = std::max(maxLen, dp[j] + 1);
            }
        }
        dp[i] = maxLen;
    }

    return *std::max_element(dp.begin(), dp.end());
}
int main(){
    cout<< findMaxLength({1,1,2,3},1);
}