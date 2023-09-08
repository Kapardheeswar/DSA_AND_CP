//
// Created by kapar on 18-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int minDays(int n, int m, vector<int> task, int index, map<int, int> days) {
    if (index >= m) return 0;
    int ans = INT_MAX;
    for (int i = index; i < m; i++) {
        int developerNum = task[i];
        for (int j = 0; j < n; j++) {
            if (days[j] > 0)days[j]--;
            if (developerNum != j and days[j] == 0) {
                days[j] = 2;
                int option1 = 2 + minDays(n, m, task, i + 1, days);
                ans = min(ans, option1);
            } else {
                int option2 = 1 + minDays(n, m, task, i + 1, days);
                ans = min(ans, option2);
            }
        }
    }
    return ans;
}

int main() {
    cout << minDays(2, 4, {1, 2, 1, 1}, 0, {});
}