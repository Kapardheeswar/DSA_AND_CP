//
// Created by kapar on 11-08-2023.
//
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int n, int m, vector<int> &path, vector<vector<int>> &paths) {
    path.push_back(grid[i][j]);

    if (i == n - 1 && j == m - 1) {
        paths.push_back(path);
    }

    if (j + 1 < m) {
        dfs(grid, i, j + 1, n, m, path, paths);
    }

    if (i + 1 < n) {
        dfs(grid, i + 1, j, n, m, path, paths);
    }

    path.pop_back();
}
vector<int>addPath(vector<int>path,int k){
    path.push_back(k);
    return path;
}
void dfsVER2(vector<vector<int>>graph,int i,int j,vector<vector<int>>&paths,vector<int>path){
    if(i==graph.size()-1 and j==graph[0].size()-1){
        paths.push_back(path);
        return;
    }
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    for(int k=0;k<4;k++){
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0 and ny>=0 and nx<graph.size() and ny<graph[0].size()){
            dfsVER2(graph,nx,ny,paths, addPath(path,graph[nx][ny]));
        }
    }
}
int findMaxDifference(vector<int> &path) {
    int maxDiff = INT_MIN;
    int size = path.size();

    for (int i = 1; i < size; i++) {
        int diff = abs(path[i] - path[i - 1]);
        maxDiff = max(maxDiff, diff);
    }

    return maxDiff;
}

int findAllPaths(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> paths;
    vector<int> path;
    path.push_back(grid[0][0]);
//    dfs(grid, 0, 0, n, m, path, paths);
    dfsVER2(grid,0,0,paths,path);
    int minimumHealth = INT_MAX;
    for (auto path: paths) {
        int x = findMaxDifference(path);
        if (x < minimumHealth) minimumHealth = x;
    }

    return minimumHealth;
}

int main() {
    vector<vector<int>> graph = {
            {1, 2, 3},
            {2, 5, 6},
            {3, 4, 5}
    };

    cout << findAllPaths(graph);
    return 0;
}