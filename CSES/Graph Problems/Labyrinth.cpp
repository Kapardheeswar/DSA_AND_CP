//
// Created by kapar on 19-08-2023.
//
#include<bits/stdc++.h>
using namespace std;
#define int long long
string isThereAPathDP(vector<vector<char>>&map,int sx,int sy,int ex,int ey,int n,int m){
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    dist[sx][sy]=0;
    vector<vector<string>>path(n,vector<string>(m,""));
    set<vector<int>>s;
    s.insert({dist[sx][sy],sx,sy});
    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};
    while(!s.empty()){
        auto f = s.begin();
        int distTillNow = f->at(0);
        int cx = f->at(1);
        int cy = f->at(2);
        string p = path[cx][cy];
        s.erase(f);
        for(int k=0;k<4;k++){
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            if(nx>=0 and ny>=0 and nx<n and ny<m and map[nx][ny]!='#'){
                if(1+distTillNow<dist[nx][ny]){
                    auto f = s.find({dist[nx][ny],nx,ny});
                    if(f!=s.end()) s.erase({dist[nx][ny],nx,ny});
                    path[nx][ny] = path[cx][cy] + (k == 0 ? 'R' : (k == 1 ? 'L' : (k == 2 ? 'D' : 'U')));
                    dist[nx][ny] = distTillNow+1;
                    s.insert({dist[nx][ny],nx,ny});
                }
            }
        }
    }
    return path[ex][ey];
}
signed main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m, '#'));
    int sx, sy, ex, ey;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            else if (map[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }
    string s = isThereAPathDP(map,sx,sy,ex,ey,n,m);
    if(s.length()>0){
        cout<<"YES"<<endl;
        cout<<s.length()<<endl;
        cout<<s<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}