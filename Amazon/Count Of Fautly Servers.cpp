//
// Created by kapar on 01-10-2023.
//
#include <bits/stdc++.h>

using namespace std;

int getFaultyServers(int n, vector<string> logs) {
    map<string, int> count;
    int ans = 0;
    for (int i = 0; i < logs.size(); i++) {
        if (logs[i].find("error") != string::npos) {
            string str = "";
            str = logs[i][0] + logs[i][1];
            count[str]++;
            if (count[str] >= 3) {
                cout << str << endl;
                ans++;
                count[str] = 0;
            }
        }
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
//    vector<string> logs(m);
//    for (int i = 0; i < m; i++) {
//        cin >> logs[i];
//    }
    vector<string> logs = {"s1 error", "s3 error", "s2 error", "s2 error"};
    cout << getFaultyServers(n, logs);
}
