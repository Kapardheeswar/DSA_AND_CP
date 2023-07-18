//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
bool canIFinishACourse(vector<vector<int>>graph,int u,vector<bool>visited){
    visited[u] = true;
    for(int i = 0;i<graph[u].size();i++){
        int v = graph[u][i];
        if(visited[v]) return false;
        bool check = canIFinishACourse(graph,v,visited);
        if(!check) return false;
    }
    visited[u] = false;
    return true;
}
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(numCourses,vector<int>());
    for(int i=0;i<prerequisites.size();i++){
        int course = prerequisites[i][0];
        int prerequisite = prerequisites[i][1];
        graph[course].push_back(prerequisite);
    }
    vector<bool>visited(numCourses,false);
    bool canIFinish = true;
    for(int i = 0;i<graph.size();i++){
        canIFinish = canIFinishACourse(graph,i,visited);
        if(!canIFinish) return false;
    }
    return canIFinish;
}

int main(){
    vector<vector<int>> prerequisites = {{0,10},{3,18}};
    cout<<canFinish(20,prerequisites);
}