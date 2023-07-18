//
// Created by kapar on 02-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int start, int end) {
    int mid = (start + end) / 2;
    int s = start;
    int m = mid;
    int j = m + 1;
    int e = end;
    int count = 0;
    vector<int> temp;
    while (s <= m and j <= e) {
        if (arr[s] < arr[j]) {
            temp.push_back(arr[s]);
            s++;
        } else {
            count += m - s + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (s <= m) {
        temp.push_back(arr[s]);
        s++;
    }
    while (j <= e) {
        temp.push_back(arr[j]);
        j++;
    }
    int k = 0;
    for (int i = start; i <= end; i++) {
        arr[i] = temp[k++];
    }
    return count;
}

int invCount(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return 0;
    }
    int mid = (start + end) / 2;
    int c1 = invCount(arr, start, mid);
    int c2 = invCount(arr, mid + 1, end);
    int c3 = merge(arr, start, end);
    return c1 + c2 + c3;
}

int main() {
    vector<int> arr = {0, 5, 2, 3, 1};
    cout<<invCount(arr, 0, arr.size() - 1);

}