//
// Created by kapar on 29-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
void getCount(vector<vector<int>>graph,int& count,int u,map<int,bool>visited,int target){
    if(u==target){
        count++;
        return;
    }
    visited[u] = true;
    for(auto k:graph[u]){
        if(!visited[k]){
            getCount(graph,count,k,visited,target);
        }
    }
    visited[u] = false;
}
int gameRoutes(int n, vector<vector<int>> edges)
{
    vector<vector<int>>graph(n+1,vector<int>());
    for(auto vec:edges){
        int u = vec[0];
        int v = vec[1];
        graph[u].push_back(v);
    }
    int count = 0;
    getCount(graph,count,1,{},n);
    return count;
}
int main(){
    cout<<gameRoutes(5,{{1,  2}, {1, 3}, {2, 3}, {1,  4}, {4, 5}});
}