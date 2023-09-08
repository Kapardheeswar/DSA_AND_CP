
#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


int solution(vector<vector<int>> grid) {
    vector<vector<int>> dist(3, vector<int>(3, 1e9));
    queue<pair<int, int>> Q;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] -= 1;
            if (grid[i][j] == -1)dist[i][j] = 1e9;
            else dist[i][j] = 0;
            if (grid[i][j] > 0) {
                Q.push({i, j});
            }
        }
    }
    while (!Q.empty()) {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i], ny = cur.second + dy[i];
            if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3)continue;
            if (grid[nx][ny] != -1)continue;
            if (dist[nx][ny] > dist[cur.first][cur.second] + 1) {
                dist[nx][ny] = dist[cur.first][cur.second] + 1;
                Q.push({nx, ny});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ans += dist[i][j];
        }
    }
    return ans;
}