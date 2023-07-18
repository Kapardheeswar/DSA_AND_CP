//
// Created by kapar on 03-07-2023.
//
#include <bits/stdc++.h>

using namespace std;

int sparseSearch(vector<string> arr, string k) {
    int s = 0;
    int e = arr.size() - 1;
    while (s <= e) {
        int mid = (s + e) / 2;
        int midLeft = mid - 1;
        int midRight = mid + 1;
        if (arr[mid] == "") {
            while (1) {
                if (midLeft < s and midRight > e) {
                    return -1;
                } else if (arr[midLeft] != "" and midLeft >= s) {
                    mid = midLeft;
                    break;
                } else if (arr[midRight] != "" and midRight <= e) {
                    mid = midRight;
                    break;
                }
                midLeft--;
                midRight++;
            }
        }
        if (arr[mid] == k) {
            return mid;
        } else if (arr[mid] > k) {
            e = mid - 1;
        } else if (arr[mid] < k) {
            s = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<string> arr = {"ai", "", "", "", "bai", "", "", "ch"};
    cout << sparseSearch(arr, "bai");
}