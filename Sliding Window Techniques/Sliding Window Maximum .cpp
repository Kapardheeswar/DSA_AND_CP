//
// Created by kapar on 02-07-2023.
//
#include<bits/stdc++.h>
using namespace std;
vector<int> maxInWindow(vector<int> input, int k) {
    int i = 0;
    int j = k - 1;
    vector<int>max;
    while(j<input.size()){
        max.push_back(*max_element(input.begin()+i,input.begin()+j+1));
        i++;
        j++;
    }
    return max;
}
int main(){
    vector<int>sums = maxInWindow({1, 2, 3, 1, 4, 5, 2, 3, 6},3);
    for(int i:sums){
        cout<<i<<" "<<endl;
    }
}
