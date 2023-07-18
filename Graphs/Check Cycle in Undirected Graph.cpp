//
// Created by kapar on 17-07-2023.
//
#include<bits/stdc++.h>
using namespace std;

bool graphContainsCycle(vector<vector<int>> graph,int u,int parent,map<int,bool>visited){
    visited[u] = true;
    for(auto v:graph[u]){
        if(parent!=v){
            if(visited[v]) return true;
            bool check = graphContainsCycle(graph,v,u,visited);
            if(check) return true;
        }
    }
    visited[u] = false;
    return false;
}

bool contains_cycle(int v,vector<pair<int,int>> edges){
    //Complete this method
    vector<vector<int>>graph(v,vector<int>());
    for(auto p:edges){
        int u = p.first;
        int v = p.second;
        cout<<u<<" "<<v<<endl;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graphContainsCycle(graph,0,-1,{});
}
int main(){
    cout<<contains_cycle(4,{{0,1},{1,2},{2,0}});
}