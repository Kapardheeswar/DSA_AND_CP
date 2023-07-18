//
// Created by kapar on 04-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> v, int k, int s, int e, int &ans) {
    int mid = (s + e) / 2;
    if (s <= e) {
        if (v[mid] == k) {
            ans = mid;
            lowerBound(v, k, s, mid - 1, ans);
        } else if (v[mid] > k) {
            lowerBound(v, k, s, mid - 1, ans);
        } else {
            lowerBound(v, k, mid + 1, e, ans);
        }
    }
    return ans;
}

int getLowerBound(vector<int> v, int k) {
    int s = 0;
    int e = v.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (v[mid] == k) {
            ans = mid;
            e = mid - 1;
        } else if (v[mid] < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int getUpperBound(vector<int> v, int k) {
    int s = 0;
    int e = v.size() - 1;
    int ans = -1;
    while (s <= e) {
        int mid = (s + e) / 2;
        if (v[mid] == k) {
            ans = mid;
            s = mid + 1;
        } else if (v[mid] < k) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v = {0, 1, 1, 2, 2, 2, 3, 3};
    int ans = -1;
    cout << getUpperBound(v, 2) - getLowerBound(v, 2) + 1 << endl;
    cout << upper_bound(v.begin(), v.end(), 2) - lower_bound(v.begin(), v.end(), 2) << endl;
}