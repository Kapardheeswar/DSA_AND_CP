#include<bits/stdc++.h>
using namespace std;
vector<long>shortestTimes(vector<vector<pair<int,int>>>graph,int source,int n,vector<long>t){
    vector<long>dist(n+1,INT_MAX);
    dist[1] = 0;
    set<vector<long>>s;
    s.insert({dist[source],source,0});
    while(!s.empty()){
        auto it = s.begin();
        int distTillNow = it->at(0);
        int u = it->at(1);
        int timeTillNow = it->at(2);
        s.erase(it);
        for(auto p:graph[u]){
            int v = p.first;
            int w = p.second;
            if(timeTillNow+w<t[v] and distTillNow+w<dist[v]){
                auto f = s.find({dist[v],v,timeTillNow+w});
                if(f!=s.end())s.erase(f);
                dist[v] = distTillNow+w;
                s.insert({dist[v],v,timeTillNow+w});
            }
        }
    }
    return dist;
}
vector<long> mazeGame(vector<long> t, vector<int> endpoint1, vector<int> endpoint2, vector<int> edgeLength) {
    vector<vector<pair<int,int>>>graph(t.size()+1);
    for(int i=0;i<endpoint1.size();i++){
        int u = endpoint1[i];
        int v = endpoint2[i];
        int w = edgeLength[i];
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    vector<long>dist = shortestTimes(graph,1,t.size(),t);
    for(int j=0;j<dist.size();j++){
        if(dist[j]==INT_MAX)dist[j] = -1;
    }
    vector<long>d(t.size());
    for(int k=0;k<dist.size();k++){
        d[k] = dist[k+1];
    }
    return d;
}
int main(){
    vector<long>dist = mazeGame({1,2,7,9},{1,2,3,4},{2,4,1,3},{2,1,5,3});
    for(auto k:dist) cout<<k<<" ";
}
