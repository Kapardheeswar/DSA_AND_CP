//
// Created by kapar on 13-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

float getMedian(priority_queue<float> &maxHeap, priority_queue<float, vector<float>, greater<float>>& minHeap) {
    if(minHeap.empty()) return maxHeap.top();
    if(maxHeap.empty()) return minHeap.top();
    if (maxHeap.size() == minHeap.size()) return (minHeap.top() + maxHeap.top()) / 2;
    if (maxHeap.size() + 1 == minHeap.size()) return minHeap.top();
    return maxHeap.top();
}

void traverse(vector<float> v) {
    priority_queue<float> maxHeap;
    priority_queue<float, vector<float>, greater<float>> minHeap;
    float median;
    for (int i = 0; i < v.size(); i++) {
        if (minHeap.empty() and maxHeap.empty()) {
            maxHeap.push(v[i]);
            median = getMedian(maxHeap, minHeap);
            cout << median << " ";
        } else if (median > v[i]) {
            maxHeap.push(v[i]);
            if (maxHeap.size() - minHeap.size() > 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            }
            median = getMedian(maxHeap, minHeap);
            cout << median << " ";
        } else if (median < v[i]) {
            minHeap.push(v[i]);
            if (minHeap.size() - maxHeap.size() > 1) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
            median = getMedian(maxHeap, minHeap);
            cout << median << " ";
        }
    }
}
int main(){
    vector<float>v = {10,5,2,3,0,12,18,20,22};
    traverse(v);
}