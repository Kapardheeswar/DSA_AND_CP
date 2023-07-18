#include<bits/stdc++.h>

using namespace std;

vector<int> smallestRange(vector<vector<int>> nums) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>heap;
    for (int i = 0; i < nums.size(); ++i) {
        heap.push({nums.at(i).at(0),i});
        nums.at(i).erase(nums.at(i).begin());
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>dummyHeap(heap);
    vector<int>vector;
    while (!dummyHeap.empty()){
        vector.push_back(dummyHeap.top().first);
        cout<<dummyHeap.top().first<<",";
        dummyHeap.pop();
    }
    if(vector.at(0)==vector.at(vector.size()-1)){
        vector.erase(vector.begin()+1,vector.end()-1);
        return vector;
    }
    while(nums.at(heap.top().second).size()>0){
        heap.push({nums.at(heap.top().second).at(0),heap.top().second});
        nums[heap.top().second].erase(nums[heap.top().second].begin());
        heap.pop();
    }
    vector.clear();
    while (!heap.empty()){
        vector.push_back(heap.top().first);
        cout<<heap.top().first<<",";
        heap.pop();
    }
    vector.erase(vector.begin()+1,vector.end()-1);
    return vector;
}

int main() {
    vector<vector<int>> nums = {{4, 10, 15, 24, 26},
                                {0, 9,  12, 20},
                                {5, 18, 22, 30}};
    vector<int>v=smallestRange(nums);
    cout<<endl;
    for(int i:v){
        cout<<i<<",";
    }
    cout<<endl;
    cout<<"RANGE: "<<v.at(v.size()-1)-v.at(0);
}