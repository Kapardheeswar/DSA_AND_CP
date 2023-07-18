#include<bits/stdc++.h>

using namespace std;
int countOneBits(int n){
    int count=0;
    while(n>0){
        int lastBit=n&1;
        count+=lastBit;
        n=n>>1;
    }
    return count;
}
vector<int> sortByBits(vector<int> arr) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;
    vector<int>answer;
    for (int i = 0; i < arr.size(); ++i) {
        minHeap.push({countOneBits(arr.at(i)),arr.at(i)});
    }
    while (!minHeap.empty()){
        int k=minHeap.top().second;
        answer.push_back(k);
        minHeap.pop();
    }
    return answer;
}

int main() {
    vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> ans= sortByBits(vec);
    for (int e:ans) {
        cout<<e<<",";
    }
}