//
// Created by kapar on 22-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> getPointsOnCircle(int x, int y, int k) {
    vector<pair<int, int>> points;
    for (int i = x - k; i <= x + k; i++) {
        for (int j = y - k; j <= y + k; j++) {
            if (pow(i - x, 2) + pow(j - y, 2) == pow(k, 2)) {
                points.push_back(make_pair(i, j));
            }
        }
    }
    return points;
}

void checkPath(int m, int n, int i, int j, int xt, int yt, int X, int currSteps, int &minSteps,
               vector<vector<bool>> &visited) {
    if (i == xt and j == yt) {
        if (currSteps < minSteps) minSteps = currSteps;
        return;
    }
    visited[i][j] = true;
    vector<pair<int, int>> pairs = getPointsOnCircle(i, j, X);
    for (int k = 0; k < pairs.size(); k++) {
        int nx = pairs[k].first;
        int ny = pairs[k].second;
        if (nx >= 0 and ny >= 0 and nx < m and ny < n and !visited[nx][ny]) {
            checkPath(m, n, nx, ny, xt, yt, X, currSteps + 1, minSteps, visited);
        }
    }
    visited[i][j] = false;
    return;
}

int main() {
    int minSteps = INT_MAX;
    vector<vector<bool>> v(6, vector<bool>(5, false));
    checkPath(6, 5, 0, 1, 1, 4, 5, 0, minSteps, v);
    cout << minSteps << endl;
}
