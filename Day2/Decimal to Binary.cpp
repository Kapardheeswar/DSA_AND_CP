#include <bits/stdc++.h>

using namespace std;
int decimalToBinary(int n){
    int p=1;
    int ans=0;
    while(n>0){
        int lastBit=n&1;
        ans+=lastBit*p;
        n=n>>1;
        p=p*10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<decimalToBinary(n)<<endl;
}
