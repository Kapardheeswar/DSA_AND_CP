//
// Created by kapar on 25-06-2023.
//
#include <bits/stdc++.h>
using namespace std;
// a*x + b*y = gcd(a,b)
// we calculate x,y and gcd(a,b)
vector<int> extendedGCD(int a,int b){
    if(b==0){
        return {1,0,a};
    }
    vector<int> sol = extendedGCD(b,a%b);
    int smallX = sol[0];
    int smallY = sol[1];
    int gcd = sol[2];
    int x = smallY;
    int y = smallX - floor(a/b)*smallY;
    return {x,y,gcd};
}
int main(){
    vector<int> sol = extendedGCD(18,12);
    cout<<sol[0]<<" "<<sol[1]<<" "<<sol[2]<<endl;
}