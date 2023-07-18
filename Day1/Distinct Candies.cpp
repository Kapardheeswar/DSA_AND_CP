#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
    set<int>s(candies.begin(),candies.end());
    int n=candies.size();
    if(s.size()>n/2){
        return n/2;
    }else{
        return s.size();
    }
}
int main(){
    vector<int>v={1,1,2,2,3,3};
    distributeCandies(v);
}