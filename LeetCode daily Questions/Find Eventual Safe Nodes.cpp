//
// Created by kapar on 12-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
bool checkRepetition(vector<int>visited,int key){
    int cnt = 0;
    for(auto i:visited){
        if(i==key) cnt++;
    }
    if(cnt>1) return false;
    return true;
}
bool findThem(vector<vector<int>>& graph,int u,int parent,vector<int>visited){
    for (int i = 0; i < graph[u].size(); i++) {
        if(graph[u][i]==parent) return false;
        visited.push_back(graph[u][i]);
        bool isNonRepeated = checkRepetition(visited,graph[u][i]);
        if(!isNonRepeated) return false;
        bool c = findThem(graph,graph[u][i],u,visited);
        if(!c) return false;
        visited.pop_back();
    }
    return true;
}
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
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    vector<int>v;
//    vector<bool>visited(graph.size(),false);
    for (int i = 0; i < graph.size(); i++) {
//        bool c = canIFinishACourse(graph,i,visited);
        bool c = findThem(graph,i,-1,{i});
        if(c)v.push_back(i);
    }
    return v;
}

int main(){
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<vector<int>> graph1 = {{1,3,4,5},{},{},{},{},{2,4}};
    vector<int>safeNodes;
    safeNodes = eventualSafeNodes(graph);
    for(int i:safeNodes) cout<<i<<" ";
}