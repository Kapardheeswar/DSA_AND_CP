//
// Created by kapar on 02-08-2023.
//
#include <bits/stdc++.h>

using namespace std;
int solution(vector<int> start, vector<int> duration, vector<int> volume, int currTime, int index) {

    int ans = INT_MIN;
    for (int i = index; i < start.size(); i++) {
        if (currTime < start[i]) {
            int subProblem = solution(start, duration, volume, duration[i] + start[i], i + 1);
            ans = max(ans, subProblem + volume[i]);
        }
        int subProblem1 = solution(start, duration, volume, currTime, index + 1);
        ans = max(ans, subProblem1);
    }
    if (ans == INT_MIN) return 0;
    return ans;
}

int main() {
    cout << solution({10,5,15,18,30}, {30,12,20,35,35}, {50,51,20,25,10}, 0, 0);
}

/*
 * start = [10, 5, 15, 18, 30]
duration = [30, 12, 20, 35, 35]
volume = [50, 51, 20, 25, 10]
 */