//
// Created by kapar on 17-06-2023.
//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1e9+7;
ll findNC2(int n){
    return (n*(n-1))/2;
}
ll power(ll a,ll b){
    ll res=1;
    while (b){
        if(b&1) res *= a;
        res%=mod;
        a*=a;
        a%=mod;
        b>>=1;
    }
    return res;
}
vector<int> cutLastElement(vector<int> v){
    v.pop_back();
    return v;
}
int solve(int n,vector<int>v){
    // sort the vectors
    sort(v.begin(),v.end(),greater<int>());
    // if there are only 2 players
    if(n==2){
        return v[1];
    }
    // if player v[n] comes in second place prob is 1/nc2
    // else 1-(1/nc2)
    return (((power(findNC2(n),mod-2)*v[n-1])%mod)+(((1-power(findNC2(n),mod-2)+mod)%mod)* solve(n-1, cutLastElement(v)))%mod)%mod;
}
int main(){
    ifstream input_file("input.txt"); // Open the input file
    if (!input_file) {
        cerr << "Failed to open input file\n";
        return 1;
    }
    ofstream output_file("output.txt"); // Open the output file
    if (!output_file) {
        cerr << "Failed to open output file\n";
        return 1;
    }
    int T;
    input_file >> T;

    while (T--) {
        int N;
        input_file >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            input_file >> ratings[i];
        }
        output_file<<solve(N,ratings)<<endl;
    }
    input_file.close();
    output_file.close();
}
