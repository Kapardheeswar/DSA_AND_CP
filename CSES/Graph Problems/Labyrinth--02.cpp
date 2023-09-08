//
// Created by kapar on 19-08-2023.
//
#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<char>> grid;
char letter[1001][1001];
int dist[1001][1001], visited[1001][1001];
char ans[1000001];

void isThereAPath(int sx, int sy, int ex, int ey) {
    visited[sx][sy] = 1;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (nx >= 0 and ny >= 0 and nx < n and ny < m and grid[nx][ny] != '#' and !visited[nx][ny]) {
                letter[nx][ny] = (i == 0 ? 'R' : (i == 1 ? 'L' : (i == 2 ? 'D' : 'U')));
                dist[nx][ny] = dist[cx][cy] + 1;
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    if (!visited[ex][ey]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[ex][ey] << endl;
        int x = ex, y = ey;
        for (int i = dist[ex][ey] - 1; i >= 0; i--) {
            ans[i] = letter[x][y];
            if (ans[i] == 'R') { x = x, y = y - 1; }
            else if (ans[i] == 'L') { x = x, y = y + 1; }
            else if (ans[i] == 'U') { x = x + 1, y = y; }
            else if (ans[i] == 'D') { x = x - 1, y = y; }
        }
        for (int i = 0; i < dist[ex][ey]; i++) {
            cout << ans[i];
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    isThereAPath(sx, sy, ex, ey);
    return 0;
}
