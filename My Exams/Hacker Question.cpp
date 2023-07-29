//
// Created by kapar on 26-07-2023.
//
#include<bits/stdc++.h>
using namespace std;

void getMin(int N, vector<vector<int>> &adj){
    vector<vector<string>> path(N+1,vector<string>(N+1,""));
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                    path[i][j] = path[i][k] + to_string(k) + path[k][j];
                } else if(adj[i][j] == adj[i][k] + adj[k][j]){
                    path[i][j] = min(path[i][j],path[i][k] + to_string(k) + path[k][j]);
                }
            }
        }
    }
    vector<int> count(N+1,0);
    for(int i=1; i<=N; i++){
        for(int j=i+1; j<=N; j++){
            for(char c: path[i][j]){
                count[c-48]++;
            }
        }
    }
    vector<int> ans;
    int max_count = *max_element(count.begin(),count.end());
    for(int i=1; i<=N; i++){
        if(count[i] == max_count){
            ans.push_back(i-1);
        }
    }
    for(int x: ans) cout<<x<<endl;
}

int main(){
    int N;
    cin>>N;
    vector<vector<int>> adj(N+1,vector<int>(N+1));
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>adj[i][j];
        }
    }
    getMin(N,adj);
}