//
// Created by kapar on 12-06-2023.
//
#include <bits/stdc++.h>

using namespace std;
int k;
int sz;
vector<int> indices;

void divSubs() {
    cin >> k;
    int sum = 0;
    vector<int> v(k);
    vector<int> mods(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        sum += v[i];
        mods[i] = sum % k;
    }
    auto it = find(mods.begin(), mods.end(), 0);
    if (it != mods.end()) {
        int index = it - mods.begin();
        sz = index + 1;
        for (int i = 0; i < sz; i++) {
            indices.push_back(i+1);
        }
        return;
    } else {
        for (int i = 0; i < mods.size(); i++) {
            for (int j = i+1; j < mods.size(); j++) {
                if(mods[i]==mods[j]){
                    sz = j - i ;
                    for (int l = i+1; l < sz+1; l++) {
                        indices.push_back(l+1);
                    }
                    return;
                }
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t!=0){
        divSubs();
        cout<<sz<<endl;
        for (int ele:indices) {
            cout<<ele<<" ";
        }
        cout<<endl;
        indices.clear();
        t--;
    }
}