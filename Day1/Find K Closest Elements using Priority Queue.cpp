#include<bits/stdc++.h>

using namespace std;

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    vector<int> newVec;
    for (int ele: arr) {
        int diff = abs(ele - x);
        heap.push({diff, ele});
    }
    while (k > 0) {
        newVec.push_back(heap.top().second);
        heap.pop();
        k--;
    }
    sort(newVec.begin(), newVec.end());
    return newVec;
}

int main() {
    vector<int> vec = {-972, -971, -874, -843, -801, -740, -702, -627, -625, -595, -567, -551, -535, -431, -405, -389,
                       -318, -290, -174, -133, -97, -88};
    vector<int> v = findClosestElements(vec, 12, -125);
    for (int k: v) {
        cout << k << ",";
    }
}