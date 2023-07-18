//
// Created by kapar on 17-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
map<int,int>values;
int getMedian(string s){
    vector<int>v;
    for(char ch:s){
        int x = ch - '0';
        v.push_back(values[x]);
    }
    sort(v.begin(),v.end());
    return v[v.size()/2];
}
void dfs(vector<vector<int>>graph,int u,int pathLength,string s,map<int,bool>visited,int &ans){
    if(pathLength %2==1){
        ans+=getMedian(s);
    }
    visited[u] = true;
    for(int v:graph[u]){
        if(!visited[v]){
            dfs(graph,v,pathLength+1,s+to_string(v),visited,ans);
        }
    }
    visited[u] = false;
    return;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>>graph(n);
    int k;
    for (int i = 0; i < n; i++) {
        cin>>k;
        values[i] = k;
    }
    int u,v;
    cin>>u>>v;
    while(u!=-1 and v!=-1){
        graph[u].push_back(v);
        graph[v].push_back(u);
        cin>>u>>v;
    }
    int ans = 0;
    dfs(graph,0,1,"0",{},ans);
    cout<<ans;
}
/*
 * 5
7 6 9 10 1
0 1
1 2
0 3
1 4
-1 -1
 */