#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    if((n&n-1)==0){
        cout<<"Power of 2\n";
    }else{
        cout<<"Not Power of 2\n";
    }
}