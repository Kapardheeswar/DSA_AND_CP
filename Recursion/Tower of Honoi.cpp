//
// Created by kapar on 21-07-2023.
//
#include <bits/stdc++.h>
using namespace std;
void towerOfHonoi(int n,char from,char helper,char to){
    if(n==0)return;
    towerOfHonoi(n-1,from,to,helper);
    cout<<from<<" --> "<<to<<endl;
    towerOfHonoi(n-1,helper,from,to);
}
int main(){
    towerOfHonoi(3,'A','B','C');
}