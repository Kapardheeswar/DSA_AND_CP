//
// Created by kapar on 02-07-2023.
//
#include<bits/stdc++.h>

using namespace std;

void merge(vector<int> &arr, int start, int end) {
    int mid = (start + end) / 2;
    int s = start;
    int m = mid;
    int j = m + 1;
    int e = end;
    vector<int> temp;
    while (s <= m and j <= e) {
        if (arr[s] < arr[j]) {
            temp.push_back(arr[s]);
            s++;
        } else {
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
    return;
}

void mergesort(vector<int> &arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);
    merge(arr, start, end);
}

int main() {
    vector<int> arr = {2, 1, 5, 3, 8, 4, 12, 9, 6};
    mergesort(arr, 0, arr.size() - 1);
    for (int i: arr) {
        cout << i << ",";
    }
}