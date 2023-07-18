//
// Created by kapar on 20-04-2023.
//
#include<bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y) {
    int count=0;
    while (x>0||y>0){
        int xLastBit=x&1;
        int yLastBit=y&1;
        if(xLastBit!=yLastBit) count+=1;
        x=x>>1;y=y>>1;
    }
    return count;
}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<endl;
    cout<<hammingDistance(x,y)<<endl;
}
