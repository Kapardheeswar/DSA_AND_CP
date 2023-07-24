#include <bits/stdc++.h>

using namespace std;

int minOperations(vector<int> v) {
    bool check = true;
    for (auto i: v) if (i != 1) check = false;
    if (check) return 0;
    int ans = INT_MAX;
    vector<int> temp;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] > 1) {
            int remaining = v[i] - 1;
            for (int j = 0; j <= remaining; j++) {
                temp = v;
                v[i] = 1;
                if (i - 1 >= 0)
                    v[i - 1] += j;
                if (i + 1 < v.size())
                    v[i + 1] += remaining - j;
                int option3 = 1 + minOperations(v);
                ans = min(ans, option3);
                v = temp;
            }
        }
    }
    return ans;
}

int main() {
    cout << minOperations({3,0,0});
}